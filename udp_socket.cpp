// Copyright 2022 Thomas Gingele (https://github.com/Ginthom)

#include <boost/asio.hpp>
#include <string>
#include <iostream>

using boost::asio::ip::udp;

const int PORT   = 5555;
const int REPEAT = 10;

void send_udp(std::string message) {
	try {
		boost::asio::io_service iosrv;
		udp::socket sock(iosrv, udp::endpoint(udp::v4(), PORT));
		sock.set_option(boost::asio::socket_base::broadcast(true));
		udp::endpoint dest(udp::v4(), PORT);

		for (;;) {
			std::string strbuf;
			udp::endpoint sender_endpoint;
			sock.receive_from(boost::asio::buffer(strbuf, strbuf.size()), sender_endpoint);
			sock.send_to(boost::asio::buffer(message, sizeof(std::string)), sender_endpoint);
		}

		sock.close();

	} catch(std::exception &e) {
		std::cout << "An error occured: " << e.what() << std::endl;
	}
}

int main() {
	send_udp("Hallo Felix");
}
