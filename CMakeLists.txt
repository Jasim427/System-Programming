cmake_minimum_required(VERSION 3.10)
project(SIS_App)

set(CMAKE_CXX_STANDARD 17)

 student3-week3-crud
include_directories(include)

add_executable(sis_app
    src/main.cpp
    src/db.cpp
)

target_link_libraries(sis_app pqxx pq)


add_executable(sis_app src/main.cpp)
 main
