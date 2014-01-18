#pragma	once

# include	"zia_IHandler.hh"

namespace zia
{
	class AHandler : public zia::IHandler
	{
	public:
		AHandler(const zia::IModule *mod) : _module(mod) {}
		virtual ~AHandler() {};

	public:
		const IModule	*module() const {return (_module);}
		virtual enum registration_priority	priority(IMessage& request) const = 0;
		virtual void 		operator()(IMessage&) const = 0;

	private:
		const zia::IModule	*_module;
	};
}