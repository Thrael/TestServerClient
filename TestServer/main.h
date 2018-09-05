#ifndef TESTSERVER_MAIN_H
#define TESTSERVER_MAIN_H

#include "commons.h"
#include "TcpClient.h"
#include "TcpServer.h"
#include "Logger.h"

struct cli_t{
    std::string role = "";
    std::string config = "";
};

void printUsage();
cli_t readCLI(int argc, char* argv[]);



#endif //TESTSERVER_MAIN_H
