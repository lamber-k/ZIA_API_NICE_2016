#pragma	once

# include		"zia_ISocket_info.hh"

namespace zia
{
	class Socket_info : public ISocket_info
	{
	public:
		virtual ~Socket_info() {}
		Socket_info(const zia::ip ip, const zia::port port) : _ip(ip), _port(port) {}

		virtual zia::ip		ip() const {return (_ip);};
		virtual zia::port	port() const {return (_port);};

		virtual void		ip(zia::ip ip) {_ip = ip;};
		virtual void		port(zia::port port) {_port = port;};

	private:
		zia::ip		_ip;
		zia::port	_port;
	};
}

