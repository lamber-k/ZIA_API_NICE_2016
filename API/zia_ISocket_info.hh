#pragma	once

namespace zia
{
	typedef	unsigned int	ip;
	typedef unsigned short	port;

	class ISocket_info
	{
	public:
		virtual ~ISocket_info() {}

		virtual zia::ip		ip() const = 0;
		virtual zia::port	port() const = 0;

		virtual void		ip(zia::ip) = 0;
		virtual void		port(zia::port) = 0;
	};
}

