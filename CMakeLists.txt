cmake_minimum_required(VERSION 3.22)
project(chat_app)

set(CMAKE_CXX_STANDARD 14)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

include_directories(.)

add_executable(chat_app
        client.cpp
        server.cpp)

find_package(Boost)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(chat_app ${Boost_LIBRARIES})
endif()

if(WIN32)
    add_definitions(-DBOOST_THREAD_USE_LIB)
    target_link_libraries(chat_app wsock32 ws2_32)
endif()

target_link_libraries(chat_app ${CMAKE_THREAD_LIBS_INIT})