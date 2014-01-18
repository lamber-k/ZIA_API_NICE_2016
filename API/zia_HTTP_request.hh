#ifndef ZIA_HTTP_REQUEST_H_
# define ZIA_HTTP_REQUEST_H_

namespace	zia
{
  namespace	http
  {
    class Request
    {
    public:
      Request();
      Request(Request const&);
      virtual ~Request();

    public:
      Request& operator=(Request const&);
    };
  }
}

#endif /* ZIA_HTTP_REQUEST_H_ */
