#include <iostream>
#include <fstream>
#include "main.h"

int main(int argc, char* argv[]) {

    TcpServer* server = initServer(argc, argv);
    server->start();
    delete server;


    Logger logger = Logger(loglevel::DEBUG);

    return 0;
}

TcpServer* initServer(int argc, char* argv[]){
    TcpServer* server = nullptr;
    if (argc > 1) {
        std::ifstream ifs;
        ifs.open(argv[1]);
        if (!ifs) {
            std::cerr << "ERR: Unable to open config file: "<<argv[1];
            exit(1);
        }

        server = new TcpServer(ifs);
        ifs.close();
    }else{
        server = new TcpServer();
    }
    return server;
}