#include <system/System.h>
#include <graphics/ImageBuffer.h>
#include <graphics/PixelFormat.h>
#include <graphics/format/JPEG.h>
#include <utils/File.h>

#include <SDL.h>
#include <SDL_image.h>
#include <climits>
#include <cstdlib>
#include <cstring>


namespace lime {


	// JPEG decoding/encoding is handled by SDL2_image's stb_image (decode) and
	// bundled tiny_jpeg (encode) backends, so no libjpeg dependency is required.


	static bool JPEGSurfaceToImageBuffer (SDL_Surface* surface, ImageBuffer* imageBuffer, bool decodeData) {

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


	bool JPEG::Decode (Resource *resource, ImageBuffer *imageBuffer, bool decodeData) {

		File file = resource->path ? File (resource->path, "rb") : File (resource->data);

		if (!file.handle) {

			return false;

		}

		SDL_RWops* rw = (SDL_RWops*)file.handle;

		if (!IMG_isJPG (rw)) {

			file.Close ();
			return false;

		}

		SDL_Surface* surface = IMG_LoadJPG_RW (rw);

		file.Close ();

		return JPEGSurfaceToImageBuffer (surface, imageBuffer, decodeData);

	}


	bool JPEG::Encode (ImageBuffer *imageBuffer, Bytes* bytes, int quality) {

		if (!bytes) {

			return false;

		}

		SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormatFrom (imageBuffer->data->buffer->b, imageBuffer->width, imageBuffer->height, 32, imageBuffer->Stride (), SDL_PIXELFORMAT_RGBA32);

		if (!surface) {

			return false;

		}

		// tiny_jpeg wants RGB(A) input; convert to a packed 24-bit surface first.
		SDL_Surface* rgb = SDL_ConvertSurfaceFormat (surface, SDL_PIXELFORMAT_RGB24, 0);
		SDL_FreeSurface (surface);

		if (!rgb) {

			return false;

		}

		// SDL2 has no growable memory stream; a JPEG is always smaller than the raw
		// RGBA source, so a raw-sized buffer plus slack is a safe upper bound.
		size_t cap = (size_t)imageBuffer->width * (size_t)imageBuffer->height * 4 + (1 << 20);
		bool success = false;

		if (cap <= (size_t)INT_MAX) {

			unsigned char* buffer = (unsigned char*)malloc (cap);

			if (buffer) {

				SDL_RWops* dst = SDL_RWFromMem (buffer, (int)cap);

				if (dst) {

					if (IMG_SaveJPG_RW (rgb, dst, 0, quality) == 0) {

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

		SDL_FreeSurface (rgb);

		return success;

	}


}
