#ifndef ZIA_MODULE_EXEMPLE_H

# include	"zia_IModule.hh"
# include	"zia_IServer_socket.hh"
# include	"zia_AHandler.hpp"
# include	"zia_Socket_info.hh"
# if defined(_WINDOWS)
#  include	"zia_Windows.hh"
#  ifdef ZIA_MODULE_EXEMPLE_EXPORTS
#   define ZIA_MODULE_EXEMPLE_API __declspec(dllexport)
#  else
#   define ZIA_MODULE_EXEMPLE_API __declspec(dllimport)
#  endif
# else
#  define	ZIA_MODULE_EXEMPLE_API
# endif

namespace zia
{
  class	ICore;
  class	ISocket;
}

class ZIA_MODULE_EXEMPLE_API Zia_Module_Exemple : public zia::IModule
{
 public:
  Zia_Module_Exemple(void);
  void	register_handlers(zia::ICore &);

 private:
  class Server : public zia::IServer_socket
   {
   public:
     Server(zia::ICore &);
     ~Server();

   private:
     void			on_accept();
     void			on_error();
     void			on_read();
     void			on_write();
     zia::socket_descriptor	socket_descriptor() const;
     const zia::ISocket_info	&socket_info() const;
     void			close();
     void			write(const zia::Byte *bytes, const std::size_t size);
     void			monitor_write(bool write);
     bool			monitor_write() const;
     void			monitor_read(bool read);
     bool			monitor_read() const;

   private:
     bool					_readable;
     bool					_writeable;
     zia::socket_descriptor	_sock;
     zia::Socket_info		_info;
     zia::ICore				&_core;
   };

 class	Client : public zia::ISocket
 {
 public:
   Client();
   ~Client();
 public:
   void			on_error();
   void			on_read();
   void			on_write();
   zia::socket_descriptor	socket_descriptor() const;
   const zia::ISocket_info	&socket_info() const;
   void			close();
   void			write(const zia::Byte *bytes, const std::size_t size);
   void			monitor_write(bool write);
   bool			monitor_write() const;
   void			monitor_read(bool read);
   bool			monitor_read() const;

 private:
   bool					_readable;
   bool					_writeable;
   zia::Socket_info		_info;
   zia::socket_descriptor	_sock;
 };

 class	Handler : public zia::AHandler
 {
 public:
   Handler(const IModule *mod);
   virtual ~Handler();
   enum zia::registration_priority	priority(zia::IMessage& request) const;
   void 							operator()(zia::IMessage&) const;

 private:
 };
};

#endif // !ZIA_MODULE_EXEMPLE_H
