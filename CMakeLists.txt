cmake_minimum_required(VERSION 3.10)
project(book-management-cpp-training)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenSSL REQUIRED)

find_path(MYSQL_INCLUDE_DIR mysql/mysql.h PATHS /usr/include/mysql)
find_library(MYSQL_LIBRARY NAMES mysqlclient PATHS /usr/lib/x86_64-linux-gnu)

if (NOT MYSQL_INCLUDE_DIR OR NOT MYSQL_LIBRARY)
    message(FATAL_ERROR "MySQL headers or library not found!")
endif()

file(GLOB_RECURSE SRC_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/**/*.cpp
)

file(GLOB_RECURSE SEEDER_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/database/seeders.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/database/database_seeders/*.cpp
)

add_executable(book-management
    ${SRC_FILES}
)

add_executable(database-seeders
    ${SEEDER_FILES}
)

set_target_properties(book-management PROPERTIES
    OUTPUT_NAME "book_management"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)

set_target_properties(database-seeders PROPERTIES
    OUTPUT_NAME "database_seeders"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)

target_link_libraries(book-management
    OpenSSL::Crypto
    ${MYSQL_LIBRARY}
)

target_link_libraries(database-seeders
    OpenSSL::Crypto
    ${MYSQL_LIBRARY}
)

target_include_directories(book-management PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
    ${MYSQL_INCLUDE_DIR}
)

target_include_directories(database-seeders PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/database
    ${CMAKE_CURRENT_SOURCE_DIR}/database/database_seeders
    ${MYSQL_INCLUDE_DIR}
)