#include <iostream>
#include <string>

#define BOOST_NETWORK_ENABLE_HTTPS
#include <boost/network/protocol/http/client.hpp>

namespace net = boost::network;
namespace http = net::http;


int
main(void)
{
	http::client::request request("http://povilasb.com");
	request << net::header("Connection", "close");
	http::client client_;
	http::client::response response = client_.get(request);
	std::string body_ = http::body(response);

	std::cout << body_ << '\n';

	return 0;
}
