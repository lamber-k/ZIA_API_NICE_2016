#ifndef ZIA_HTTP_RESPONSE_H_
# define ZIA_HTTP_RESPONSE_H_

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
     *	@brief		Response class.
     *
     *	Implement the http response class
     *
     *	@endif
     */
    class Response
    {
    public:
      Response();
      Response(Response const&);
      virtual ~Response();

    public:
      Response& operator=(Response const&);
    };
  }
}


#endif /* ZIA_HTTP_RESPONSE_H_ */
