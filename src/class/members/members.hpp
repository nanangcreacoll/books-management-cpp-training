#ifndef __MEMBER
#define __MEMBER

#include <string>
#include <iostream>
#include <sstream>
#include <mysql/mysql.h>

//struct
#include "dateStruct.hpp"

using namespace std;

class members
{
    int id;
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