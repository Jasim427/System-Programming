#include <iostream>
#include "db.hpp"

int main() {
    Database db;

    if (!db.connect()) {
        std::cout << "Database not available\n";
        return 1;
    }

    db.createTable();
    db.addStudent("Omar", "omar@email.com", 22);
    db.listStudents();
    db.updateStudent(1, 23);
    db.deleteStudent(1);

    return 0;
}
