#ifndef __DATABASE_SEEDERS
#define __DATABASE_SEEDERS

#include <iostream>
#include <string>
#include <sstream>
#include <mysql/mysql.h>
#include "../admin/admin.hpp"

using namespace std;

extern MYSQL *conn;
extern MYSQL_RES *res_set;
extern MYSQL_ROW row;
extern stringstream stmt;
extern const char* q;
extern string query;

class database_seeders
{
    admin admin_seed;
public:
    void admin_seeders();
    database_seeders();
};

#endif