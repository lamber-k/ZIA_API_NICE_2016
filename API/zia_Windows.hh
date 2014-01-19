#pragma	once

/*!
 * @file	"zia_Windows.hh"
 * @if french
 * @brief	Macros à utiliser pour la portabilité des DLL windows
 *
 * @elseif english
 * @brief	DLL Windows Macros.
 *
 * @endif
 *
 */

#if defined(_WINDOWS)
# if defined(ZIA_CORE_DLL_EXPORT)
#  define	ZIA_DLL_PORT	_declspec(dllexport)
# else
#  define	ZIA_DLL_PORT	_declspec(dllimport)
# endif
# define	ZIA_CORE_API	ZIA_DLL_PORT
#else
# define	ZIA_CORE_API
#endif
