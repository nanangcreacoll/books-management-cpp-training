// Header Files
#include <iostream>
#include <string>
#include <mysql/mysql.h>
#include <sstream>
#include <conio.h>

// Definition
#define HOST "127.0.0.1"
#define MYSQL_USER "root"
#define MYSQL_PASS ""
#define DATABASE "book_management"
#define MYSQL_PORT 3306
#define PASSWORD 12345

using namespace std;

//Global Variable
MYSQL *conn;
MYSQL_RES *res_set;
MYSQL_ROW row;
stringstream stmt;
const char* q;
string query;

//classes
#include "class/books/books.hpp"
#include "class/suppliers/suppliers.hpp"
#include "class/purchases/purchases.hpp"
#include "class/members/members.hpp"
#include "class/sales/sales.hpp"

// Functions
void pass();
void book_menu();
void supplier_menu();
void purchase_menu();
void employee_menu();
void member_menu();
void sale_menu();

int main()
{
    pass();
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, HOST, MYSQL_USER, MYSQL_PASS, DATABASE, MYSQL_PORT, NULL ,0);

    cout << "Hello World!" << endl;

    return 0;
}

void pass()
{
    int num = 0;
    cout << "Password: ";

    for (int i = 0; i < 5; i++)
    {
        char pass_input = getch();
        //cin >> pass_input;
        num = num * 10 + (pass_input - '0');
        cout << "*";
    }
    
    if (num == PASSWORD)
    {
        cout << endl << endl << "Correct password!" << endl << endl;
        cout << "Press any key ...";
        getch();
    }
    else
    {
        cout << endl << endl << "Incorrect password!" << endl << endl;
        cout << "Press any key ...";
        getch();
        exit(1);
    }
    return;
}