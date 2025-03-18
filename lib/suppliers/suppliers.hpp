#ifndef __SUPPLIERS
#define __SUPPLIERS

#include <string>
#include <iostream>
#include <sstream>
#include <mysql/mysql.h>

using namespace std;

extern stringstream stmt;
extern MYSQL *conn;
extern MYSQL_RES *res_set;
extern MYSQL_ROW row;
extern const char* q;
extern string query;

class suppliers
{
    int id; //primary key
    string name;
    long int phone_num;
    string addr_line1;
    string addr_line2;
    string addr_city;
    string addr_state;

public:
    void add_sup();
    void remove_supplier();
    void search_id();
    void display();
};

#endif