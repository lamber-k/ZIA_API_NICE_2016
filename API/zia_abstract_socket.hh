#ifndef		ZIA_ABSTRACT_SOCKET
# define	ZIA_ABSTRACT_SOCKET

# include	"zia_buffer.hh"

namespace zia
{
	enum socket_error
	{
		DISCONNECTED	= 0,
		ERROR			= 1,
	};

	enum socket_state
	{
		UNCONNECTED	= 0,
		CONNECTED	= 1,
		BOUND		= 2,
		CLOSING		= 3
	};

	typedef int		socket_descriptor;
	typedef void	(*on_read)(const zia::IBuffer &, const std::size_t);
	typedef void	(*on_write)(const std::size_t);
	typedef void	(*on_error)(const zia::socket_error);
	typedef void	(*on_change_state)(const socket_state);

	class abstract_socket
	{
	public:
		virtual						~abstract_socket() {};

		virtual void				register_error(const handler &) = 0;
		virtual void				register_read(const handler &) = 0;
		virtual void				register_write(const handler &) = 0;
		virtual void				register_change_state(const handler &) = 0;

		virtual socket_descriptor	socket_descriptor() const = 0 {return (_socket);};
		virtual void				close();

	protected:
		zia::socket_descriptor			_socket;
	};
}

#endif // !ZIA_ABSTRACT_SOCKET
