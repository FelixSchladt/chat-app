#include <iostream>
#include <boost/asio.hpp>
#include <thread>

using namespace boost::asio;
using ip::tcp;
using std::string;
using std::cout;
using std::cin;
using std::endl;

void tx() {
    boost::system::error_code error;
    while(true) {
        boost::asio::streambuf receive_buffer;
        boost::asio::read(socket, receive_buffer, boost::asio::transfer_all(), error);
        if( error && error != boost::asio::error::eof ) {
            cout << "receive failed: " << error.message() << endl;
        }
        else {
            const char *data = boost::asio::buffer_cast<const char *>(receive_buffer.data());
            cout << data << endl;
        }
    }

}

class client {

    public:
        client():io_service(nullptr), socket(nullptr) {

        }
        ~client(){
            delete io_service;
        }
        void open(string & address, int port) {
            io_service = new boost::asio::io_service;
            socket = new tcp::socket(io_service);
            socket->connect(tcp::endpoint( boost::asio::ip::address::from_string(address), port ));
            reader = new std::thread(tx);
            reader->join();
        }
        void close() {
        }


    private:
        boost::asio::io_service *io_service;
        tcp::socket *socket;
        std::thread *reader;
        void rx(){
            boost::system::error_code error;
            while(true){
                string msg;
                getline(cin, msg);
                boost::asio::write( socket, boost::asio::buffer(msg), error );
                if(error){
                    cout << "send failed: " << error.message() << endl;
                }
            }
        }
};

int main() {
    client client;
    client.open("127.0.0.1",5000);
    return 0;
}
