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
# include		"zia_abstract_server_socket.hh"

/*!	@brief zia Namespace
 */
namespace	zia
{

  class	abstract_socket;
  class	abstract_server_socket;
  class	request_handler;

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
  class ICore
  {
  public:

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		Register a socket in the core. This socket will be monitored.
     *
     *	@endif
     */
    virtual void	register_server_socket(zia::abstract_socket *server_socket,
					       const zia::on_accept &handler) = 0;

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		Register a socket in the core. This socket will be monitored.
     *  Register a function to a specific state.
     *  You can also define a priority level to know if your function will be called.
     *  By default, priority is MIDDLE.
     *  @note see also: zia_registration.hh
     *
     *	@endif
     */
    virtual void	register_request_state(zia::request_handler &,
					       zia::request_state,
					       zia::registration_priority = zia::MIDDLE) = 0;

  };
}

#endif // ZIA_ICORE