#include <boost/asio.hpp>
#include <string>
#include <iostream>

class udp_server {
public:
	void broadcast(std::string message, std::string mask, int port);
};
