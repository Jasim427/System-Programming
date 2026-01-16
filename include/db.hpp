#pragma once
#include <pqxx/pqxx>
#include <string>

class Database {
public:
    Database();
    bool connect();

private:
    std::string conn_str;
};

