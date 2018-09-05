#ifndef TESTSERVER_TCPSERVER_H
#define TESTSERVER_TCPSERVER_H


#include <string>

class TcpServer {
    int port;
    int timeout;
    int sessions;
    std::string loglevel;
    //TODO: Logger

public:
    TcpServer();
    explicit TcpServer(std::string configFile);
    explicit TcpServer(std::istream& configFile);
    void start();
private:
    void readConfig(std::istream& configFile);
};


#endif //TESTSERVER_TCPSERVER_H
