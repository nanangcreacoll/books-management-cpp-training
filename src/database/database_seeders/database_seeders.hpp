#ifndef __DATABASE_SEEDERS
#define __DATABASE_SEEDERS

#include <iostream>
#include <string>
#include <sstream>
#include <mysql/mysql.h>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <thread>
#include <chrono>

using namespace std;

extern MYSQL *conn;
extern MYSQL_RES *res_set;
extern MYSQL_ROW row;
extern stringstream stmt;
extern const char* q;
extern string query;

class database_seeders
{
private:
    string username = "admin";
    string password = "password";

public:
    string sha256(const string&);
    void admin_seed();
    void books_seed();
    void suppliers_seed();
    void purchases_seed();
    void employees_seed();
    void members_seed();
    void sales_seed();
    database_seeders();
    ~database_seeders();
};

#endif