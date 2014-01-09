#ifndef		ZIA_REGISTRATION
# define	ZIA_REGISTRATION

namespace zia
{
/*
**
** registration_priority
** When you register, you can have some priority level.
** The priority look like this:
** REALLY_FIRST > FIRST > MIDDLE > LAST > REALLY_LAST
** Note that REALLY_* must be use carefully and  MIDDLE should be the
** default choice.
**
*/

	enum registration_priority
	{
		REALLY_FIRST	= 4,
		FIRST		= 3,
		MIDDLE		= 2,
		LAST		= 1,
		REALLY_LAST	= 0
	};

/*
**
** request_state
** Every HTTP Request have a directive line.
**
** a -> b -> c -> d -> e -> f
**
*/

	enum request_state
	{

	};
}


#endif // !ZIA_REGISTRATION
