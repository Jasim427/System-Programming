#include <iostream>
#include "db.hpp"

int main() {
    std::cout << "Starting Student Information System...\n";

    Database db;
    if (!db.connect()) {
        std::cerr << "Database connection failed\n";
        return 1;
    }

    std::cout << "Database connected. Application ready.\n";
    return 0;
}

