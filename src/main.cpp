// Header Files
#include <iostream>
#include <string>
#include <mysql/mysql.h>
#include <sstream>
#include <conio.h>

// Definition
#define HOST "127.0.0.1"
#define MYSQL_USER "root"
#define MYSQL_PASS "creacoll"
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
void main_menu();
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

    if (conn)
    {
        while (1)
        {
            system("clear");
            main_menu();
        }
    }
    else
    {
        system("clear");
        cout << "Error while connecting to database." << endl << "Contact tech expert." << endl;
		getch();
    }
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

void main_menu()
{
    int c;

	cout << "*************************************************" << endl;
	cout << "         BOOK SHOP MANGEMENT SYSTEM" << endl;
	cout << "*************************************************" << endl;
	cout << "\t1. BOOKS" << endl;
	cout << "\t2. SUPPLIERS" << endl;
	cout << "\t3. PURCHASES" << endl;
	cout << "\t4. EMPLOYEES" << endl;
	cout << "\t5. MEMBERS" << endl;
	cout << "\t6. SALES" << endl;
	cout << "\t7. EXIT" << endl << endl << endl;
	cout << "Enter Your Choice: ";
	cin >> c;
	switch (c)
	{
		case 1:
			system("clear");
			book_menu();
			getch();
			break;
		case 2:
			system("clear");
			supplier_menu();
			getch();
			break;
		case 3:
			system("clear");
			purchase_menu();
			getch();
			break;
		case 4:
			system("clear");
			employee_menu();
			getch();
			break;
		case 5:
			system("clear");
			member_menu();
			getch();
			break;
		case 6:
			system("clear");
			sale_menu();
			getch();
			break;
		case 7:
			exit(1);
		default:
			system("clear");
			cout << "Wrong Input" << endl << endl << "Invalid input" << endl;
			getch();
			break;
	}
	return;
}

void book_menu() 
{

}

void supplier_menu()
{

}

void purchase_menu()
{

}

void employee_menu()
{

}

void member_menu()
{

}

void sale_menu()
{

}