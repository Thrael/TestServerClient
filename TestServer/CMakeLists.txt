cmake_minimum_required(VERSION 3.12)
project(TestServer)

set(CMAKE_CXX_STANDARD 11)

add_executable(TestServer main.cpp TcpServer.cpp TcpServer.h main.h Logger.cpp Logger.h)