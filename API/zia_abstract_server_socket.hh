#ifndef		ZIA_ABSTRACT_SERVER_SOCKET
# define	ZIA_ABSTRACT_SERVER_SOCKET

# include	"zia_abstract_socket.hh"

namespace zia
{
    typedef void	(*on_accept)(const abstract_socket *);

    class abstract_server_socket
    {
	public:
	virtual			~abstract_server_socket();

	virtual void	register_on_accept_handler(const abstract_socket *) = 0;
    };
}

#endif // !ZIA_ABSTRACT_SERVER_SOCKET
