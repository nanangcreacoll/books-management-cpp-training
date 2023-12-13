#ifndef __BOOKS
#define __BOOKS

#include <string>
#include <iostream>
#include <sstream>
#include <mysql/mysql.h>

using namespace std;

extern MYSQL *conn;
extern MYSQL_RES *res_set;
extern MYSQL_ROW row;
extern stringstream stmt;
extern const char* q;
extern string query;

class books
{
    int id;
    string name;
    string author;
    int price;
    int qty;

public:
    void add();
    void update_price();
    void search();
    void update();
    void display();
};

#endif