#ifndef ZIA_HTTP_TYPES_H_
# define ZIA_HTTP_TYPES_H_

# include	<string>

/*!
 * @file	"zia_HTTP_types.hh"
 * @if french
 * @brief	Types liés aux requêtes et réponses HTTP
 *
 * @elseif english
 * @brief	HTTP request and responses types
 *
 * @endif
 *
 */

# define	CRLF	"\r\n"
# define	SP	" "

/*!	@brief zia Namespace
 */
namespace	zia
{

  /*!	@brief http Namespace
   */
  namespace	http
  {
    /*!	@if french
     *	@brief		Définition du type version.
     *
     *	@elseif english
     *	@brief		version Typedef.
     *
     *	@endif
     */
    typedef std::string	version_type;

    /*!	@if french
     *	@brief		Définition du type uri (identifiants uniformisés de ressource).
     *
     *	@elseif english
     *	@brief		uri (Uniform Resource Identifier) Typedef.
     *
     *	@endif
     */
    typedef std::string	uri_type;

    /*!	@if french
     *	@brief		Définition du type method.
     *
     *  une méthode peut être un des types de base ou une extension comme définis par le RFC 2616.
     *
     *	@elseif english
     *	@brief		method Typedef.
     *
     *  A method can be defined with one of the base types or an extension type (defined in RFC 2616).
     *
     *	@endif
     */
    typedef std::string	method_type;

    /*!	@if french
     *	@brief		Définition du type de code retour HTTP.
     *
     *	@elseif english
     *	@brief		HTTP return code Typedef.
     *
     *	@endif
     */
    typedef std::string response_code_type;

    /*!	@if french
     *	@brief		Définition du type reason_phrase.
     *
     *	@elseif english
     *	@brief		reason phrase Typedef.
     *
     *	@endif
     */
    typedef std::string	reason_phrase_type;

    /*!	@if french
     *	@brief		Définition du type body.
     *
     *	@elseif english
     *	@brief		body Typedef.
     *
     *	@endif
     */
    typedef std::string	body_type;

    /*!	@if french
     *	@brief		Définition du type "nom du field".
     *
     *	@elseif english
     *	@brief		field name Typedef.
     *
     *	@endif
     */
    typedef std::string	field_name_type;

    /*!	@if french
     *	@brief		Définition du type de la valeur associé à un field_name_type
     *
     *	@elseif english
     *	@brief		field value Typedef.
     *
     *	@endif
     */
    typedef std::string	field_value_type;

    /*!	@if french
     *	@brief		Définition du type de conteneur des clés/valeur du field HTTP
     *
     *	@elseif english
     *	@brief		HTTP fields container Typedef.
     *
     *	@endif
     */
    typedef std::map<field_name_type, field_value_type>	fields_type;

    /*!	@if french
     *	@brief		Définition du type de conteneur des clés/valeur du field HTTP
     *
     *	@elseif english
     *	@brief		HTTP fields container Typedef.
     *
     *	@endif
     */
    typedef std::string	raw_type;
  }
}

#endif /* ZIA_HTTP_TYPES_H_ */
