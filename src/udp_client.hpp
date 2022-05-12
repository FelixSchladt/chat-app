#include <boost/asio.hpp>
#include <string>
#include <iostream>

class udp_client {
public:
	void broadcast(std::string message, std::string mask, int port);
	std::string receive_broadcast(int port);
};
