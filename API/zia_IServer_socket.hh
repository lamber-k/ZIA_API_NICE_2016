#ifndef		ZIA_ABSTRACT_SERVER_SOCKET
# define	ZIA_ABSTRACT_SERVER_SOCKET

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
# include	"zia_abstract_socket.hh"

/*!	@brief zia Namespace
 */
namespace zia
{
  /*!	@if french
   *	@brief		En cours.
   *
   *	@elseif english
   *	@brief		Typedef for on_accept signal.
   *
   *	@endif
   */
  typedef void	(*on_accept)(const ISocket *);

  /*!	@if french
   *	@brief		En cours.
   *
   *	@elseif english
   *	@brief		IServer_socket class.
   *
   *	Describe the interface that all server socket have to inherit.
   *
   *	@endif
   */
  class	IServer_socket
  {
  public:
    virtual		~IServer_socket() {};

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		This function will be called if there is a new connection on the server.
     *
     *	@endif
     */
    virtual void	on_accept(const ISocket *) = 0;
  };
}

#endif // !ZIA_ABSTRACT_SERVER_SOCKET
