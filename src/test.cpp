#include "udp_client.hpp"

int main(int argc, char** argv) {
	udp_client udpclt;

	udpclt.broadcast("Ich bin der König des UDP", argv[1], 7373);
	std::string message = udpclt.receive_broadcast(7373);
	std::cout << message << std::endl;
}
