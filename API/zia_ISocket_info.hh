#pragma	once

/*!
 * @file	"zia_ISocket_info.hh"
 * @if french
 * @brief	Interface définissant les informations liées à la socket.
 *
 * @elseif english
 * @brief	Interface. Describe information related to socket(s).
 *
 * @endif
 *
 */

/*!	@brief zia Namespace
 */
namespace zia
{
  /*!	@brief IP Type (only IPV4, can be improved with further developments).
   */
  typedef unsigned int		ip;

  /*!	@brief Port Type.
   */
  typedef unsigned short	port;

  /*!	@if french
   *	@brief		En cours.
   *
   *	@elseif english
   *	@brief		Socket_info interface.
   *
   *
   *	@endif
   */
  class ISocket_info
  {
  public:
    virtual ~ISocket_info() {}

    /*!	@brief ip getter
     */
    virtual zia::ip		ip() const = 0;

    /*!	@brief port getter
     */
    virtual zia::port		port() const = 0;

    /*!	@brief ip setter
     */
    virtual void		ip(zia::ip) = 0;

    /*!	@brief port setter
     */
    virtual void		port(zia::port) = 0;
  };
}
