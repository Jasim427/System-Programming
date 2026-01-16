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

void Database::createTable() {
    try {
        pqxx::connection c(conn_str);
        pqxx::work w(c);

        w.exec(R"(
            CREATE TABLE IF NOT EXISTS students (
                id SERIAL PRIMARY KEY,
                name VARCHAR(100),
                email VARCHAR(100),
                age INT
            );
        )");

        w.commit();
        std::cout << "Table created successfully\n";
    } catch (const std::exception& e) {
        std::cerr << "Create table error: " << e.what() << std::endl;
    }
}
void Database::addStudent(const std::string& name,
                           const std::string& email,
                           int age) {
    pqxx::connection c(conn_str);
    pqxx::work w(c);

    w.exec_params(
        "INSERT INTO students (name, email, age) VALUES ($1, $2, $3)",
        name, email, age
    );

    w.commit();
    std::cout << "Student added\n";
}

void Database::listStudents() {
    pqxx::connection c(conn_str);
    pqxx::work w(c);

    pqxx::result r = w.exec("SELECT * FROM students");

    for (const auto& row : r) {
        std::cout << row["id"].as<int>() << " | "
                  << row["name"].as<std::string>() << " | "
                  << row["email"].as<std::string>() << " | "
                  << row["age"].as<int>() << "\n";
    }
}

void Database::updateStudent(int id, int age) {
    pqxx::connection c(conn_str);
    pqxx::work w(c);

    w.exec_params(
        "UPDATE students SET age=$1 WHERE id=$2",
        age, id
    );

    w.commit();
    std::cout << "Student updated\n";
}

void Database::deleteStudent(int id) {
    pqxx::connection c(conn_str);
    pqxx::work w(c);

    w.exec_params(
        "DELETE FROM students WHERE id=$1",
        id
    );

    w.commit();
    std::cout << "Student deleted\n";
}
