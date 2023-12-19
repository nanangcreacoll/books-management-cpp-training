#ifndef __PURCHASES
#define __PURCHASES

#include <iostream>
#include <string>
#include <sstream>
#include <mysql/mysql.h>

//struct
#include "../../dateStruct.hpp"

using namespace std;

extern MYSQL *conn;
extern MYSQL_RES *res_set;
extern MYSQL_ROW row;
extern stringstream stmt;
extern const char* q;
extern string query;

class purchases
{
    int order_id;
    int book_id;
    int sup_id;
    int qty;
    date dt_ordered;
    int estim_deliv;
    char received;
    int inv;

public:
    void new_ord();
    void view();
    void mark_cancel();
    void mark_reciv();
};

#endif