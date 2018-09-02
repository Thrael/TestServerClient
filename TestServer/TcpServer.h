#ifndef TESTSERVER_TCPSERVER_H
#define TESTSERVER_TCPSERVER_H


#include <string>

class TcpServer {
    int port;
    int timeout;
    int sessions;
    std::string loglevel;

public:
    TcpServer();
    explicit TcpServer(std::istream& configFile);
    void start();
private:
    void readConfig(std::istream& configFile);
    void splitConfLine(const std::string& line, std::string& key, std::string& value);
};


#endif //TESTSERVER_TCPSERVER_H
