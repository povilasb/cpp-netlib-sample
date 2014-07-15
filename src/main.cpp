#include <iostream>

#include <boost/network/protocol/http/client.hpp>


using namespace std;
using namespace boost::network;


int
main(void)
{
	http::client::request request("http://povilasb.com");
	request << header("Connection", "close");
	http::client client_;
	http::client::response response = client_.get(request);
	std::string body_ = body(response);

	cout << body_ << '\n';

	return 0;
}
