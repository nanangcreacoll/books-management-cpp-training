#ifndef __SALES
#define __SALES

#include <string>
#include <iostream>
#include <sstream>
#include <mysql/mysql.h>
#include <limits>

using namespace std;

//struct
#include "date.hpp"

extern MYSQL *conn;
extern MYSQL_RES *res_set;
extern MYSQL_ROW row;
extern stringstream stmt;
extern const char* q;
extern string query;

class sales
{
    int invoice_id; //primary key
    int member_id; //FK ref member(id)
    int book_id; //FK ref books(id)
    int qty;
    int amount;
    date date_sales;

public:
    void add();
    void find_total_sales();
};

#endif