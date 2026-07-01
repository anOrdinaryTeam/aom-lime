#include <system/System.h>
#include <graphics/ImageBuffer.h>
#include <graphics/PixelFormat.h>
#include <graphics/format/PNG.h>
#include <utils/File.h>

#include <SDL.h>
#include <SDL_image.h>
#include <climits>
#include <cstdlib>
#include <cstring>


namespace lime {


	// PNG decoding/encoding is handled by SDL2_image's stb_image (decode) and
	// bundled miniz (encode) backends, so no libpng dependency is required.


	static bool SurfaceToImageBuffer (SDL_Surface* surface, ImageBuffer* imageBuffer, bool decodeData) {

		if (!surface) {

			return false;

		}

		imageBuffer->width = surface->w;
		imageBuffer->height = surface->h;

		if (!decodeData) {

			SDL_FreeSurface (surface);
			return true;

		}

		if (surface->format->format != SDL_PIXELFORMAT_RGBA32) {

			SDL_Surface* converted = SDL_ConvertSurfaceFormat (surface, SDL_PIXELFORMAT_RGBA32, 0);
			SDL_FreeSurface (surface);
			surface = converted;

			if (!surface) {

				return false;

			}

		}

		imageBuffer->Resize (surface->w, surface->h, 32);
		memcpy (imageBuffer->data->buffer->b, surface->pixels, surface->h * surface->pitch);

		SDL_FreeSurface (surface);

		return true;

	}


	bool PNG::Decode (Resource *resource, ImageBuffer *imageBuffer, bool decodeData) {

		File file = resource->path ? File (resource->path, "rb") : File (resource->data);

		if (!file.handle) {

			return false;

		}

		SDL_RWops* rw = (SDL_RWops*)file.handle;

		if (!IMG_isPNG (rw)) {

			file.Close ();
			return false;

		}

		SDL_Surface* surface = IMG_LoadPNG_RW (rw);

		file.Close ();

		return SurfaceToImageBuffer (surface, imageBuffer, decodeData);

	}


	bool PNG::Encode (ImageBuffer *imageBuffer, Bytes* bytes) {

		if (!bytes) {

			return false;

		}

		SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom (imageBuffer->data->buffer->b, imageBuffer->width, imageBuffer->height, 32, imageBuffer->Stride (), SDL_PIXELFORMAT_RGBA32);

		if (!surface) {

			return false;

		}

		// SDL2 has no growable memory stream, so encode into a fixed buffer sized well
		// above the worst case (raw RGBA is an upper bound for PNG plus format overhead).
		size_t cap = (size_t)imageBuffer->width * (size_t)imageBuffer->height * 4 + (1 << 20);
		bool success = false;

		if (cap <= (size_t)INT_MAX) {

			unsigned char* buffer = (unsigned char*)malloc (cap);

			if (buffer) {

				SDL_RWops* dst = SDL_RWFromMem (buffer, (int)cap);

				if (dst) {

					if (IMG_SavePNG_RW (surface, dst, 0) == 0) {

						Sint64 size = SDL_RWtell (dst);

						if (size > 0 && size <= INT_MAX) {

							bytes->Resize ((int)size);
							memcpy (bytes->b, buffer, (size_t)size);
							success = true;

						}

					}

					SDL_RWclose (dst);

				}

				free (buffer);

			}

		}

		SDL_FreeSurface (surface);

		return success;

	}


}
