#ifndef		ZIA_ICONNECTION_INFO
# define	ZIA_ICONNECTION_INFO

# include	"zia_Windows.hh"

/*!
 * @file	"zia_IConnection_info.hh"
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

  class	IModule;

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
  class IConnection_info
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
     * @brief		Add an attribute to the connection info
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
     * @brief		Add an attribute to the connection info
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
     * @brief		Get an attribute of the connection info
     *
     * @endif
     *
     */
    virtual void		*getattr<T>(std::string name, size_type size, zia::IModule &module) = 0;

    /*!
     *
     * @if french
     * @brief En cours.
     *
     * @elseif english
     * @brief		Get an attribute of the connection info
     *
     * @endif
     *
     */
    virtual void		*getattr<T>(std::string name, size_type size) = 0;

  };
}

#endif // ZIA_CONNECTION_INFO
