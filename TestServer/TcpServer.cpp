#include <fstream>
#include <iostream>
#include "TcpServer.h"
#include "commons.h"


TcpServer::TcpServer():TcpServer("server.cfg"){}
TcpServer::TcpServer(std::string configFile) {
    std::ifstream ifs;
    ifs.open(configFile);
    if(!ifs){
        std::cerr<<"ERR: Unable to open config file: "<<configFile;
        exit(1);
    }
    readConfig(ifs);
    ifs.close();
}
TcpServer::TcpServer(std::istream& configFile) {
    readConfig(configFile);
}

void TcpServer::readConfig(std::istream& configFile) {

    //TODO: validate values
    std::string line;
    while(std::getline(configFile,line)){

        std::string key,value;
        splitPropertyLine(line, key, value);
        if(key == "port"){
            this->port = std::strtol(value.data(),nullptr ,10);
        } else if(key == "timeout"){
            this->timeout = std::strtol(value.data(),nullptr ,10);
        } else if(key == "sessions"){
            this->sessions = std::strtol(value.data(),nullptr ,10);
        } else if(key == "loglevel"){
            this->loglevel = value;
        }
    }
}

void TcpServer::start() {
    std::cout   <<"\tstarted\n"
                <<"\tport: "<<this->port<<std::endl
                <<"\ttimeout: "<<this->timeout<<std::endl
                <<"\tsessions: "<<this->sessions<<std::endl
                <<"\tlogLevel: "<<this->loglevel;
}


