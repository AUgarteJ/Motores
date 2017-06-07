#pragma once

#define OE_PLATFORM_WINDOWS		1

#define OE_PLATFORM_LINUX		2
/*!
\def OE_PLATFORM_MACOSX
\brief Defines the Mac OS X Platform
*/
#define OE_PLATFORM_MACOSX		3
/*!
\def OE_PLATFORM_PS4
\brief Defines the Playstation 4 Platform
*/
#define OE_PLATFORM_PS4			4
/*!
\def OE_PLATFORM_PSVITA
\brief Defines the Playstation Vita Platform
*/
#define OE_PLATFORM_PSVITA		5

//////////////////////////////////////////////////


//! Compilers
/*!
\def OE_COMPILER_MSVC
\brief Defines the Microsoft Visual Compiler
*/
#define OE_COMPILER_MSVC		1
/*!
\def OE_COMPILER_GCC
\brief Defines the GNUC Compiler
*/
#define OE_COMPILER_GCC			2
/*!
\def OE_COMPILER_CLANG
\brief Defines the Clang Compiler
*/
#define OE_COMPILER_CLANG		3
/*!
\def OE_COMPILER_INTEL
\brief Defines the Intel Compiler
*/
#define OE_COMPILER_INTEL		4

//////////////////////////////////////////////////


//! Architectures
/*!
\def OE_ARCH_x86_32
\brief Defines the 32-bit architecture
*/
#define OE_ARCH_x86_32			1
/*!
\def OE_ARCH_x86_64
\brief Defines the 64-bit architecture
*/
#define OE_ARCH_x86_64			2

//! Endians
#define OE_ENDIAN_BIG			1
#define OE_ENDIAN_LITTLE		2

#define OE_ENDIAN

//! Edition build
#define OE_EDITION_BUILD

//////////////////////////////////////////////////


//! Active compiler
#if defined _MSC_VER
/*!
\def OE_ACTIVE_COMPILER
\brief Microsoft's Visual Compiler
*/
#define OE_ACTIVE_COMPILER		OE_COMPILER_MSVC
/*!
\def OE_COMPILER_VERSION
\brief Defines the version of the compiler
*/
#define OE_COMPILER_VERSION		_MSC_VER
/*!
\def OE_THREAD_TYPE
\brief Defines the type of thread the compiler manages
*/
#define OE_THREAD_TYPE			__declspec(thread)

#elif defined __GNUC__
#define OE_ACTIVE_COMPILER		OE_COMPILER_GCC
#define OE_COMPILER_VERSION		(((__GNUC__)*100) + (__GNUC_MINOR__*10) + __GNUC_PATCHLEVEL__)
#define OE_THREAD_TYPE			__declspec(thread)

#elif defined __clang__
#define OE_ACTIVE_COMPILER		OE_COMPILER_CLANG
#define OE_COMPILER_VERSION		__clang_major__
#define OE_THREAD_TYPE			__thread

#elif defined __INTEL_COMPILER
#define OE_ACTIVE_COMPILER		OE_COMPILER_INTEL
#define OE_COMPILER_VERSION		__INTEL_COMPILER

#else
#pragma error "No known compiler"

#endif 

//////////////////////////////////////////////////


//! Compiler settings
#if OE_ACTIVE_COMPILER == OE_COMPILER_MSVC
#if OE_COMPILER_VERSION >= 1200
#define FORCE_INLINE __forceinline
#ifndef RESTRICT
#define RESTRICT __restrict
#endif
#endif
#elif defined (__MINGW32__)
#if !defined (FORCE_INLINE)
#define FORCE_INLINE __inline
#ifndef RESTRICT
#define RESTRICT
#endif
#endif
#else
#define FORCE_INLINE __inline
#ifndef RESTRICT
#define RESTRICT __restrict
#endif
#endif

//////////////////////////////////////////////////


//! Active platform
#if defined(__WIN32__) || defined(_WIN32)
#define OE_ACTIVE_PLATFORM OE_PLATFORM_WINDOWS
#elif defined(__APPLE_CC__)
#define OE_ACTIVE_PLATFORM OE_PLATFORM_MACOSX
#elif defined (__ORBIS__)
#define OE_ACTIVE_PLATFORM OE_PLATFORM_PS4
#elif defined (__psp2__)
#define OE_ACTIVE_PLATFORM OE_PLATFORM_PSVITA
#else
#define OE_ACTIVE_PLATFORM OE_PLATFORM_LINUX
#endif


//! Active Architecture
#if defined(__x86_x64__) || defined(_M_X64)
#define OE_ACTIVE_ARCHITECTURE OE_ARCH_x86_64
#else
/*!
\def OE_ACTIVE_ARCHITECTURE
\brief Defines the active architecture of the active platform and compiler
*/
#define OE_ACTIVE_ARCHITECTURE OE_ARCH_x86_32
#endif

//! Memory alignment
#if OE_ACTIVE_COMPILER == OE_COMPILER_MSVC
#define MS_ALIGN(n) __declspec(align(n))
#ifndef GCC_PACK
#define GCC_PACK(n)
#endif
#ifndef GCC_ALIGN
#define GCC_ALIGN(n)
#endif
#elif (OE_ACTIVE_COMPILER == OE_COMPILER_GCC && OE_PLATFORM == OE_PLATFORM_PS4)
#define GCC_ALIGN(n) __attribute__((__aligned__(n)))
#define MS_ALIGN
#define GCC_PACK(n)
#else
#define MS_ALIGN
#define GCC_PACK(n) __attribute__((packed, aligned(n)))
#define GCC_ALIGN(n) __attribute__((aligned(n)))
#endif


//! Throw override
#if OE_ACTIVE_COMPILER == OE_COMPILER_MSVC
#define _NOEXCEPT noexcept
#elif OE_ACTIVE_COMPILER == OE_COMPILER_INTEL
#define _NOEXCEPT noexcept
#elif OE_ACTIVE_COMPILER == OE_COMPILER_GCC
#define _NOEXCEPT noexcept
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

// !Linux and Mac
#if OE_ACTIVE_PLATFORM == OE_PLATFORM_LINUX || OE_ACTIVE_PLATFORM == OE_PLATFORM_MACOSX
#if defined(OE_GCC_VISIBILTY)
#define OE_UTILITY_EXPORT __attribute__((visibility("default")))
#else
#define OE_UTILITY_EXPORT
#endif

#define stricmp strcasecmp

#if defined(_DEBUG) || defined(DEBUG)
#define OE_DEBUG_MODE 1
#else
#define OE_DEBUG_MODE 0
#endif

#if OE_ACTIVE_COMPILER == OE_COMPILER_INTEL
#define OE_THREAD_LOCAL __declspec(thread)
#endif
#endif

//! PS4
#if OE_ACTIVE_PLATFORM == OE_PLATFORM_PS4
#if defined(OE_STATIC_LIB)
#define OE_UTILITY_EXPORT
#else
#if defined(OE_UTILITY_EXPORTS)
#define OE_UTILITY_EXPORT __declspec(dllexport)
#else
#if defined (__MINGW32__)
#define OE_UTILITY_EXPORT	
#else
#define	OE_UTILITY_EXPORT __declspec(dllexport)
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

//! Debug modes
#if OE_DEBUG_MODE
#define OE_DEBUG_ONLY(x) x
#define OE_ASSERT(x) assert(x)
#else
#define OE_DEBUG_ONLY(x)
#define OE_ASSERT(x) assert(x)
#endif