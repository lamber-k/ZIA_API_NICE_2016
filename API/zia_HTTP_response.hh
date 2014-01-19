#ifndef ZIA_HTTP_RESPONSE_H_
# define ZIA_HTTP_RESPONSE_H_

# include	"zia_HTTP_types.hh"

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
      /*!	@if french
       *	@brief		Constructeur par défaut.
       *
       *	@elseif english
       *	@brief		Default constructor.
       *
       *	@endif
       */
      Response() { }

      /*!	@if french
       *	@brief		Constructeur avec version, code de retour et phrase explicative.
       *
       *	@elseif english
       *	@brief		Constructor that takes version return code and reason phrase.
       *
       *	@endif
       */
      Response(const version_type &version, response_code_type code,
	      const reason_phrase_type &reason_phrase):
	_version(version),
	_code(code),
	_reason_phrase(reason_phrase)
      {
      }

      /*!	@if french
       *	@brief		Constructeur par copie.
       *
       *	@elseif english
       *	@brief		Copy constructor.
       *
       *	@endif
       */
      Response(Response const &src):
	_version(src._version),
	_response_code(src._response_code),
	_reason_phrase(src._reason_phrase),
	_fields(src._fields),
	_body(src._body)
      {
      }

      virtual ~Response() {}

    public:

      /*!	@if french
       *	@brief		Assigne une Copie de la classe.
       *
       *	@elseif english
       *	@brief		Copy Class Assignement.
       *
       *	@endif
       */
      Response& operator=(Response const &src)
      {
	if (this != &src)
	  {
	    _version = src._version;
	    _response_code = src._response_code;
	    _reason_phrase = src._reason_phrase;
	    _fields = src._fields;
	    _body = src._body;
	  }
	return (*this);
      }

    public:

      /*!	@if french
       *	@brief		Ajoute un champ à la réponse HTTP.
       *
       *	@elseif english
       *	@brief		Add a field in HTTP response.
       *
       *	@endif
       */
      void	add_field(const field_name_type &name, const field_value_type &value)
      {
	_fields[name] = value;
      }

      /*!	@if french
       *	@brief		Test si ce champ existe dans cette réponse.
       *
       *	@elseif english
       *	@brief		Test if this field exist in the response.
       *
       *	@endif
       */
      bool	field_exist(const field_name_type &name)
      {
	return (_fields.find(name) != _fields.end());
      }

      /*!	@if french
       *	@brief		Retourne les champs de la réponse.
       *
       *	@elseif english
       *	@brief		Return the response fields.
       *
       *	@endif
       */
      const fields_type	&fields() const
      {
	return (_fields);
      }

      /*!	@if french
       *	@brief		Retourne la version du protocole HTTP utilisé.
       *
       *	@elseif english
       *	@brief		Get the HTTP protocol version.
       *
       *	@endif
       */
      const version_type	&version() const
      {
	return (_version);
      }

      /*!	@if french
       *	@brief		Modifie la version du protocole HTTP utilisé.
       *
       *	@elseif english
       *	@brief		Set the HTTP protocol version.
       *
       *	@endif
       */
      void			version(const version_type &version)
      {
	_version = version;
      }

      /*!	@if french
       *	@brief		Retourne le code de réponse.
       *
       *	@elseif english
       *	@brief		Get the response code.
       *
       *	@endif
       */
      response_code_type		response_code() const
      {
	return (_response_code);
      }

      /*!	@if french
       *	@brief		Modifie le code de la réponse.
       *
       *	@elseif english
       *	@brief		Set the response code.
       *
       *	@endif
       */
      void			response_code(response_code_type response_code)
      {
	_response_code = response_code;
      }

      /*!	@if french
       *	@brief		Retourne la "reason_phrase" de la réponse.
       *
       *	@elseif english
       *	@brief		Get the reason phrase response.
       *
       *	@endif
       */
      const reason_phrase_type		&reason_phrase() const
      {
	return (_reason_phrase);
      }

      /*!	@if french
       *	@brief		Modifie le "reason_phrase" de la réponse.
       *
       *	@elseif english
       *	@brief		Set the response reason phrase.
       *
       *	@endif
       */
      void			reason_phrase(const reason_phrase_type &reason_phrase)
      {
	_reason_phrase = reason_phrase;
      }

      /*!	@if french
       *	@brief		Retourne le formattage de la réponse HTTP crée.
       *
       *	@elseif english
       *	@brief		Return the raw format.
       *
       *	@endif
       */
      virtual const raw_type	format() const
      {
	std::stringstream	output;

	output << _version << SP << _code << SP << _reason_phrase << CRLF;
	for (fields_type::const_iterator it = _fields.begin(); it != _fields.end(); ++it)
	  output << it->first << ':' << it->second << CRLF;
	output << CRLF << _body;
	return (output.str());
      }

    protected:
      version_type		_version;
      response_code_type	_code;
      reason_phrase_type	_reason_phrase;
      fields_type		_fields;
      body_type			_body;
    };
  }
}


#endif /* ZIA_HTTP_RESPONSE_H_ */
