#pragma once

namespace zia
{
    using std::string;

    enum signal_type
    {
	a, b,
	c, d
    };

    typedef Status_code (*handler_type) (Request&)

    class Core
    {
	public:
	bool	on_signal(signal_type signal, handler_type handler);
    };
}

namespace zia
{
    class Request
    {
	public:
	// Add an attribute in the request memory publicly available
	void*	addattr(const string& name, size_t size);

	// Add an attribute in the request memory only available to that module
	void*	addattr(const string& name, size_t size, const void* module);

	// Get an attribute from the request memory publicly available
	void*	getattr(const string& name);

	// Get an attribute from the request memory only available to that module
	void*	getattr(const string& name, const void* module);


	private:
	// Allocate memory used by addattr()
	// Allocates size bytes and returns a pointer to the allocated memory.
	// The memory is automatically freed.
	void*	alloc(size_t size);
    }
}
