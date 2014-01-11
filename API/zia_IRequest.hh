#ifndef		ZIA_ICORE
# define	ZIA_ICORE

/*!
 * @file	"zia_IRequest.hh"
 * @if french
 * @brief	Décris l'interface de la socket serveur lié au core.
 *
 * @elseif english
 * @brief	Describe the server socket interface linked to the core.
 *
 * @endif
 *
 */

/*!	@brief zia Namespace
 */
namespace	zia
{

  class	IHandler;

  /*!	@if french
   *	@brief		En cours.
   *
   *	@elseif english
   *	@brief		Interface for Zia's Core.
   *
   * In order to interact with Zia's Core, The user must register.
   * Some functions are userful for server socket purpose
   * (register a socket, handle incoming messages, ...).
   * Other one are used to transport http request between Modules.
   *
   *	@endif
   */
  class IRequest
  {
  public:
    /*! @if french
     *  @brief     En cours
     *
     *  @elseif english
     *  @brief  alloc size type
     *
     *  @endif
     */
    typedef std::size_t		size_type;

  private:
    /*!
     *
     * @if french
     * @brief En cours.
     *
     * @elseif english
     * @brief		Allocate a chuck of data.
     *
     * @endif
     *
     */
    virtual void		*alloc(size_type size) = 0;

  public:
    /*!
     *
     * @if french
     * @brief En cours.
     *
     * @elseif english
     * @brief		Add an attribute to the request.
     *
     * @endif
     *
     */
    virtual void		*addattr(std::string name, size_type size, zia::IModule &module) = 0;

    /*!
     *
     * @if french
     * @brief En cours.
     *
     * @elseif english
     * @brief		Add an attribute to the request.
     *
     * @endif
     *
     */
    virtual void		*addattr(std::string name, size_type size) = 0;

    /*!
     *
     * @if french
     * @brief En cours.
     *
     * @elseif english
     * @brief		Get an attribute of the request.
     *
     * @endif
     *
     */
    virtual void		*getattr(std::string name, size_type size, zia::IModule &module) = 0;

    /*!
     *
     * @if french
     * @brief En cours.
     *
     * @elseif english
     * @brief		Get an attribute of the request.
     *
     * @endif
     *
     */
    virtual void		*getattr(std::string name, size_type size) = 0;

    /*!
     *
     * @if french
     * @brief En cours.
     *
     * @elseif english
     * @brief			set the status code.
     *
     * @endif
     *
     */
    virtual void		status_code(const IStatus_code &code) = 0;

    /*!
     *
     * @if french
     * @brief En cours.
     *
     * @elseif english
     * @brief			get the status code.
     *
     * @endif
     *
     */
    virtual const IStatus_code	&status_code() const = 0;


    /*!
     *
     * @if french
     * @brief En cours.
     *
     * @elseif english
     * @brief			gets the servers response to the current request
     *
     * @endif
     *
     */
    virtual IRequest&		response(void) const = 0;

    /*!
     *
     * @if french
     * @brief En cours.
     *
     * @elseif english
     * @brief			sets the servers response to the current request
     *
     * @endif
     *
     */
    virtual void		response(IRequest &response) = 0;
  };
}

#endif // ZIA_ICORE
