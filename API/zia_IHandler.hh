
#ifndef		ZIA_IHANDLER
#define		ZIA_IHANDLER

namespace zia
{
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
    
    virtual ~IHandler() = 0 {};

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief Returns the priority of a handler based on 
     *	       the request passed as a parameter
     *	
     *  @endif
     */
    virtual enum registration_priority	priority(IRequest& request) const = 0;


    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief 	The core calls this method to process the request
     *  with via the current instance of IHandler
     *	@endif
     */    
    virtual const IStatus_code		&operator()(request&) = 0;

  }
}

#endif		// ! ZIA_IHANDLER
