#include <iostream>
 student3-week3-crud
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

 student3-week4-final


int main() {
    std::cout << "Student Information System - C++ App Initialized" << std::endl;
    return 0;
}

 main
 main
