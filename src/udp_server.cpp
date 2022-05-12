// Copyright 2022 Thomas Gingele (https://github.com/Ginthom)

#include "udp_server.hpp"

using boost::asio::ip::udp;

void udp_server::broadcast(std::string message, std::string mask, int port) {
	try {
		boost::asio::io_service iosrv;
		udp::socket sock(iosrv, udp::endpoint(udp::v4(), port));
		sock.set_option(boost::asio::socket_base::broadcast(true));
		udp::endpoint dest(boost::asio::ip::address::from_string(mask), port);
		sock.send_to(boost::asio::buffer(message, message.size()), dest);
		sock.close();

	} catch(std::exception &e) {
		std::cout << "An error occured: " << e.what() << std::endl;
	}
}

int main() {
	//broadcast("Hallo ihr alle, esst mein broadcast signal.", "192.168.255.255", 7373);
}
