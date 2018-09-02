#include <fstream>
#include <iostream>
#include "TcpServer.h"

TcpServer::TcpServer(){
    std::ifstream ifs;
    ifs.open("config.cfg");
    if(!ifs){
        std::cerr<<"ERR: Unable to open config file: config.cfg";
        exit(1);
    }
    readConfig(ifs);
    ifs.close();
}

TcpServer::TcpServer(std::istream& configFile) {
    readConfig(configFile);
}

void TcpServer::readConfig(std::istream& configFile) {

    std::string line, key, value;
    while(std::getline(configFile,line)){

        splitConfLine(line,key,value);
        if(key == "port"){
            this->port = std::strtol(value.data(),nullptr ,10);
        } else if(key == "timeout"){
            this->timeout = std::strtol(value.data(),nullptr ,10);
        } else if(key == "sessions"){
            this->sessions = std::strtol(value.data(),nullptr ,10);
        } else if(key == "loglevel"){
            this->loglevel = value;
        }
        key.erase();
        value.erase();
    }
}

void TcpServer::splitConfLine(const std::string &line, std::string& key, std::string& value) {
    std::string* writeTo = &key;
    for (char c : line){
        if(c ==' '){
            continue;
        } else if(c == '='){
            writeTo = &value;
        }else{
            writeTo->push_back(c);
        }
    }
}

void TcpServer::start() {
    std::cout<<"\tstarted\n";
}
