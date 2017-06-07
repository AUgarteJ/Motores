#pragma once

#include <string>
#include "oePrerequisites_Utilities.h"
namespace oeEngineSDK
{


  typedef std::string String;
  typedef std::wstring wstring;

  //! Unsigned types
  /*!
  \brief 8-bit unsigned integer
  */
  typedef unsigned char			uint8;			//! 8-bit integer
                                        /*!
                                        \brief 16-bit unsigned integer
                                        */
  typedef unsigned short			uint16;			//! 16-bit integer
                                          /*!
                                          \brief 32-bit unsigned integer
                                          */
  typedef unsigned int			uint32;			//! 32-bit integer
#if OE_ACTIVE_COMPILER == OE_COMPILER_MSVC
                                        /*!
                                        \brief 64-bit unsigned integer for Microsoft Visual Compiler
                                        */
  typedef unsigned __int64	uint64;			//! 64-bit integer for Microsoft Visual Compiler
#else
                                        /*!
                                        \brief 64-bit unsigned integer for any other compiler
                                        */
  typedef unsigned long		uint64;			//! 64-bit integer for any other compiler
#endif

                                      //! Signed types
                                      /*!
                                      \brief 8-bit signed integer
                                      */
  typedef signed char				int8;			//! 8-bit integer
                                      /*!
                                      \brief 16-bit signed integer
                                      */
  typedef signed short			int16;			//! 16-bit integer
                                        /*!
                                        \brief 32-bit signed integer
                                        */
  typedef signed int				int32;			//! 32-bit integer
#if OE_ACTIVE_COMPILER == OE_COMPILER_MSVC
                                        /*!
                                        \brief 64-bit signed integer for Microsoft Visual Compiler
                                        */
  typedef signed __int64		int64;			//! 64-bit integer for Microsoft Visual Compiler
#else
                                        /*!
                                        \brief 64-bit signed integer for any other compiler
                                        */
  typedef signed long			int64;			//! 64-bit integer for any other compiler
#endif

                                      /*!
                                      \class QWord
                                      \brief 128-bit variable (QWord)
                                      */
  MS_ALIGN(16) class QWord {
  public:
    uint64		a_Lower;
    int64		a_Upper;

    //! Operator ()
    operator int64 () const {
      return a_Lower;
    }

    //! Default builder
    /*!
    \memberof QWord
    \brief Builds QWord instance, zero init
    */
    QWord() : a_Lower(0), a_Upper(0) {

    }

    //! Copy builder
    /*!
    \memberof QWord
    \brief Builds QWord instance, copying value from a double type param
    \param prm_From Value copied to QWord
    */
    QWord(double prm_From) : a_Lower((uint64)prm_From), a_Upper(0) {

    }
  }GCC_ALIGN(16);

  /*!
  \brief 128-bit signed integer
  */
  typedef QWord					int128;
  /*!
  \brief 128-bit unsigned integer
  */
  typedef QWord					uint128;

#if OE_ACTIVE_COMPILER == OE_COMPILER_MSVC || OE_ACTIVE_PLATFORM == OE_PLATFORM_PS4
  /*!
  \brief Wide character
  */
  typedef wchar_t					WCHAR;
#else
  /*!
  \brief Wide character
  */
  typedef unsigned short			WCHAR;
#endif

  /*!
  \brief ANSI character
  */

  typedef char					ANSI_CHAR;
  /*!
  \brief UNICODE character
  */
  typedef WCHAR					UNI_CHAR;

  /*!
  \brief Null data type
  */
  typedef int32					TYPE_OF_NULL;

  //! Size_t
#if ((OE_ACTIVE_ARCHITECTURE == OE_ARCH_x86_64) && (OE_ACTIVE_COMPILER == OE_COMPILER_MSVC))
  /*!
  \brief Size_t type
  */
  typedef unsigned __int64		SIZE_T;
#else
  /*!
  \brief Size_t type
  */
  typedef unsigned long 		SIZE_T;
#endif
}

