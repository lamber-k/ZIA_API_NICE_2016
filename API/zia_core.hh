#ifndef		ZIA_ICORE
# define	ZIA_ICORE

# include		"zia_registration.hh"

/*
** Namespace for every Zia API Classes
*/
namespace	zia
{

	class	abstract_socket;
	class	abstract_server_socket;
	class	acceptor_handler;
	class	request_handler;

/*
**
** Class ICore
** Interface for Zia's Core
**
** In order to interact with Zia's Core, The user must register.
** Some functions are userful for server socket purpose (register a socket, handle incoming messages, ...).
** Other one are used to transport http request between Modules.
**
*/

	class		ICore
	{
	public:

/*
**
** register_server_socket()
** Register a socket in the core. This socket will be monitored.
** 
*/
		virtual void	register_server_socket(zia::abstract_socket *server_socket, const zia::acceptor_handler &handler) = 0;

/*
** 
** register_request_state()
** Register a function to a specific state.
** You can also define a priority level to know if your function will be called.
** By default, priority is MIDDLE.
** see also: zia_registration.hh
**
*/
		virtual void	register_request_state(zia::request_handler &, zia::request_state, zia::registration_priority = zia::MIDDLE);

	};
}

#endif // ZIA_ICORE