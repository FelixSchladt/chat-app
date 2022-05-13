#include "udp_client.hpp"

int main(int argc, char** argv) {
	udp_client udpclt;

	while(true) { 
		udpclt.broadcast("Ich bin der König des UDP", 6969, 7373);
		sleep(1);
	}
}
