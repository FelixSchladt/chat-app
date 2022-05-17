cmake_minimum_required(VERSION 3.22)

project(chat_app)

add_executable(server
        server.cpp)
add_executable(client
        client.cpp)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost COMPONENTS thread system REQUIRED)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(server ${Boost_LIBRARIES})
    target_link_libraries(client ${Boost_LIBRARIES})
endif()

if(WIN32)
    add_definitions(-DBOOST_THREAD_USE_LIB)
    target_link_libraries(server wsock32 ws2_32)
    target_link_libraries(client wsock32 ws2_32)
endif()

target_link_libraries(server ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(client ${CMAKE_THREAD_LIBS_INIT})