#ifndef TESTSERVER_TCPCLIENT_H
#define TESTSERVER_TCPCLIENT_H


#include <string>

class TcpClient {
    std::string remote;
    int port;
    std::string loglevel;
    //TODO: Logger

public:
    TcpClient();
    explicit TcpClient(std::string configFile);
    explicit TcpClient(std::istream& configFile);
    void start();
private:
    void readConfig(std::istream& configFile);
};


#endif //TESTSERVER_TCPCLIENT_H
