// Copyright 2022 Thomas Gingele (https://github.com/Ginthom)

#include "udp_client.hpp"

using boost::asio::ip::udp;

void udp_client::broadcast(std::string message, int from_port, int to_port) {
	try {
		boost::asio::io_service iosrv;
		udp::socket sock(iosrv, udp::endpoint(udp::v4(), from_port));
		sock.set_option(boost::asio::socket_base::broadcast(true));
		boost::asio::ip::multicast::hops hop(99);
		sock.set_option(hop);
		boost::asio::socket_base::reuse_address reuse(true);
		sock.set_option(reuse);
		udp::endpoint dest(boost::asio::ip::address_v4::broadcast(), to_port);
		sock.send_to(boost::asio::buffer(message, message.size()), dest);
		sock.close();

	} catch(std::exception &e) {
		std::cout << "An error occured: " << e.what() << std::endl;
	}
}

std::string udp_client::receive_broadcast(int port) {
	char data[1024];
	for (int i = 0; i < 1024; i++) {
		data[i] = '\0';
	} 
	try {
		boost::asio::io_service iosrv;
		udp::socket sock(iosrv, udp::endpoint(udp::v4(), port));
		udp::endpoint source(udp::v4(), port);
		boost::asio::socket_base::reuse_address reuse(true);
		sock.set_option(reuse);
		sock.receive(boost::asio::buffer(data, 1024));

	} catch(std::exception &e) {
		std::cout << "An error occured: " << e.what() << std::endl;
	}

	std::string result(data);
	return result;
}
