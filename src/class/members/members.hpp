#ifndef __MEMBERS
#define __MEMBERS

#include <string>
#include <iostream>
#include <sstream>
#include <mysql/mysql.h>


using namespace std;

//struct
#include "../../dateStruct.hpp"

extern MYSQL *conn;
extern MYSQL_RES *res_set;
extern MYSQL_ROW row;
extern stringstream stmt;
extern const char* q;
extern string query;

class members
{
    int id; //primary key
    string name;
    string addr_line1;
    string addr_line2;
    string addr_city;
    string addr_state;
    long int phone_num;
    date beg_date;
    date end_date;
    string valid;

public:
    void add_member();
    void refresh();
    void search_member();
};

#endif