#pragma once

#include <oePlatformTypes.h>

#if OE_ACTIVE_PLATFORM == OE_PLATFORM_WINDOWS
#if defined (OE_CORE_STATIC_LIBRARY)
#define OE_CORE_EXPORT
#else
#if defined (OE_CORE_EXPORTS)
#define OE_CORE_EXPORT __declspec(dllexport)
#else
#if defined (__MINGW32__)
#define OE_CORE_EXPORT
#else
#define OE_CORE_EXPORT __declspec(dllexport)
#endif
#endif
#endif
#endif
