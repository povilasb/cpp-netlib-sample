#include <iostream>


using namespace std;
using namespace boost::network;
using namespace boost::network::http;


int
main(void)
{
	client::request request("http://povilasb.com");
	request << header("Connection", "close");
	client client_;
	client::response response_ = client_.get(request);
	std::string body_ = body(response);

	cout << body_ << '\n';

	return 0;
}
