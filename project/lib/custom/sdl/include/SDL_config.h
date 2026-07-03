// Lime full custom SDL2 config (single self-contained header).
// custom/sdl is first on the include path and the SDL build uses
// -DUSING_GENERATED_CONFIG_H, so SDL and Lime use this file. Add shared
// defines just after the guard; per-target sections follow.
#ifndef SDL_config_h_
#define SDL_config_h_
#include "SDL_platform.h"

/* ===== common to all supported targets ===== */
#if defined(__WIN32__) || defined(__WINGDK__) || defined(__WINRT__) || defined(__MACOSX__) || defined(__IPHONEOS__) || defined(__ANDROID__) || defined(__EMSCRIPTEN__) || defined(__LINUX__)
#define HAVE_ABS 1
#define HAVE_ACOS 1
#define HAVE_ACOSF 1
#define HAVE_ALLOCA 1
#define HAVE_ASIN 1
#define HAVE_ASINF 1
#define HAVE_ATAN 1
#define HAVE_ATAN2 1
#define HAVE_ATAN2F 1
#define HAVE_ATANF 1
#define HAVE_ATOF 1
#define HAVE_ATOI 1
#define HAVE_BSEARCH 1
#define HAVE_CALLOC 1
#define HAVE_CEIL 1
#define HAVE_CEILF 1
#define HAVE_COS 1
#define HAVE_COSF 1
#define HAVE_CTYPE_H 1
#define HAVE_EXP 1
#define HAVE_EXPF 1
#define HAVE_FABS 1
#define HAVE_FABSF 1
#define HAVE_FLOOR 1
#define HAVE_FLOORF 1
#define HAVE_FMOD 1
#define HAVE_FMODF 1
#define HAVE_FREE 1
#define HAVE_LIMITS_H 1
#define HAVE_LOG 1
#define HAVE_LOG10 1
#define HAVE_LOG10F 1
#define HAVE_LOGF 1
#define HAVE_LROUND 1
#define HAVE_LROUNDF 1
#define HAVE_MALLOC 1
#define HAVE_MATH_H 1
#define HAVE_MEMCMP 1
#define HAVE_MEMCPY 1
#define HAVE_MEMMOVE 1
#define HAVE_MEMSET 1
#define HAVE_POW 1
#define HAVE_POWF 1
#define HAVE_QSORT 1
#define HAVE_REALLOC 1
#define HAVE_ROUND 1
#define HAVE_ROUNDF 1
#define HAVE_SIGNAL_H 1
#define HAVE_SIN 1
#define HAVE_SINF 1
#define HAVE_SQRT 1
#define HAVE_SQRTF 1
#define HAVE_STDINT_H 1
#define HAVE_STDIO_H 1
#define HAVE_STRCHR 1
#define HAVE_STRCMP 1
#define HAVE_STRING_H 1
#define HAVE_STRLEN 1
#define HAVE_STRNCMP 1
#define HAVE_STRRCHR 1
#define HAVE_STRSTR 1
#define HAVE_STRTOD 1
#define HAVE_STRTOL 1
#define HAVE_STRTOUL 1
#define HAVE_TAN 1
#define HAVE_TANF 1
#define HAVE_TRUNC 1
#define HAVE_TRUNCF 1
#define SDL_AUDIO_DRIVER_DUMMY 1
#define SDL_VIDEO_OPENGL_ES2 1
#define SDL_VIDEO_RENDER_OGL_ES2 1
#define STDC_HEADERS 1
#endif

/* ===== common to POSIX targets (mac / ios / android / emscripten / linux) ===== */
#if defined(__MACOSX__) || defined(__IPHONEOS__) || defined(__ANDROID__) || defined(__EMSCRIPTEN__) || defined(__LINUX__)
#define HAVE_ALLOCA_H 1
#define HAVE_INTTYPES_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_GCC_ATOMICS 1
#define HAVE_DLOPEN 1
#define HAVE_GETENV 1
#define HAVE_SETENV 1
#define HAVE_PUTENV 1
#define HAVE_UNSETENV 1
#define HAVE_BCOPY 1
#define HAVE_STRTOK_R 1
#define HAVE_STRTOLL 1
#define HAVE_STRTOULL 1
#define HAVE_STRCASECMP 1
#define HAVE_STRNCASECMP 1
#define HAVE_VSSCANF 1
#define HAVE_VSNPRINTF 1
#define HAVE_SETJMP 1
#define HAVE_SIGACTION 1
#define HAVE_NANOSLEEP 1
#define HAVE_SYSCONF 1
#define HAVE_COPYSIGN 1
#define HAVE_COPYSIGNF 1
#define HAVE_SCALBN 1
#define HAVE_SCALBNF 1
#endif

#if defined(__WIN32__) || defined(__WINGDK__)
#if !defined(HAVE_WINSDKVER_H) && defined(__has_include)
#if __has_include(<winsdkver.h>)
#define HAVE_WINSDKVER_H 1
#endif
#endif
#ifdef HAVE_WINSDKVER_H
#include <winsdkver.h>
#endif
#if !defined(HAVE_SDKDDKVER_H) && defined(__has_include)
#if __has_include(<sdkddkver.h>)
#define HAVE_SDKDDKVER_H 1
#endif
#endif
#ifdef HAVE_SDKDDKVER_H
#include <sdkddkver.h>
#endif
#if !defined(HAVE_STDINT_H) && !defined(_STDINT_H_)
#if defined(_MSC_VER) && (_MSC_VER < 1600)
typedef signed __int8 int8_t;
typedef unsigned __int8 uint8_t;
typedef signed __int16 int16_t;
typedef unsigned __int16 uint16_t;
typedef signed __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef signed __int64 int64_t;
typedef unsigned __int64 uint64_t;
#ifndef _UINTPTR_T_DEFINED
#ifdef  _WIN64
typedef unsigned __int64 uintptr_t;

#else
typedef unsigned int uintptr_t;
#endif
#define _UINTPTR_T_DEFINED
#endif

#else
#endif
#endif
#ifdef _WIN64
# define SIZEOF_VOIDP 8

#else
# define SIZEOF_VOIDP 4
#endif
#ifdef __clang__
# define HAVE_GCC_ATOMICS 1
#endif
#define HAVE_DDRAW_H 1
#define HAVE_DINPUT_H 1
#define HAVE_DSOUND_H 1
#ifndef __WATCOMC__
#define HAVE_DXGI_H 1
#define HAVE_XINPUT_H 1
#if defined(_WIN32_MAXVER) && _WIN32_MAXVER >= 0x0A00
#define HAVE_WINDOWS_GAMING_INPUT_H 1
#endif
#if defined(_WIN32_MAXVER) && _WIN32_MAXVER >= 0x0602
#define HAVE_D3D11_H 1
#define HAVE_ROAPI_H 1
#endif
#if defined(__has_include)
#if __has_include(<d3d12.h>) && __has_include(<d3d12sdklayers.h>)
#define HAVE_D3D12_H 1
#endif
#endif
#if defined(_WIN32_MAXVER) && _WIN32_MAXVER >= 0x0603
#define HAVE_SHELLSCALINGAPI_H 1
#endif
#define HAVE_MMDEVICEAPI_H 1
#define HAVE_AUDIOCLIENT_H 1
#define HAVE_TPCSHRD_H 1
#define HAVE_SENSORSAPI_H 1
#endif
#if (defined(_M_IX86) || defined(_M_X64) || defined(_M_AMD64)) && (defined(_MSC_VER) && _MSC_VER >= 1600)
#define HAVE_IMMINTRIN_H 1
#elif defined(__has_include) && (defined(__i386__) || defined(__x86_64))
# if __has_include(<immintrin.h>)
#   define HAVE_IMMINTRIN_H 1
# endif
#endif
#ifdef HAVE_LIBC
#define HAVE_FLOAT_H 1
#ifndef __WATCOMC__
#endif
#define HAVE__STRREV 1
#define HAVE__STRICMP 1
#define HAVE__STRNICMP 1
#define HAVE__WCSICMP 1
#define HAVE__WCSNICMP 1
#define HAVE__WCSDUP 1
#ifndef __WATCOMC__
#define HAVE__COPYSIGN 1
#endif
#if defined(_MSC_VER)
#if _MSC_VER >= 1800
#define HAVE_STRTOLL 1
#define HAVE_STRTOULL 1
#define HAVE_VSSCANF 1
#define HAVE_SCALBN 1
#define HAVE_SCALBNF 1
#endif
#if _MSC_VER >= 1400
#define HAVE__FSEEKI64 1
#endif
#ifdef _USE_MATH_DEFINES
#define HAVE_M_PI 1
#endif
#elif defined(__WATCOMC__)
#define HAVE__FSEEKI64 1
#define HAVE_STRTOLL 1
#define HAVE_STRTOULL 1
#define HAVE_VSSCANF 1
#define HAVE_SCALBN 1

#else
#define HAVE_M_PI 1
#endif

#else
#define HAVE_STDARG_H   1
#define HAVE_STDDEF_H   1
#endif
#if defined(HAVE_MMDEVICEAPI_H) && defined(HAVE_AUDIOCLIENT_H)
#define SDL_AUDIO_DRIVER_WASAPI 1
#endif
#define SDL_AUDIO_DRIVER_DSOUND 1
#define SDL_AUDIO_DRIVER_WINMM  1
#define SDL_AUDIO_DRIVER_DISK   1
#define SDL_JOYSTICK_DINPUT 1
#define SDL_JOYSTICK_HIDAPI 1
#ifndef __WINRT__
#define SDL_JOYSTICK_RAWINPUT   1
#endif
#define SDL_JOYSTICK_VIRTUAL    1
#ifdef HAVE_WINDOWS_GAMING_INPUT_H
#define SDL_JOYSTICK_WGI    1
#endif
#define SDL_JOYSTICK_XINPUT 1
#define SDL_HAPTIC_DINPUT   1
#define SDL_HAPTIC_XINPUT   1
#ifdef HAVE_SENSORSAPI_H
#define SDL_SENSOR_WINDOWS  1

#else
#define SDL_SENSOR_DUMMY    1
#endif
#define SDL_LOADSO_WINDOWS  1
#define SDL_THREAD_GENERIC_COND_SUFFIX 1
#define SDL_THREAD_WINDOWS  1
#define SDL_TIMER_WINDOWS   1
#define SDL_VIDEO_DRIVER_DUMMY  1
#define SDL_VIDEO_DRIVER_WINDOWS    1
#ifndef SDL_VIDEO_RENDER_D3D
#define SDL_VIDEO_RENDER_D3D    1
#endif
#if !defined(SDL_VIDEO_RENDER_D3D11) && defined(HAVE_D3D11_H)
#define SDL_VIDEO_RENDER_D3D11  1
#endif
#if !defined(SDL_VIDEO_RENDER_D3D12) && defined(HAVE_D3D12_H)
#define SDL_VIDEO_RENDER_D3D12  1
#endif
#ifndef SDL_VIDEO_OPENGL
#define SDL_VIDEO_OPENGL    1
#endif
#ifndef SDL_VIDEO_OPENGL_WGL
#define SDL_VIDEO_OPENGL_WGL    1
#endif
#ifndef SDL_VIDEO_RENDER_OGL
#define SDL_VIDEO_RENDER_OGL    1
#endif
#ifndef SDL_VIDEO_RENDER_OGL_ES2
#endif
#ifndef SDL_VIDEO_OPENGL_ES2
#endif
#ifndef SDL_VIDEO_OPENGL_EGL
#define SDL_VIDEO_OPENGL_EGL    1
#endif
#define SDL_VIDEO_VULKAN 1
#define SDL_POWER_WINDOWS 1
#define SDL_FILESYSTEM_WINDOWS  1

#elif defined(__WINRT__)
#include <sdkddkver.h>
#ifndef NTDDI_WINBLUE
#define NTDDI_WINBLUE 0x06030000
#endif
#ifndef NTDDI_WIN10
#define NTDDI_WIN10 0x0A000000
#endif
#ifdef _WIN64
# define SIZEOF_VOIDP 8

#else
# define SIZEOF_VOIDP 4
#endif
#ifdef __clang__
# define HAVE_GCC_ATOMICS 1
#endif
#define HAVE_DXGI_H 1
#if !SDL_WINAPI_FAMILY_PHONE
#define HAVE_XINPUT_H 1
#endif
#define HAVE_MMDEVICEAPI_H 1
#define HAVE_AUDIOCLIENT_H 1
#define HAVE_TPCSHRD_H 1
#define HAVE_LIBC 1
#define HAVE_FLOAT_H 1
#define HAVE__STRREV 1
#define HAVE__STRUPR 1
#define HAVE__STRICMP 1
#define HAVE__STRNICMP 1
#define HAVE_VSNPRINTF 1
#define HAVE_M_PI 1
#define HAVE__COPYSIGN 1
#define HAVE__SCALB 1
#define HAVE__FSEEKI64 1
#define HAVE_ROAPI_H  1
#define SDL_AUDIO_DRIVER_WASAPI 1
#define SDL_AUDIO_DRIVER_DISK   1
#if SDL_WINAPI_FAMILY_PHONE
#define SDL_JOYSTICK_DISABLED 1
#define SDL_HAPTIC_DISABLED 1

#else
#define SDL_JOYSTICK_VIRTUAL    1
#if (NTDDI_VERSION >= NTDDI_WIN10)
#define SDL_JOYSTICK_WGI    1
#define SDL_HAPTIC_DISABLED 1

#else
#define SDL_JOYSTICK_XINPUT 1
#define SDL_HAPTIC_XINPUT   1
#endif
#endif
#define SDL_HIDAPI_DISABLED    1
#define SDL_SENSOR_DUMMY  1
#define SDL_LOADSO_WINDOWS  1
#if (NTDDI_VERSION >= NTDDI_WINBLUE)
#define SDL_THREAD_GENERIC_COND_SUFFIX 1
#define SDL_THREAD_WINDOWS  1

#else
#define SDL_THREAD_STDCPP   1
#endif
#define SDL_TIMER_WINDOWS   1
#define SDL_VIDEO_DRIVER_WINRT  1
#define SDL_VIDEO_DRIVER_DUMMY  1
#define SDL_VIDEO_OPENGL_EGL 1
#define SDL_VIDEO_RENDER_D3D11  1
#ifdef SDL_VIDEO_OPENGL_ES2
#endif
#define SDL_POWER_WINRT 1

#elif defined(__MACOSX__)
#include <AvailabilityMacros.h>
#ifdef __LP64__
    #define SIZEOF_VOIDP 8

#else
    #define SIZEOF_VOIDP 4
#endif
#define HAVE_FLOAT_H    1
#define HAVE_LIBUNWIND_H    1
#define HAVE_STRLCPY    1
#define HAVE_STRLCAT    1
#define HAVE_STRCASESTR 1
#define HAVE_M_PI   1
#define HAVE_SYSCTLBYNAME 1
#if defined(__has_include) && (defined(__i386__) || defined(__x86_64))
# if __has_include(<immintrin.h>)
#   define HAVE_IMMINTRIN_H 1
# endif
#endif
#if (MAC_OS_X_VERSION_MAX_ALLOWED >= 1070)
#define HAVE_O_CLOEXEC 1
#endif
#define SDL_AUDIO_DRIVER_COREAUDIO  1
#define SDL_AUDIO_DRIVER_DISK   1
#define SDL_JOYSTICK_HIDAPI 1
#define SDL_JOYSTICK_IOKIT  1
#define SDL_JOYSTICK_VIRTUAL    1
#define SDL_HAPTIC_IOKIT    1
#if MAC_OS_X_VERSION_MIN_REQUIRED >= 1080 && !defined(__i386__)
#define SDL_JOYSTICK_MFI 1
#endif
#define SDL_SENSOR_DUMMY  1
#define SDL_LOADSO_DLOPEN   1
#define SDL_THREAD_PTHREAD  1
#define SDL_THREAD_PTHREAD_RECURSIVE_MUTEX  1
#define SDL_TIMER_UNIX  1
#define SDL_VIDEO_DRIVER_COCOA  1
#define SDL_VIDEO_DRIVER_DUMMY  1
#undef SDL_VIDEO_DRIVER_X11
#define SDL_VIDEO_DRIVER_X11_DYNAMIC "/opt/X11/lib/libX11.6.dylib"
#define SDL_VIDEO_DRIVER_X11_DYNAMIC_XEXT "/opt/X11/lib/libXext.6.dylib"
#define SDL_VIDEO_DRIVER_X11_DYNAMIC_XINPUT2 "/opt/X11/lib/libXi.6.dylib"
#define SDL_VIDEO_DRIVER_X11_DYNAMIC_XRANDR "/opt/X11/lib/libXrandr.2.dylib"
#define SDL_VIDEO_DRIVER_X11_DYNAMIC_XSS "/opt/X11/lib/libXss.1.dylib"
#define SDL_VIDEO_DRIVER_X11_XDBE 1
#define SDL_VIDEO_DRIVER_X11_XRANDR 1
#define SDL_VIDEO_DRIVER_X11_XSCRNSAVER 1
#define SDL_VIDEO_DRIVER_X11_XSHAPE 1
#define SDL_VIDEO_DRIVER_X11_HAS_XKBKEYCODETOKEYSYM 1
#ifdef MAC_OS_X_VERSION_10_8
#define SDL_VIDEO_DRIVER_X11_XINPUT2 1
#define SDL_VIDEO_DRIVER_X11_SUPPORTS_GENERIC_EVENTS 1
#endif
#ifndef SDL_VIDEO_RENDER_OGL
#define SDL_VIDEO_RENDER_OGL    1
#endif
#undef SDL_VIDEO_RENDER_OGL_ES2
#if TARGET_RT_64_BIT && (MAC_OS_X_VERSION_MAX_ALLOWED >= 101100)
#define SDL_PLATFORM_SUPPORTS_METAL    1
#else
#define SDL_PLATFORM_SUPPORTS_METAL    0
#endif
#ifndef SDL_VIDEO_RENDER_METAL
#if SDL_PLATFORM_SUPPORTS_METAL
#define SDL_VIDEO_RENDER_METAL    1

#else
#define SDL_VIDEO_RENDER_METAL    0
#endif
#endif
#ifndef SDL_VIDEO_OPENGL
#define SDL_VIDEO_OPENGL    1
#endif
#undef SDL_VIDEO_OPENGL_ES2
#ifndef SDL_VIDEO_OPENGL_CGL
#define SDL_VIDEO_OPENGL_CGL    1
#endif
#ifndef SDL_VIDEO_OPENGL_GLX
#define SDL_VIDEO_OPENGL_GLX    1
#endif
#ifndef SDL_VIDEO_VULKAN
#if SDL_PLATFORM_SUPPORTS_METAL
#define SDL_VIDEO_VULKAN 1

#else
#define SDL_VIDEO_VULKAN 0
#endif
#endif
#ifndef SDL_VIDEO_METAL
#if SDL_PLATFORM_SUPPORTS_METAL
#define SDL_VIDEO_METAL 1

#else
#define SDL_VIDEO_METAL 0
#endif
#endif
#define SDL_POWER_MACOSX 1
#define SDL_FILESYSTEM_COCOA   1
#ifdef __ppc__
#define SDL_ALTIVEC_BLITTERS    1
#endif

#elif defined(__IPHONEOS__)
#ifdef __LP64__
#define SIZEOF_VOIDP 8

#else
#define SIZEOF_VOIDP 4
#endif
#define HAVE_STRLCPY    1
#define HAVE_STRLCAT    1
#define HAVE_STRCASESTR 1
#define HAVE_M_PI   1
#define HAVE_SYSCTLBYNAME 1
#define HAVE_O_CLOEXEC 1
#define SDL_AUDIO_DRIVER_COREAUDIO 1
#define SDL_HAPTIC_DUMMY 1
#define SDL_JOYSTICK_MFI 1
#define SDL_JOYSTICK_VIRTUAL    1
#ifdef __TVOS__
#define SDL_SENSOR_DUMMY    1

#else
#define SDL_SENSOR_COREMOTION   1
#endif
#define SDL_LOADSO_DLOPEN 1
#define SDL_THREAD_PTHREAD  1
#define SDL_THREAD_PTHREAD_RECURSIVE_MUTEX  1
#define SDL_TIMER_UNIX  1
#define SDL_VIDEO_DRIVER_UIKIT  1
#define SDL_VIDEO_DRIVER_DUMMY  1
#if !TARGET_OS_MACCATALYST
#define SDL_VIDEO_OPENGL_ES 1
#define SDL_VIDEO_RENDER_OGL_ES 1
#endif
#if (TARGET_OS_SIMULATOR && ((__IPHONE_OS_VERSION_MIN_REQUIRED >= 130000) || (__TV_OS_VERSION_MIN_REQUIRED >= 130000))) || (!TARGET_CPU_ARM && ((__IPHONE_OS_VERSION_MIN_REQUIRED >= 80000) || (__TV_OS_VERSION_MIN_REQUIRED >= 90000)))
#define SDL_PLATFORM_SUPPORTS_METAL	1

#else
#define SDL_PLATFORM_SUPPORTS_METAL	0
#endif
#if SDL_PLATFORM_SUPPORTS_METAL
#define SDL_VIDEO_RENDER_METAL  1
#endif
#if SDL_PLATFORM_SUPPORTS_METAL
#define SDL_VIDEO_VULKAN 1
#endif
#if SDL_PLATFORM_SUPPORTS_METAL
#define SDL_VIDEO_METAL 1
#endif
#define SDL_POWER_UIKIT 1
#define SDL_IPHONE_KEYBOARD 1
#define SDL_IPHONE_LAUNCHSCREEN 1
#define SDL_FILESYSTEM_COCOA   1

#elif defined(__ANDROID__)
#include <stdarg.h>
#define HAVE_STRLCPY    1
#define HAVE_STRLCAT    1
#define HAVE_STRCASESTR 1
#define HAVE_CLOCK_GETTIME  1
#ifdef __LP64__
#define SIZEOF_VOIDP 8

#else
#define SIZEOF_VOIDP 4
#endif
#define SDL_AUDIO_DRIVER_ANDROID    1
#define SDL_AUDIO_DRIVER_OPENSLES   1
#define SDL_AUDIO_DRIVER_AAUDIO     1
#define SDL_JOYSTICK_ANDROID    1
#define SDL_JOYSTICK_HIDAPI     1
#define SDL_JOYSTICK_VIRTUAL    1
#define SDL_HAPTIC_ANDROID  1
#define SDL_SENSOR_ANDROID  1
#define SDL_LOADSO_DLOPEN   1
#define SDL_THREAD_PTHREAD  1
#define SDL_THREAD_PTHREAD_RECURSIVE_MUTEX  1
#define SDL_TIMER_UNIX  1
#define SDL_VIDEO_DRIVER_ANDROID 1
#define SDL_VIDEO_OPENGL_ES 1
#define SDL_VIDEO_OPENGL_EGL 1
#define SDL_VIDEO_RENDER_OGL_ES 1
#if defined(__ARM_ARCH) && __ARM_ARCH < 7
#define SDL_VIDEO_VULKAN 0

#else
#define SDL_VIDEO_VULKAN 1
#endif
#define SDL_POWER_ANDROID 1
#define SDL_FILESYSTEM_ANDROID   1

#elif defined(__EMSCRIPTEN__)
#ifdef __LP64__
#define SIZEOF_VOIDP 8

#else
#define SIZEOF_VOIDP 4
#endif
#define HAVE_ICONV_H 1
#define HAVE_MALLOC_H 1
#define HAVE_MEMORY_H 1
#define HAVE_STDARG_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRINGS_H 1
#define HAVE_WCHAR_H 1
#define HAVE_WCSLEN 1
#define HAVE_WCSDUP 1
#define HAVE_WCSSTR 1
#define HAVE_WCSCMP 1
#define HAVE_WCSNCMP 1
#define HAVE_WCSCASECMP 1
#define HAVE_WCSNCASECMP 1
#define HAVE_STRLCPY 1
#define HAVE_STRLCAT 1
#define HAVE_SSCANF 1
#define HAVE_M_PI 1
#define HAVE_FSEEKO 1
#define HAVE_FSEEKO64 1
#define HAVE_SA_SIGACTION 1
#define HAVE_CLOCK_GETTIME 1
#define HAVE_MPROTECT 1
#define HAVE_ICONV 1
#define SDL_CPUINFO_DISABLED 1
#define SDL_HAPTIC_DISABLED 1
#define SDL_HIDAPI_DISABLED 1
#ifndef __EMSCRIPTEN_PTHREADS__
#define SDL_THREADS_DISABLED 1
#endif
#define SDL_AUDIO_DRIVER_DISK 1
#define SDL_AUDIO_DRIVER_EMSCRIPTEN 1
#define SDL_JOYSTICK_EMSCRIPTEN 1
#define SDL_SENSOR_DUMMY 1
#define SDL_LOADSO_DLOPEN 1
#ifdef __EMSCRIPTEN_PTHREADS__
#define SDL_THREAD_PTHREAD 1
#define SDL_THREAD_PTHREAD_RECURSIVE_MUTEX 1
#endif
#define SDL_TIMER_UNIX 1
#define SDL_VIDEO_DRIVER_EMSCRIPTEN 1
#define SDL_VIDEO_OPENGL_EGL 1
#define SDL_POWER_EMSCRIPTEN 1
#define SDL_FILESYSTEM_EMSCRIPTEN 1

#elif defined(__LINUX__)
/* Desktop Linux (glibc). Drivers are limited to the source files compiled in
   lib/sdl-files.xml's <section if="linux">: X11 video, ALSA + PulseAudio audio
   (dynamically loaded), evdev/udev/dbus, linux joystick/haptic. Do NOT enable a
   driver whose .c is not in that list (e.g. PipeWire/JACK/Wayland) -- SDL_audio.c /
   SDL_video.c reference the bootstrap symbol and it would fail to link. */
#ifdef __LP64__
#define SIZEOF_VOIDP 8

#else
#define SIZEOF_VOIDP 4
#endif
#define HAVE_LIBC 1
#define HAVE_FLOAT_H 1
#define HAVE_ICONV_H 1
#define HAVE_MALLOC_H 1
#define HAVE_MEMORY_H 1
#define HAVE_STDARG_H 1
#define HAVE_STDDEF_H 1
#define HAVE_STDLIB_H 1
#define HAVE_STRINGS_H 1
#define HAVE_WCHAR_H 1
#define HAVE_WCSLEN 1
#define HAVE_WCSDUP 1
#define HAVE_WCSSTR 1
#define HAVE_WCSCMP 1
#define HAVE_WCSNCMP 1
#define HAVE_WCSCASECMP 1
#define HAVE_WCSNCASECMP 1
#define HAVE_STRCASESTR 1
#define HAVE_SSCANF 1
#define HAVE_M_PI 1
#define HAVE_FOPEN64 1
#define HAVE_FSEEKO 1
#define HAVE_FSEEKO64 1
#define HAVE_SA_SIGACTION 1
#define HAVE_CLOCK_GETTIME 1
#define HAVE_GETPAGESIZE 1
#define HAVE_MPROTECT 1
#define HAVE_ICONV 1
#define HAVE_POLL 1
#define HAVE_O_CLOEXEC 1
#define HAVE_LINUX_INPUT_H 1
#define HAVE_DBUS_DBUS_H 1
#define HAVE_LIBUDEV_H 1
#if defined(__has_include) && (defined(__i386__) || defined(__x86_64))
# if __has_include(<immintrin.h>)
#   define HAVE_IMMINTRIN_H 1
# endif
#endif
/* input backends (sources: core/linux/SDL_evdev*, SDL_udev, SDL_dbus) */
#define SDL_INPUT_LINUXEV 1
#define SDL_INPUT_LINUXKD 1
#define SDL_USE_LIBUDEV 1
/* audio: only ALSA + PulseAudio are compiled, both dlopen'd at runtime */
#define SDL_AUDIO_DRIVER_ALSA 1
#define SDL_AUDIO_DRIVER_ALSA_DYNAMIC "libasound.so.2"
#define SDL_AUDIO_DRIVER_PULSEAUDIO 1
#define SDL_AUDIO_DRIVER_PULSEAUDIO_DYNAMIC "libpulse-simple.so.0"
#define SDL_AUDIO_DRIVER_DISK 1
/* input devices */
#define SDL_JOYSTICK_LINUX 1
#define SDL_JOYSTICK_VIRTUAL 1
#define SDL_HAPTIC_LINUX 1
#define SDL_SENSOR_DUMMY 1
/* threads / timers / loaders / power / filesystem */
#define SDL_LOADSO_DLOPEN 1
#define SDL_THREAD_PTHREAD 1
#define SDL_THREAD_PTHREAD_RECURSIVE_MUTEX 1
#define SDL_TIMER_UNIX 1
#define SDL_POWER_LINUX 1
#define SDL_FILESYSTEM_UNIX 1
/* video: X11 (dynamically loaded) + dummy fallback */
#define SDL_VIDEO_DRIVER_DUMMY 1
#define SDL_VIDEO_DRIVER_X11 1
#define SDL_VIDEO_DRIVER_X11_DYNAMIC "libX11.so.6"
#define SDL_VIDEO_DRIVER_X11_DYNAMIC_XEXT "libXext.so.6"
#define SDL_VIDEO_DRIVER_X11_DYNAMIC_XCURSOR "libXcursor.so.1"
#define SDL_VIDEO_DRIVER_X11_DYNAMIC_XINPUT2 "libXi.so.6"
#define SDL_VIDEO_DRIVER_X11_DYNAMIC_XRANDR "libXrandr.so.2"
#define SDL_VIDEO_DRIVER_X11_DYNAMIC_XSS "libXss.so.1"
#define SDL_VIDEO_DRIVER_X11_XCURSOR 1
#define SDL_VIDEO_DRIVER_X11_XDBE 1
#define SDL_VIDEO_DRIVER_X11_XINPUT2 1
#define SDL_VIDEO_DRIVER_X11_XINPUT2_SUPPORTS_MULTITOUCH 1
#define SDL_VIDEO_DRIVER_X11_XRANDR 1
#define SDL_VIDEO_DRIVER_X11_XSCRNSAVER 1
#define SDL_VIDEO_DRIVER_X11_XSHAPE 1
#define SDL_VIDEO_DRIVER_X11_SUPPORTS_GENERIC_EVENTS 1
#define SDL_VIDEO_DRIVER_X11_HAS_XKBKEYCODETOKEYSYM 1
/* gl / egl / vulkan (SDL_VIDEO_OPENGL_ES2 + RENDER_OGL_ES2 come from common block) */
#define SDL_VIDEO_OPENGL 1
#define SDL_VIDEO_OPENGL_EGL 1
#define SDL_VIDEO_OPENGL_GLX 1
#define SDL_VIDEO_RENDER_OGL 1
#define SDL_VIDEO_VULKAN 1
#define SDL_ASSEMBLY_ROUTINES 1

#else
#define HAVE_STDARG_H   1
#define HAVE_STDDEF_H   1
#if !defined(HAVE_STDINT_H) && !defined(_STDINT_H_)
#if defined(_MSC_VER) && (_MSC_VER < 1600)
typedef signed __int8 int8_t;
typedef unsigned __int8 uint8_t;
typedef signed __int16 int16_t;
typedef unsigned __int16 uint16_t;
typedef signed __int32 int32_t;
typedef unsigned __int32 uint32_t;
typedef signed __int64 int64_t;
typedef unsigned __int64 uint64_t;
#ifndef _UINTPTR_T_DEFINED
#ifdef  _WIN64
typedef unsigned __int64 uintptr_t;

#else
typedef unsigned int uintptr_t;
#endif
#define _UINTPTR_T_DEFINED
#endif

#else
#define HAVE_STDINT_H 1
#endif
#endif
#ifdef __GNUC__
#define HAVE_GCC_SYNC_LOCK_TEST_AND_SET 1
#endif
#define SDL_AUDIO_DRIVER_DUMMY  1
#define SDL_JOYSTICK_DISABLED   1
#define SDL_HAPTIC_DISABLED 1
#define SDL_HIDAPI_DISABLED 1
#define SDL_SENSOR_DISABLED 1
#define SDL_LOADSO_DISABLED 1
#define SDL_THREADS_DISABLED    1
#define SDL_TIMERS_DISABLED 1
#define SDL_VIDEO_DRIVER_DUMMY  1
#define SDL_FILESYSTEM_DUMMY  1
#endif
#endif

