#ifndef		ZIA_ICORE
# define	ZIA_ICORE

/*!
 * @file	"zia_IServer_socket.hh"
 * @if french
 * @brief	Décris l'interface de la socket serveur lié au core.
 *
 * @elseif english
 * @brief	Describe the server socket interface linked to the core.
 *
 * @endif
 *
 */
# include		"zia_registration.hh"
# include		"zia_IServer_socket.hh"

/*!	@brief zia Namespace
 */
namespace	zia
{

  class	ISocket;
  class	IServer_socket;
  class	IHandler;
  class IMessage;

  /*!	@if french
   *	@brief		En cours.
   *
   *	@elseif english
   *	@brief		Interface for Zia's Core.
   *
   * In order to interact with Zia's Core, The user must register.
   * Some functions are userful for server socket purpose
   * (register a socket, handle incoming messages, ...).
   * Other one are used to transport http request between Modules.
   *
   *	@endif
   */
  class ZIA_CORE_API ICore
  {
  public:

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		Register a server socket in the core. This socket will be monitored.
     *
     *	@endif
     */
    virtual void	register_server_socket(zia::IServer_socket *server_socket) = 0;

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		Register a client socket in the core. This socket will be monitored.
     *
     *	@endif
     */
	virtual void	register_client_socket(zia::ISocket *client_socket) = 0;

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		Register a socket in the core. This socket will be monitored.
     *  Register a function to a specific state.
     *  @note see also: zia_registration.hh
     *
     *	@endif
     */
    virtual void	register_request_state(const zia::IHandler &handler, zia::Signal sig) = 0;


    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		Used to push the request to the core for processing.
     *
     *	@endif
     */
    virtual void	push_request(const IMessage *) = 0;

  protected:

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		send the response after the treatment is done.
     *
     *	@endif
     */
    virtual void	send_response(const IMessage &req, const ISocket &socket) = 0;


	/*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		Deletes the request after it has been processed.
     *
     *	@endif
     */
    virtual void	delete_request(IMessage *) = 0;

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		Used to call a module's handler on a Signal
     *
     *	@endif
     */
    virtual void	on_signal(Signal sig, IHandler &handle) = 0;

  };
}

#endif // ZIA_ICORE
