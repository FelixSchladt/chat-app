// Copyright 2022 Thomas Gingele (https://github.com/Ginthom)

#include "udp_client.hpp"

using boost::asio::ip::udp;

void udp_client::broadcast(std::string message, std::string mask, int port) {
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

std::string udp_client::receive_broadcast(int port) {
	char data[1024];
	try {
		boost::asio::io_service iosrv;
		udp::socket sock(iosrv, udp::endpoint(udp::v4(), port));
		udp::endpoint source(udp::v4(), port);
		sock.receive(boost::asio::buffer(data, 1024));

	} catch(std::exception &e) {
		std::cout << "An error occured: " << e.what() << std::endl;
	}

	std::string result(data);
	return result;
}
