#pragma once
#include <pqxx/pqxx>
#include <string>

class Database {
public:
    Database();
    bool connect();

    void createTable();
    void addStudent(const std::string& name,
                    const std::string& email,
                    int age);
    void listStudents();
    void updateStudent(int id, int age);
    void deleteStudent(int id);

private:
    std::string conn_str;
};

