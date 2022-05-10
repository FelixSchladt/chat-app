// Copyright 2022 Thomas Gingele (https://github.com/Ginthom)

#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <string>
#include <iostream>

using boost::asio::ip::udp;

void send_udp(std::string message) {
	try {
		boost::asio::io_context io_context;
		udp::resolver resolver(io_context);
		boost::array<char, 1> recv_buf;
		udp::endpoint remote_endpoint;
		udp::socket socket(io_context, udp::endpoint(udp::v4(), 13));
		socket.receive_from(boost::asio::buffer(recv_buf), remote_endpoint);
		boost::system::error_code ignored_error;
		socket.send_to(boost::asio::buffer(message), remote_endpoint, 0, ignored_error);
	} catch(std::exception &e) {
		std::cout << "An error occured: " << e.what() << std::endl;
	}
}

int main() {
	send_udp("Hallo Felix");
}
