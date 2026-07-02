/*
 * FreeType bundles an old zlib (src/gzip). Its ftzconf.h only typedefs `Byte`
 * when neither MACOS nor TARGET_OS_MAC is defined:
 *
 *     #if !defined(MACOS) && !defined(TARGET_OS_MAC)
 *     typedef unsigned char  Byte;
 *     #endif
 *
 * On modern macOS TARGET_OS_MAC is always 1, so the typedef is skipped -- the
 * code expects classic-Mac <MacTypes.h> to supply `Byte`. We don't compile any
 * Carbon/ftmac source, so MacTypes is never in the picture and `Byte` ends up
 * undefined (Xcode 26 hard-errors). Force-include this on mac to provide it.
 *
 * Safe because no compiled freetype TU pulls in MacTypes.h (ftmac.c is not in
 * the file list), and FreeType core uses FT_Byte, never a bare `Byte`.
 */
#ifndef LIME_FT_BYTE_SHIM_H
#define LIME_FT_BYTE_SHIM_H

typedef unsigned char Byte;

#endif
