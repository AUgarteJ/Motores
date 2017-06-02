#pragma once

#if OE_ACTIVE_PLATFORM == OE_PLATFORM_WINDOWS

#	if defined( OE_GRAPHICS_API_STATIC_LIB)
#		define OE_GRAPHICS_API_UTILITY_EXPORT
#	elif defined(OE_GRAPHICS_API_UTILITY_EXPORTS)
#			define OE_GRAPHICS_API_UTILITY_EXPORT __declspec( dllexport)
#	else	
#		if defined (__MINGW32__)	
#			define OE_GRAPHICS_API_UTILITY_EXPORT
#		else
#			define OE_GRAPHICS_API_UTILITY_EXPORT __declspec( dllimport )
#		endif
#	endif
#endif
