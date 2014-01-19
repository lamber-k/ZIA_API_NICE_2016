#ifndef IMESSAGE_H_
# define IMESSAGE_H_

/*!
 * @file	"zia_IMessage.hh"
 * @if french
 * @brief	Interface décrivant le cheminement d'un message de bout en bout
 *
 * @elseif english
 * @brief	Interface that describe a message from scratch.
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
    class	Request;
    class	Response;
    class	ISocket_info;
  }

  /*!
   *
   * @if	french
   * @brief	Interface d'un message
   *
   * @elseif	english
   * @brief	Message interface
   *
   * @endif
   *
   */
  class		IMessage
  {
    /*!
     *
     * @if	french
     * @brief	Récupère une requete.
     *
     * @elseif	english
     * @brief	Get the request.
     *
     * @endif
     *
     */
    virtual http::Request	&request() = 0;

    /*!
     *
     * @if	french
     * @brief	Récupère la réponse.
     *
     * @elseif	english
     * @brief	Get the response.
     *
     * @endif
     *
     */
    virtual http::Response	&response() = 0;

    /*!
     *
     * @if	french
     * @brief	Récupère l'interface décrivant les informations de connexions.
     *
     * @elseif	english
     * @brief	Get connexion informations interface.
     *
     * @endif
     *
     */
    virtual ISocket_info	&socket_info() = 0;
  };
}

#endif /* IMESSAGE_H_ */
