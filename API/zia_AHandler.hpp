#pragma	once

/*!
 * @file	"zia_AHandler.hpp"
 * @if french
 * @brief	Décris la classe d'implémentation des handler(s)
 *
 * @elseif english
 * @brief	Describe the handler class implementation.
 *
 * @endif
 *
 */

# include	"zia_IHandler.hh"

/*!	@brief zia Namespace
 */
namespace zia
{
  /*!	@if french
   *	@brief		En cours.
   *
   *	@elseif english
   *	@brief		Abstract handler class.
   *
   *	Perform some implementation.
   *
   *	@endif
   */
  class AHandler : public zia::IHandler
  {
  public:
    /*!	@brief AHandler() constructor
     */
    AHandler(const zia::IModule *mod) : _module(mod) {}
    virtual ~AHandler() {};

  public:
    /*!	@brief Module getter implementation
     */
    const IModule			*module() const {return (_module);}
    virtual enum registration_priority	priority(IMessage& request) const = 0;
    virtual void			operator()(IMessage&) const = 0;

  private:
    const zia::IModule	*_module;
  };
}
