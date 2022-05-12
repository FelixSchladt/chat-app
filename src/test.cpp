#include "udp_server.hpp"

int main(int argc, char** argv) {
	udp_server udpsrv;

	udpsrv.broadcast("Ich bin der König des UDP", argv[1], 7373);
}
