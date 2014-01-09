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
	typedef void	(*on_read_handler)(const zia::IBuffer &, const std::size_t);
	typedef void	(*on_write_handler)(const std::size_t);
	typedef void	(*on_error_handler)(const zia::socket_error);
	typedef void	(*on_change_state_handler)(const socket_state);

	class abstract_socket
	{
	public:
		virtual						~abstract_socket() {};

		virtual void				register_error_handler(const on_error_handler &) = 0;
		virtual void				register_read_handler(const on_read_handler &) = 0;
		virtual void				register_write_handler(const on_write_handler &) = 0;
		virtual void				register_change_state_handler(const on_change_state_handler &) = 0;

		virtual socket_descriptor	socket_descriptor() const = 0 {return (_socket);};
		virtual void				close();

	protected:
		zia::socket_descriptor			_socket;
	};
}

#endif // !ZIA_ABSTRACT_SOCKET
