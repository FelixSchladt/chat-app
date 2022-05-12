#include "udp_server.hpp"

int main() {
	udp_server udpsrv;

	udpsrv.broadcast("Ich bin der König des UDP", "192.168.255.255", 7373);
}
