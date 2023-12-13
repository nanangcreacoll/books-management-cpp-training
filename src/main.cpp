// Header Files
#include <iostream>
#include <string>
#include <mysql/mysql.h>
#include <sstream>
#include <conio.h>

// Definition
#define HOST "127.0.0.1"
#define MYSQL_PASS "creacoll"
#define DATABASE "book-management"
#define MYSQL_PORT 3306
#define PASSWORD "creacoll"

using namespace std;

//Global Variable
MYSQL *conn;
MYSQL_RES *res_set;
MYSQL_ROW row;
stringstream stmt;
const char* q;
string query;

typedef struct
{
    int date;
    int month;
    int year;
}date;

//classes
#include "books.hpp"

int main()
{
    cout << "hello world" << endl;
    return 0;
}
