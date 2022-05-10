cmake_minimum_required(VERSION 3.22)
project(chat_app)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(chat_app
        client.cpp
        server.cpp)
