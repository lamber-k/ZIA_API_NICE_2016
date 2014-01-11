#ifndef		ZIA_ABSTRACT_SOCKET
# define	ZIA_ABSTRACT_SOCKET

# include	"zia_IBuffer.hh"

/*!
 * @file	"zia_ISocket.hh"
 * @if french
 * @brief	Décris l'interface de la socket lié au core.
 *
 * @elseif english
 * @brief	Describe the socket interface linked to the core.
 *
 * @endif
 *
 */

/*!	@brief zia Namespace
 */
namespace zia
{

  class	IHandler;

  /*!
   *
   * @if french
   * @brief	Définis les différentes erreures liées aux sockets.
   *
   * @elseif english
   * @brief	Define all the errors liked to sockets.
   *
   * @endif
   *
   */
  enum socket_error
    {
      DISCONNECTED	= 0,
      /*!<	@if french
       *	@brief		La socket a été déconnectée proprement.
       *
       *	@elseif english
       *	@brief		The socket was properly closed.
       *
       *	@endif
       */
      ERROR		= 1,
      /*!<	@if french
       *	@brief		La socket a relevé une erreur critique.
       *
       *	@elseif english
       *	@brief		The socket catch an unexpected error.
       *
       *	@endif
       */
    };

  /*!
   *
   * @if french
   * @brief	Définis les différents états d'une socket.
   *
   * @elseif english
   * @brief	Define all the socket states.
   *
   * At first, the socket is UNCONNECTED. When you are successfully connected, the socket switch to
   * CONNECTED state. Finally, when you close the socket, you'll switch the socket to CLOSING state.
   * Note the BOUND is only use for server socket.
   *
   * @endif
   *
   */
  enum socket_state
    {
      UNCONNECTED	= 0,
      /*!<	@if french
       *	@brief		La socket est dans un état non-connecté.
       *
       *	@elseif english
       *	@brief		The socket is not connected.
       *
       *	@endif
       */
      CONNECTED		= 1,
      /*!<	@if french
       *	@brief		La socket est connectée.
       *
       *	@elseif english
       *	@brief		A connection is established.
       *
       *	@endif
       */
      BOUND		= 2,
      /*!<	@if french
       *	@brief		La socket est attaché à une adresse et un port (pour les serveurs).
       *
       *	@elseif english
       *	@brief		The socket is bound to an address and port (for servers).
       *
       *	@endif
       */
      CLOSING		= 3
      /*!<	@if french
       *	@brief		La socket est sur le point de se fermer.
       *
       *	@elseif english
       *	@brief		The socket is about to close.
       *
       *	@endif
       */
    };

  /*!	@if french
   *	@brief		Le descripteur de fichier natif.
   *
   *	@elseif english
   *	@brief		The native socket descriptor.
   *
   *	@endif
   */
  typedef int	socket_descriptor;

  /*!	@if french
   *	@brief		En cours.
   *
   *	@elseif english
   *	@brief		Typedef for read signal.
   *
   *	@endif
   */
  typedef void	(*on_read)(const zia::IBuffer &, const IBuffer::size_t);

  /*!	@if french
   *	@brief		En cours.
   *
   *	@elseif english
   *	@brief		Typedef for write signal.
   *
   *	@endif
   */
  typedef void	(*on_write)(const std::size_t);

  /*!	@if french
   *	@brief		En cours.
   *
   *	@elseif english
   *	@brief		Typedef for error signal.
   *
   *	@endif
   */
  typedef void	(*on_error)(const zia::socket_error);

  /*!	@if french
   *	@brief		En cours.
   *
   *	@elseif english
   *	@brief		Typedef for changing state signal.
   *
   *	@endif
   */
  typedef void	(*on_change_state)(const socket_state);

  /*!	@if french
   *	@brief		En cours.
   *
   *	@elseif english
   *	@brief		ISocket class.
   *
   *	Describe the interface that all socket have to inherit.
   *
   *	@endif
   */
  class ISocket
  {
  public:
    virtual			~ISocket() {};

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		This function will be called if an error happened in the socket.
     *
     *	@endif
     */
    virtual void		on_error(const IHandler &) = 0;

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		This function will be called if there is something to read in the socket.
     *
     *	@endif
     */
    virtual void		on_read(const IHandler &) = 0;

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		This function will be called if there is something to write in the socket.
     *
     *	@endif
     */
    virtual void		on_write(const IHandler &) = 0;

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		This function will be called if the socket state was changed.
     *
     *	@endif
     */
    virtual void		on_change_state(const IHandler &) = 0;

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		return the native socket descriptor.
     *
     *	@endif
     */
    virtual socket_descriptor	socket_descriptor() const = 0;

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		return the native socket descriptor.
     *
     *	@endif
     */
    virtual void		close() = 0;

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		Push data to send.
     *
     *	@endif
     */
    virtual void		write(const IBuffer &) = 0;

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		change write monitor status.
     *
     *	@endif
     */
    virtual void		monitor_write(bool write) = 0;

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		get write monitor status.
     *
     *	@endif
     */
    virtual bool		monitor_write() const = 0;

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief	        change read monitor status.
     *
     *	@endif
     */
    virtual void		monitor_read(bool read) = 0;

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief	        get read monitor status.
     *
     *	@endif
     */
    virtual bool		monitor_read() const = 0;
  };
}

#endif // !ZIA_ABSTRACT_SOCKET
