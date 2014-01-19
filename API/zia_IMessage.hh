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
  public:
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

    /*!
     *
     * @if french
     * @brief En cours.
     *
     * @elseif english
     * @brief    Add an attribute to the request.
     *
     * @endif
     *
     */
    virtual void    *addattr(std::string name, std::size_t size, zia::IModule &module) = 0;

    /*!
     *
     * @if french
     * @brief En cours.
     *
     * @elseif english
     * @brief    Add an attribute to the request.
     *
     * @endif
     *
     */
    virtual void    *addattr(std::string name, std::size_t size) = 0;

    /*!
     *
     * @if french
     * @brief En cours.
     *
     * @elseif english
     * @brief    Get an attribute of the request.
     *
     * @endif
     *
     */
    template <typename T>
    virtual T		*getattr<T>(std::string name, zia::IModule &module) = 0;

    /*!
     *
     * @if french
     * @brief En cours.
     *
     * @elseif english
     * @brief    Get an attribute of the request.
     *
     * @endif
     *
     */
    template <typename T>
    virtual T    *getattr<T>(std::string name) = 0;
  };
}

#endif /* IMESSAGE_H_ */
