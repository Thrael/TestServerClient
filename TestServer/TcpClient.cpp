#include <iostream>
#include <fstream>
#include "TcpClient.h"
#include "commons.h"

TcpClient::TcpClient():TcpClient("client.cfg"){}
TcpClient::TcpClient(std::string configFile) {
    std::ifstream ifs;
    ifs.open(configFile);
    if(!ifs){
        std::cerr<<"ERR: Unable to open config file: "<<configFile;
        exit(1);
    }
    readConfig(ifs);
    ifs.close();
}
TcpClient::TcpClient(std::istream& configFile) {
    readConfig(configFile);
}

void TcpClient::readConfig(std::istream& configFile) {

    //TODO: validate values
    std::string line;
    while(std::getline(configFile,line)){

        std::string key,value;
        splitPropertyLine(line, key, value);
        if(key == "port"){
            this->port = std::strtol(value.data(),nullptr ,10);
        } else if(key == "remote"){
            this->remote = value;
        } else if(key == "loglevel"){
            this->loglevel = value;
        }
    }


}


void TcpClient::start() {
    std::cout   <<"\tstarted\n"
                <<"\tport: "<<this->port<<std::endl
                <<"\tremote: "<<this->remote<<std::endl
                <<"\tlogLevel: "<<this->loglevel;

}


