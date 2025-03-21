#ifndef __EMPLOYEES
#define __EMPLOYEES

#include <string>
#include <iostream>
#include <sstream>
#include <mysql/mysql.h>

//struct
#include "date.hpp"

using namespace std;

extern MYSQL *conn;
extern MYSQL_RES *res_set;
extern MYSQL_ROW row;
extern stringstream stmt;
extern const char* q;
extern string query;

class employees
{
    int id; //primary key
    string name;
    string addr_line1;
    string addr_line2;
    string addr_city;
    string addr_state;
    long int phone_num;
    date date_of_joining;
    long int salary;
    string mgr_status; //check(T or F) def f

public:
    void add_emp();
    void search_emp();
    void assign_mgr_status();
    void display();
    void update_salary();
};


#endif