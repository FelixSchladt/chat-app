#include "udp_client.hpp"

int main() {
	udp_client udpclt;
	while(true) {
		std::string message(udpclt.receive_broadcast(7373));
		std::cout << message << std::endl;
	}
}
