

#ifndef			ZIA_MODULE
# define		ZIA_MODULE

# include		"zia_Windows.hh"

/*!
 * @file	"zia_IModule.hh"
 * @if french
 * @brief	Decris l'interface de la socket lie au core
 *
 * @elseif english
 * @brief	Describe a Module interface
 *
 * @endif
 *
 */

class	ICore;

/*!	@brief zia Namespace
 */
namespace		zia
{
  /*!	@if french
   *	@brief		En cours.
   *
   *	@elseif english
   *	@brief		Interface for Zia's Module.
   *
   *	@endif
   */
  class IModule
  {
  public:

    virtual	~IModule() = 0 {};

    /*! @if french
     *  @brief     En cours
     *
     *  @elseif english
     *  @brief  registers the modules handler to a reference of ICore
     *
     *  @endif
     */
    virtual	void register_handlers(ICore &) = 0;
  };
}

#endif // ! ZIA_MODULE
