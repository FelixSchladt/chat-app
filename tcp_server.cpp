#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main() {
    try {
        boost::asio::io_context io_context;
        
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 5556));


        for(;;) {
            tcp::socket socket(io_context);
            acceptor.accept(socket);
            
            boost::system::error_code ignored_error;
            std::string message = "TEST";

            boost::asio::streambuf buf;
            //boost::asio::read(socket, boost::asio::buffer(buf), ignored_error);
            while ( boost::asio::read(socket, buf, ignored_error)) {
                std::cout << "received: '" << &buf << "'\n";

            }
            boost::asio::write(socket, boost::asio::buffer(message), ignored_error);
        }
    
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;

    }
}
