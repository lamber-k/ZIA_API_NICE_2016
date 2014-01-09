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
** Note that REALLY_* must be use carefully
**
*/

	enum registration_priority
	{
		FIRST = 0,
		MIDDLE = 1,
		LAST = 2,
		REALLY_FIRST = 3,
		REALLY_LAST = 4
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
