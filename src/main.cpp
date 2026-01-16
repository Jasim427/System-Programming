#include <iostream>
#include "db.hpp"

int main() {
    std::cout << "Starting SIS Application...\n";

    Database db;
    if (db.connect()) {
        std::cout << "Ready for database operations.\n";
    } else {
        std::cout << "Exiting application.\n";
    }

    return 0;
}

