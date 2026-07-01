/*
	Lime's unified SDL2 configuration header ("our config").

	This single header is used for every target instead of SDL's in-tree
	include/SDL_config.h. It is placed first on the include path (-I custom/sdl),
	so both the SDL build and Lime's own SDL includes resolve to this file,
	keeping the configuration identical on both sides.

	It dispatches to SDL2's complete, per-target static configs
	(SDL_config_windows.h / _macosx.h / _iphoneos.h / _android.h, ...), which
	keep the full default backend set. Put any project-wide overrides in the
	"Lime overrides" block below and they apply across all platforms from one
	place.
*/

#ifndef SDL_config_h_
#define SDL_config_h_

#include "SDL_platform.h"

/* ------------------------------------------------------------------------- */
/* Lime overrides (applied on every target). Add custom HAVE_*/SDL_* defines  */
/* here; leave empty to use SDL's per-target defaults verbatim.               */
/* ------------------------------------------------------------------------- */


/* ------------------------------------------------------------------------- */
/* Per-target static configuration (SDL2's own headers, full backend set).    */
/* ------------------------------------------------------------------------- */
#if defined(__WIN32__) || defined(__WINGDK__)
#include "SDL_config_windows.h"
#elif defined(__WINRT__)
#include "SDL_config_winrt.h"
#elif defined(__XBOXONE__) || defined(__XBOXSERIES__)
#include "SDL_config_xbox.h"
#elif defined(__MACOSX__)
#include "SDL_config_macosx.h"
#elif defined(__IPHONEOS__)
#include "SDL_config_iphoneos.h"
#elif defined(__ANDROID__)
#include "SDL_config_android.h"
#elif defined(__EMSCRIPTEN__)
#include "SDL_config_emscripten.h"
#else
/* Linux and other Unix targets have no static config upstream; SDL normally
   generates one via configure/CMake. Fall back to the minimal config so the
   build still succeeds. Replace this with a generated/curated SDL_config.h for
   a full-featured Linux build. */
#include "SDL_config_minimal.h"
#endif

#endif /* SDL_config_h_ */
