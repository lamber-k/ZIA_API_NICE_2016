
#ifndef ZIA_STATUS_CODE
#define ZIA_STATUS_CODE


namespace zia
{

  /*!
   * @file	"zia_Status_code.hh"
   * @if french
   * @brief     Decris l'interface pour un status code
   *
   * @elseif english
   * @brief	Describes an interface for a status code
   *
   * @endif
   *
   */

  class IStatus_Code
  {
  public:

    
    typedef unsigned short code_type;

    virtual ~IStatus_Code() = 0 {};


    /*!
     * @if french
     * @brief     En cours
     *
     * @elseif english
     * @brief		Returns the status code
     *
     * @endif
     *
     */
    virtual code_type		code() const = 0; 


    /*!
     * @if french
     * @brief     En cours
     *
     * @elseif english
     * @brief		Returns information regarding the status code
     *
     * @endif
     *
     */
    virtual std::string		information() const = 0;

  }
}

#endif // ! ZIA_STATUS_CODE
