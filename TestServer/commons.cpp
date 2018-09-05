#include "commons.h"

void splitPropertyLine(const std::string &line, std::string &key, std::string &value) {
    std::string* writeTo = &key;
    for (char c : line){
        if(c ==' '){
            continue;
        } else if(c == '='){
            writeTo = &value;
        }else{
            writeTo->push_back(static_cast<char>(std::tolower(c)));
        }
    }
}

const std::string *factotialAsString(unsigned int f) {
    const std::string* str = nullptr;
    if(f<20){
        str = &factorials[f];
    }
    return str;
}
