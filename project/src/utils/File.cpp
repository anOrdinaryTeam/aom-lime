#include <utils/File.h>

#include <cstdio>

#include <SDL.h>


namespace lime {


	File::File (const char* path, const char* mode) {

		handle = (void *)SDL_RWFromFile (path, mode);

		if (!handle) {

			char *base = SDL_GetBasePath ();

			if (base) {

				size_t length = SDL_strlen (base) + SDL_strlen (path) + 1;
				char *fullpath = (char *)SDL_malloc (length);

				if (fullpath) {

					SDL_snprintf (fullpath, length, "%s%s", base, path);
					handle = (void *)SDL_RWFromFile (fullpath, mode);
					SDL_free (fullpath);

				}

				SDL_free (base);

			}

		}

	}


	File::File (Bytes* data) {

		handle = (void *)SDL_RWFromConstMem (data->b, data->length);

	}


	bool File::Close () {

		if (handle) {

			SDL_RWclose ((SDL_RWops *)handle);
			handle = NULL;
			return true;

		}

		return false;

	}


	bool File::Flush () {

		// SDL2's SDL_RWops has no explicit flush; treat an open handle as flushed.
		return handle ? true : false;

	}


	size_t File::Read (void *ptr, size_t size) {

		return handle ? SDL_RWread ((SDL_RWops *)handle, ptr, 1, size) : -1;

	}


	int64_t File::Seek (int64_t offset, int whence) {

		if (!handle) {

			return -1;

		}

		int sdlWhence = RW_SEEK_SET;

		switch (whence) {

			case SEEK_SET:
				sdlWhence = RW_SEEK_SET;
				break;
			case SEEK_CUR:
				sdlWhence = RW_SEEK_CUR;
				break;
			case SEEK_END:
				sdlWhence = RW_SEEK_END;
				break;

		}

		return SDL_RWseek ((SDL_RWops *)handle, offset, sdlWhence);

	}


	int64_t File::Tell () {

		return handle ? SDL_RWtell ((SDL_RWops *)handle) : -1;

	}


	size_t File::Write (const void *ptr, size_t size) {

		return handle ? SDL_RWwrite ((SDL_RWops *)handle, ptr, 1, size) : -1;

	}


}
