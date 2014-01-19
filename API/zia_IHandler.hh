
#ifndef		ZIA_IHANDLER
#define		ZIA_IHANDLER

/*!
 * @file	"zia_IHandler.hh"
 * @if french
 * @brief	Décris la classe interface des handler(s)
 *
 * @elseif english
 * @brief	Describe the handler class interface.
 *
 * @endif
 *
 */

# include	"zia_registration.hh"

namespace zia
{
	class	IMessage;
	class	IModule;

  /*!
   *
   * @if french
   * @brief	En cours.
   *
   * @elseif english
   * @brief	Zia Handler interface.
   *
   * @endif
   *
   */
  class IHandler
  {

  private:

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief Returns the instance of IHandler's module
     *
     *  @endif
     */
    virtual const IModule *module() const = 0;

  public:

    virtual ~IHandler() {};

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief Returns the priority of a handler based on
     *	       the request passed as a parameter
     *
     *  @endif
     */
    virtual enum zia::registration_priority	priority(IMessage& request) const = 0;


    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief 	The core calls this method to process the request
     *  with via the current instance of IHandler
     *	@endif
     */
    virtual void 		operator()(IMessage&) const = 0;

  };
}

#endif		// ! ZIA_IHANDLER
