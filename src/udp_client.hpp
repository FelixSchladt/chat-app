#ifndef UDP_INCLUDED
#define UDP_INCLUDED

#include <boost/asio.hpp>
#include <string>
#include <iostream>

class udp_client {
public:
	void broadcast(std::string message, int from_port, int to_port);
	std::string receive_broadcast(int port);
};

#endif
