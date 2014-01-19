#ifndef ZIA_HTTP_REQUEST_H_
# define ZIA_HTTP_REQUEST_H_

# include	<sstream>
# include	<map>
# include	"zia_HTTP_types.hh"

/*!
 * @file	"zia_HTTP_request.hh"
 * @if french
 * @brief	Décris la classe lié a la requête HTTP
 *
 * @elseif english
 * @brief	Describe the HTTP request class.
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
     *	@brief		Classe de requête HTTP.
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
      /*!	@if french
       *	@brief		Constructeur par défaut.
       *
       *	@elseif english
       *	@brief		Default constructor.
       *
       *	@endif
       */
      Request() { }

      /*!	@if french
       *	@brief		Constructeur avec methode, version et URI.
       *
       *	@elseif english
       *	@brief		Constructor that takes method, version and URI.
       *
       *	@endif
       */
      Request(const method_type &method, const version_type &version, const uri_type URI):
	_method(method),
	_uri(URI),
	_version(version)
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
      Request(Request const &src):
	_method(src._method),
	_uri(src._uri),
	_version(src._version),
	_fields(src._fields),
	_body(src._body)
      {
      }

      virtual ~Request() {}

    public:

      /*!	@if french
       *	@brief		Assigne une Copie de la classe.
       *
       *	@elseif english
       *	@brief		Copy Class Assignement.
       *
       *	@endif
       */
      Request& operator=(Request const &src)
      {
	if (this != &src)
	  {
	    _method = src._method;
	    _uri = src._uri;
	    _version = src._version;
	    _fields = src._fields;
	    _body = src._body;
	  }
	return (*this);
      }

    public:

      /*!	@if french
       *	@brief		Ajoute un champ a la requête HTTP.
       *
       *	@elseif english
       *	@brief		Add a field in HTTP request.
       *
       *	@endif
       */
      void	add_field(const field_name_type &name, const field_value_type &value)
      {
	_fields[name] = value;
      }

      /*!	@if french
       *	@brief		Test si ce champ existe dans cette requête.
       *
       *	@elseif english
       *	@brief		Test if this field exist in the request.
       *
       *	@endif
       */
      bool	field_exist(const field_name_type &name)
      {
	return (_fields.find(name) != _fields.end());
      }

      /*!	@if french
       *	@brief		Retourne les champs de la requête.
       *
       *	@elseif english
       *	@brief		Return the request fields.
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
       *	@brief		Retourne la methode de la requête.
       *
       *	@elseif english
       *	@brief		Get the request method.
       *
       *	@endif
       */
      const method_type		&method() const
      {
	return (_method);
      }

      /*!	@if french
       *	@brief		Modifie la methode de la requête.
       *
       *	@elseif english
       *	@brief		Set the request method.
       *
       *	@endif
       */
      void			method(const method_type &method)
      {
	_method = method;
      }

      /*!	@if french
       *	@brief		Retourne l'URI de la requête.
       *
       *	@elseif english
       *	@brief		Get the URI request.
       *
       *	@endif
       */
      const uri_type		&uri() const
      {
	return (_uri);
      }

      /*!	@if french
       *	@brief		Modifie l'URI de la requête.
       *
       *	@elseif english
       *	@brief		Set the URI request.
       *
       *	@endif
       */
      void			uri(const uri_type &uri)
      {
	_uri = uri;
      }

      /*!	@if french
       *	@brief		Retourne le "body" de la réponse.
       *
       *	@elseif english
       *	@brief		Get the body response.
       *
       *	@endif
       */
      const body_type		&body() const
      {
	return (_body);
      }

      /*!	@if french
       *	@brief		Modifie le contenu du body de la réponse.
       *
       *	@elseif english
       *	@brief		Set the response body content.
       *
       *	@endif
       */
      void			body(const body_type &body)
      {
	_body = body;
      }

      /*!	@if french
       *	@brief		Retourne le formattage de la requête HTTP crée.
       *
       *	@elseif english
       *	@brief		Return the raw format.
       *
       *	@endif
       */
      virtual const raw_type	format() const
      {
	std::stringstream	output;

	output << _method << SP << _uri << SP << _version << CRLF;
	for (fields_type::const_iterator it = _fields.begin(); it != _fields.end(); ++it)
	  output << it->first << ':' << it->second << CRLF;
	output << CRLF << _body;
	return (output.str());
      }

    protected:
      method_type	_method;
      uri_type		_uri;
      version_type	_version;
      fields_type	_fields;
      body_type		_body;
    };
  }
}

#endif /* ZIA_HTTP_REQUEST_H_ */
