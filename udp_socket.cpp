// Copyright 2022 Thomas Gingele (https://github.com/Ginthom)

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <string>
#include <iostream>

using boost::asio::ip::udp;

const int PORT = 5555;

void send_udp(std::string message) {
	try {
		boost::asio::io_context io_context;
		udp::resolver resolver(io_context);
		boost::array<char, 1> recv_buf;

		udp::endpoint remote_endpoint;
		udp::socket socket(io_context, udp::endpoint(udp::v4(), PORT));

		boost::asio::socket_base::broadcast option(true);
                socket.set_option(option);

		socket.send(boost::asio::buffer(message));
	} catch(std::exception &e) {
		std::cout << "An error occured: " << e.what() << std::endl;
	}
}

int main() {
	send_udp("Hallo Felix");
}
