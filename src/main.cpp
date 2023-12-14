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

//struct
#include "dateStruct.hpp"

//classes
#include "class/books/books.hpp"
#include "class/suppliers/suppliers.hpp"
#include "class/purchases/purchases.hpp"
#include "class/members/members.hpp"


int main()
{
    cout << "hello world" << endl;
    return 0;
}
