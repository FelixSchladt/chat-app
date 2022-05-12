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
		udp::endpoint dest(boost::asio::ip::address::from_string("192.168.178.255"), PORT);
		sock.send_to(boost::asio::buffer(message, sizeof(std::string)), dest);
		sock.close();

	} catch(std::exception &e) {
		std::cout << "An error occured: " << e.what() << std::endl;
	}
}

int main() {
	send_udp("Hallo ihr alle, esst mein braodcast signal.");
}
