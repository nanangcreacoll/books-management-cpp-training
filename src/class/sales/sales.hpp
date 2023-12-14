#ifndef __MEMBER
#define __MEMBER

#include <string>
#include <iostream>
#include <sstream>
#include <mysql/mysql.h>

//struct
#include "dateStruct.hpp"

using namespace std;

class sales
{
    int invoice_id;
    int member_id;
    int book_id;
    int qty;
    int amount;
    date date_sales;

public:
    void add();
    void find_total_sales();
};

#endif