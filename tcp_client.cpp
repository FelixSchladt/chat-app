#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

#define IP "127.0.0.1"
#define PORT 5555

using boost::asio::ip::tcp;

int main(int argc, char* argv[]) {
  try {
    if (argc != 2) {
      std::cerr << "Usage: client <host>" << std::endl;
      return 1;
    }

    boost::asio::io_context io_context;

    //tcp::resolver resolver(io_context);
    tcp::endpoint dest(boost::asio::ip::address::from_string(IP), PORT);

    tcp::socket socket(io_context);
    boost::asio::connect(socket, dest);

    for (;;) {
      boost::array<char, 128> buf;
      boost::system::error_code error;

      size_t len = socket.read_some(boost::asio::buffer(buf), error);

      if (error == boost::asio::error::eof)
        break; // Connection closed cleanly by peer.
      else if (error)
        throw boost::system::system_error(error); // Some other error.

      std::cout.write(buf.data(), len);
    }
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}
