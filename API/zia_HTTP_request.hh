#ifndef ZIA_HTTP_REQUEST_H_
# define ZIA_HTTP_REQUEST_H_

/*!
 * @file	"zia_HTTP_response.hh"
 * @if french
 * @brief	Décris la classe lié a la réponse HTTP
 *
 * @elseif english
 * @brief	Describe the HTTP response class.
 *
 * @endif
 *
 */

/*!	@brief zia Namespace
 */
namespace	zia
{
  /*!	@brief http Namespace
   */
  namespace	http
  {
    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		Request class.
     *
     *	Implement the http request class
     *
     *	@endif
     */
    class Request
    {
    public:
      Request();
      Request(Request const&);
      virtual ~Request();

    public:
      Request& operator=(Request const&);
    };
  }
}

#endif /* ZIA_HTTP_REQUEST_H_ */
