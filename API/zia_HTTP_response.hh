#ifndef ZIA_HTTP_RESPONSE_H_
# define ZIA_HTTP_RESPONSE_H_

namespace	zia
{
  namespace	http
  {
    class Response
    {
    public:
      Response();
      Response(Response const&);
      virtual ~Response();

    public:
      Response& operator=(Response const&);
    };
  }
}


#endif /* ZIA_HTTP_RESPONSE_H_ */
