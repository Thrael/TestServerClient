#ifndef TESTSERVER_COMMONS_H
#define TESTSERVER_COMMONS_H

#include <string>

const std::string factorials[] = {
        "1",                    //0
        "1",                    //1
        "2",                    //2
        "6",                    //3
        "24",                   //4
        "120",                  //5
        "720",                  //6
        "5040",                 //7
        "40320",                //8
        "362880",               //9
        "3628800",              //10
        "39916800",             //11
        "479001600",            //12
        "6227020800",           //13
        "87178291200",          //14
        "1307674368000",        //15
        "20922789888000",       //16
        "355687428096000",      //17
        "6402373705728000",     //18
        "121645100408832000",   //19
        "2432902008176640000",   //20

};

void splitPropertyLine(const std::string &line, std::string &key, std::string &value);
const std::string * factotialAsString(unsigned int f);

#endif //TESTSERVER_COMMONS_H
