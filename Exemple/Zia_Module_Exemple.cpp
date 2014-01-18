#include	<iostream>
#include	"zia_Module_Exemple.h"
#include	"zia_AHandler.hpp"
#include	"zia_ICore.hh"
#include	"zia_IServer_Socket.hh"
#include	"zia_Socket_info.hh"

Zia_Module_Exemple::Zia_Module_Exemple()
{
	
}

void	Zia_Module_Exemple::register_handlers(zia::ICore &core)
{
	core.register_server_socket(new Server(core));
	core.register_request_state(Handler(this), zia::HEADER_PARSER);
}

Zia_Module_Exemple::Server::Server(zia::ICore &core) : 
	_readable(true), _writeable(false), _sock(0), _core(core)
{
}

Zia_Module_Exemple::Server::~Server()
{
	
}

void	Zia_Module_Exemple::Server::on_accept()
{
	_core.register_client_socket(new Client);
}

void	Zia_Module_Exemple::Server::on_error()
{
	close();
}

void	Zia_Module_Exemple::Server::on_read()
{
	// read(_sock);
}

void	Zia_Module_Exemple::Server::on_write()
{
	// write(_sock);
}

zia::socket_descriptor	Zia_Module_Exemple::Server::socket_descriptor() const
{
	return (_sock);
}

const zia::ISocket_info	&Zia_Module_Exemple::Server::socket_info() const
{
	return (zia::Socket_info(0, 0));
}

void	Zia_Module_Exemple::Server::close()
{
	// close(_sock);
}

void	Zia_Module_Exemple::Server::write(const zia::Byte *bytes, const std::size_t size)
{
}

void	Zia_Module_Exemple::Server::monitor_read(bool read)
{
	_readable = read;
}

bool	Zia_Module_Exemple::Server::monitor_read() const
{
	return (_readable);
}

void	Zia_Module_Exemple::Server::monitor_write(bool write)
{
	_writeable = write;
}

bool	Zia_Module_Exemple::Server::monitor_write() const
{
	return (_writeable);
}

Zia_Module_Exemple::Client::Client()
{
}

Zia_Module_Exemple::Client::~Client()
{
}

void	Zia_Module_Exemple::Client::on_error()
{
	close();
}

void	Zia_Module_Exemple::Client::on_read()
{
	// read(_sock);
}

void	Zia_Module_Exemple::Client::on_write()
{
	// write(_sock);
}

zia::socket_descriptor	Zia_Module_Exemple::Client::socket_descriptor() const
{
	return (_sock);
}

const zia::ISocket_info	&Zia_Module_Exemple::Client::socket_info() const
{
	return (zia::Socket_info(0, 0));
}

void	Zia_Module_Exemple::Client::close()
{
	// close(_sock);
}

void	Zia_Module_Exemple::Client::write(const zia::Byte *bytes, const std::size_t size)
{
}

void	Zia_Module_Exemple::Client::monitor_read(bool read)
{
	_readable = read;
}

bool	Zia_Module_Exemple::Client::monitor_read() const
{
	return (_readable);
}

void	Zia_Module_Exemple::Client::monitor_write(bool write)
{
	_writeable = write;
}

bool	Zia_Module_Exemple::Client::monitor_write() const
{
	return (_writeable);
}

Zia_Module_Exemple::Handler::Handler(const IModule *mod) : zia::AHandler(mod)
{

}

Zia_Module_Exemple::Handler::~Handler()
{
}

enum zia::registration_priority	Zia_Module_Exemple::Handler::priority(zia::IMessage &msg) const
{
	return (zia::MIDDLE); // MIDDLE is default behavior, see zia_registration.hh for information
}

void	Zia_Module_Exemple::Handler::operator()(zia::IMessage &msg) const
{
	// Here you code the handler function (parsing headers, un-zip, ...)
}