#include "db.hpp"
#include <cstdlib>
#include <iostream>

Database::Database() {
    const char* host = std::getenv("DB_HOST");
    const char* port = std::getenv("DB_PORT");
    const char* name = std::getenv("DB_NAME");
    const char* user = std::getenv("DB_USER");
    const char* pass = std::getenv("DB_PASSWORD");

    conn_str =
        "host=" + std::string(host ? host : "localhost") +
        " port=" + std::string(port ? port : "5432") +
        " dbname=" + std::string(name ? name : "sisdb") +
        " user=" + std::string(user ? user : "sisuser") +
        " password=" + std::string(pass ? pass : "sispass");
}

bool Database::connect() {
    try {
        pqxx::connection c(conn_str);
        std::cout << "Database connected successfully\n";
        return c.is_open();
    } catch (const std::exception& e) {
        std::cerr << "Database connection failed: " << e.what() << std::endl;
        return false;
    }
}

