#ifndef		ZIA_BUFFER
# define	ZIA_BUFFER

/*!
 * @file	"zia_ISocket.hh"
 * @if french
 * @brief	Décris l'interface de la socket lié au core.
 *
 * @elseif english
 * @brief	Describe the socket interface linked to the core.
 *
 * @endif
 *
 */

# include	<cstddef>

/*!	@brief zia Namespace
 */
namespace zia
{

  /*!	@if french
   *	@brief		En cours.
   *
   *	@elseif english
   *	@brief		IBuffer class.
   *
   *	Describe the interface that buffer have to implement.
   *
   *	@endif
   */
  class IBuffer
  {
  public:
    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		Typedef a specific type for size().
     *
     *	@endif
     */
    typedef std::size_t	size_t;

    virtual ~IBuffer() {};

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		get the data() from the IBuffer.
     *
     *	@endif
     */
    virtual const char		*data() const = 0;

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		return the data size.
     *
     *	@endif
     */
    virtual const size_t	size() const = 0;

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		assign a IBuffer in another.
     *
     *	@endif
     */
    virtual IBuffer			&operator=(const IBuffer &) = 0;

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		Concatenate a IBuffer in the current IBuffer.
     *
     *	@endif
     */
    virtual IBuffer			&operator+=(const IBuffer &) = 0;

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		Concatenate the current IBuffer with the IBuffer passed in parameter.
     *			Don't change the current IBuffer
     *
     *	@endif
     */
    virtual IBuffer			operator+(const IBuffer &) = 0;

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		Test if the IBuffer matches.
     *
     *	@endif
     */
    virtual bool			operator==(const IBuffer &) const = 0;

    /*!	@if french
     *	@brief		En cours.
     *
     *	@elseif english
     *	@brief		Test if the IBuffer don't matches.
     *
     *	@endif
     */
    virtual bool			operator!=(const IBuffer &) const = 0;

  };
}

#endif // !ZIA_BUFFER
