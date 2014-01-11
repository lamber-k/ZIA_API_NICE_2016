

#ifndef			ZIA_MODULE
# define		ZIA_MODULE

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

namespace		zia
{
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
    virtual	void register_handlers(ICore &) const = 0;
  }
}

#endif // ! ZIA_MODULE
