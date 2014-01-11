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
# include	"zia_ISocket.hh"

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
  class	IServer_socket : public ISocket
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
    virtual void		on_accept(const ISocket *) = 0;
    virtual void		on_error(const IHandler &) = 0;
    virtual void		on_read(const IHandler &) = 0;
    virtual void		on_write(const IHandler &) = 0;
    virtual void		on_change_state(const IHandler &) = 0;
    virtual socket_descriptor	socket_descriptor() const = 0;
    virtual void		close() = 0;
    virtual void		write(const IBuffer &) = 0;
    virtual void		monitor_write(bool write) = 0;
    virtual bool		monitor_write() const = 0;
    virtual void		monitor_read(bool read) = 0;
    virtual bool		monitor_read() const = 0;
  };
}

#endif // !ZIA_ABSTRACT_SERVER_SOCKET
