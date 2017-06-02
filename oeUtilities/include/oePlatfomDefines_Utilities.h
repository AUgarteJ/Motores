#pragma once

#define OE_PLATFORM_WINDOWS		1

//! Active platform
#if defined(__WIN32__) || defined(_WIN32)
#define OE_ACTIVE_PLATFORM OE_PLATFORM_WINDOWS
#endif

//! Windows
#if OE_ACTIVE_PLATFORM == OE_PLATFORM_WINDOWS
#if defined(OE_UTILITIES_STATIC_LIB)
#define OE_UTILITIES_EXPORT
#else
#if defined(OE_UTILITIES_EXPORTS)
#define OE_UTILITIES_EXPORT __declspec(dllexport)
#else
#if defined (__MINGW32__)
#define OE_UTILITIES_EXPORT	
#else
#define	OE_UTILITIES_EXPORT __declspec(dllexport)
#endif
#endif
#endif

#if defined(_DEBUG) || defined(DEBUG)
#define OE_DEBUG_MODE 1
#else
#define OE_DEBUG_MODE 0
#endif

#if OE_ACTIVE_COMPILER == OE_COMPILER_INTEL
#define OE_THREAD_LOCAL __declspec(thread)
#endif
#endif

