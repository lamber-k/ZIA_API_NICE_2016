#ifndef		ZIA_BUFFER
# define	ZIA_BUFFER

# include	<cstddef>

namespace zia
{
	class IBuffer
	{
	public:
		typedef std::size_t	size_t;

		virtual ~IBuffer() {};
		virtual const char		*data() const= 0;
		virtual const size_t	size() const = 0;
		
		virtual IBuffer			&operator=(const IBuffer &) = 0;
		virtual IBuffer			&operator+=(const IBuffer &) = 0;
		virtual IBuffer			&operator+(const IBuffer &) = 0;
		virtual bool			operator==(const IBuffer &) const = 0;
		virtual bool			operator!=(const IBuffer &) const = 0;

	};
}

#endif // !ZIA_BUFFER
