#ifndef		ZIA_REGISTRATION
# define	ZIA_REGISTRATION

/*!
 * @file	"zia_registration.hh"
 * @if french
 * @brief	Décris les énumérations nécéssaire a l'enregistrement d'un handler.
 *
 * Vous trouverez dans ce fichier la registration_priority et le request_state.
 * Tous deux décrivent respectivement le comportement et l'état dans lequel agit l'handler.
 *
 * @elseif english
 * @brief	Describe some useful enums for registration.
 *
 * You can find in this file the registration_priority and request_state.
 * They describe the behaviour and the state where they acts.
 *
 * @endif
 *
 */

/*!	@brief zia Namespace
 */
namespace zia
{
  /*!
   *
   * @if french
   * @brief	enregistre un handler avec un certain niveau de priorité.
   *
   * @elseif english
   * @brief	Register a handler with a specific priority level.
   * When you register, you can have some priority level.
   * The priority look like this:
   * REALLY_FIRST > FIRST > MIDDLE > LAST > REALLY_LAST
   * Note that REALLY_* must be use carefully and  MIDDLE should be the
   * default choice.
   *
   * @endif
   *
   */
  enum registration_priority
    {
      REALLY_FIRST		= 4,
      /*!<	@if french
       *	@brief		Enregistre un handler avec la priorité maximale
       *	@warning	A utiliser avec précautions. On preferera utiliser FIRST
       *
       *	@elseif english
       *	@brief		Register a handler with the maximal priority
       *	@warning	Use with caution. We'll prefer use FIRST
       *
       *	@endif
       */
      FIRST			= 3,
      /*!<	@if french
       *	@brief		Enregistre un handler avec une priorité élevée
       *
       *	@elseif english
       *	@brief		Register a handler with the high priority
       *
       *	@endif
       */
      MIDDLE			= 2,
      /*!<	@if french
       *	@brief		Enregistre un handler avec une priorité neutre
       *	@note		C'est le comportement par défaut à appliquer
       *
       *	@elseif english
       *	@brief		Register a handler with the normal priority
       *	@note		It's the default behavior to use.
       *
       *	@endif
       */
      LAST			= 1,
      /*!<	@if french
       *	@brief		Enregistre un handler avec une priorité faible
       *
       *	@elseif english
       *	@brief		Register a handler with a weak priority
       *
       *	@endif
       */
      REALLY_LAST		= 0
      /*!<	@if french
       *	@brief		Enregistre un handler avec la priorité minimale
       *	@warning	A utiliser avec précautions. On preferera utiliser LAST
       *
       *	@elseif english
       *	@brief		Register a handler with the minimal priority
       *	@warning	Use with caution. We'll prefer use LAST
       *
       *	@endif
       */
    };

  /*!
   *
   * @if french
   * @brief	enregistre un handler sur un état précis.
   *
   * @elseif english
   * @brief	Register a handler in a specific state.
   * Every HTTP Request have a directive line.
   *
   * a -> b -> c -> d -> e -> f
   *
   * @endif
   *
   */
  enum request_state
    {

    };
}


#endif // !ZIA_REGISTRATION
