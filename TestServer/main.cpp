#include <iostream>
#include <fstream>
#include <algorithm>
#include "main.h"
#include "Tester.h"

int main(int argc, char* argv[]) {

    cli_t commandLine = readCLI(argc,argv); //exit on error

    if(commandLine.role == "server") {
        auto server = std::unique_ptr<TcpServer>(new TcpServer());
        server->start();
    }else if(commandLine.role == "client") {
        auto client = std::unique_ptr<TcpClient>(new TcpClient());
        client->start();
    }else if(commandLine.role == "test") {
        auto tester = std::unique_ptr<Tester>(new Tester());
        tester->start();
    }else{
        std::cerr<<"Wrong arguments\n";
        printUsage();
        exit(1);
    }

    return 0;
}

cli_t readCLI(int argc, char* argv[]) {

    if(argc == 1 || argc >3){
        std::cerr<<"Wrong arguments"<<std::endl;
        printUsage();
        exit(1);
    }

    cli_t commanLine;

    std::string role(argv[1]);
    std::transform(role.begin(), role.end(), role.begin(), ::tolower);
    commanLine.role = role;

    if(argc == 3){
        commanLine.config = std::string(argv[2]);
    }

    return commanLine;
}

void printUsage(){
    std::cout   <<"\ttestServerClient <role> <config>\n"
                <<"\t\t<role>\t\t- indicates role to perform. mandatory\n"
                <<"\t\t\t\t  possible values: server, client, test\n"
                <<"\t\t<config>\t- optional path to config\n";
}


