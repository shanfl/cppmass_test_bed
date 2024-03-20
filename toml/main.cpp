#include <iostream>
#include "toml.h"
#include <fstream>
#include <iostream>
int main()
{
    std::ifstream ifs("config.toml");
    toml::ParseResult pr = toml::parse(ifs);

    if (!pr.valid()) 
    {
        std::cout << pr.errorReason << std::endl;
        return 0;
    }

    const toml::Value& v = pr.value;

    const toml::Value* server = v.find("server");
    const toml::Array& ar = server->as<toml::Array>();
    for (const toml::Value& v : ar) {
        std::string ip = v.find("ip")->as<std::string>();
        int port = v.find("port")->as<int>();
        std::cout << "ip:" << ip << ",port:" << port << std::endl;
    }
    return 0;
}