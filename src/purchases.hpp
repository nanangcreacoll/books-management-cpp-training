#ifndef __PURCHASES
#define __PURCHASES

#include <string>
#include <iostream>
#include <sstream>
#include <mysql/mysql.h>

//struct
#include "dateStruct.hpp"

using namespace std;

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