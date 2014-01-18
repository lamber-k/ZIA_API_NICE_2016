#pragma	once

/*!
 * @file	"zia_Socket_info.hh"
 * @if french
 * @brief	Abstract Class définissant les informations liées à la socket.
 *
 * @elseif english
 * @brief	Abstract Class. Describe information related to socket(s).
 *
 * @endif
 *
 */

# include		"zia_ISocket_info.hh"

/*!	@brief zia Namespace
 */
namespace zia
{
  /*!	@if french
   *	@brief		En cours.
   *
   *	@elseif english
   *	@brief		Socket_info class implementation.
   *
   *
   *	@endif
   */
  class Socket_info : public ISocket_info
  {
  public:
    virtual ~Socket_info() {}

    /*!	@brief Default Constructor
     */
    Socket_info() {}

    /*!	@brief Constructor that take ip and port.
     */
    Socket_info(const zia::ip ip, const zia::port port) : _ip(ip), _port(port) {}

    /*!	@brief Copy Constructor.
     */
    Socket_info(const Socket_info &src) : _ip(src._ip), _port(src._port) {}

    /*!	@brief IP getter.
     */
    virtual zia::ip	ip() const {return (_ip);};

    /*!	@brief Port getter.
     */
    virtual zia::port	port() const {return (_port);};

    /*!	@brief IP setter.
     */
    virtual void	ip(zia::ip ip) {_ip = ip;};

    /*!	@brief Port setter.
     */
    virtual void	port(zia::port port) {_port = port;};

  private:
    zia::ip	_ip;
    zia::port	_port;
  };
}
