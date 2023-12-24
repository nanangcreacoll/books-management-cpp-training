// Header Files
#include <iostream>
#include <string>
#include <mysql/mysql.h>
#include <sstream>
#include <termios.h>
#include <unistd.h>

// Definition
#define HOST "127.0.0.1"
#define MYSQL_USER "root"
#define MYSQL_PASS "creacoll"
#define DATABASE "book_management"
#define MYSQL_PORT 3306

using namespace std;

//Global Variable
MYSQL* conn;
MYSQL_RES* res_set;
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
#include "class/admin/admin.hpp"
#include "class/database_seeders/database_seeders.hpp"

// Functions
string get_password();
void login_menu();
void main_menu();
void book_menu();
void supplier_menu();
void purchase_menu();
void employee_menu();
void member_menu();
void sale_menu();

int main()
{
	system("clear");
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, HOST, MYSQL_USER, MYSQL_PASS, DATABASE, MYSQL_PORT, NULL ,0);

    if (conn)
    {
		database_seeders seeding;
		login_menu();

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
		cin.get();
    }
    return 0;
}

string get_password() {
	cin.get();
    string password;

    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
	termios newt = oldt;
    newt.c_lflag &= ~ECHO;

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    getline(cin, password);
	
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &oldt);

    return password;
}

void login_menu()
{
	int c;
	string input_username;
	string input_password;

	admin administrator;

	cout << "*************************************************" << endl;
	cout << "         			LOGIN MENU" << endl;
	cout << "*************************************************" << endl;
	cout << "\t1. LOGIN" << endl;
	cout << "\t2. ADD ADMIN" << endl;
	cout << "\t3. EXIT" << endl << endl << endl;
	cout << "Enter your choice: ";
	cin >> c;

	switch (c)
	{
	case 1:
		system("clear");
		cout << "\tUsername: ";
		cin >> input_username;
		cout << "\tPassword: ";
		input_password = get_password();

		administrator.login(input_username, input_password);

		if (bool logged_in = administrator.get_is_logged_in())
		{
			cout << endl << endl << "Valid login." << endl << endl;
			cout << "Press any key ...";
    		cin.get();
			break;
		}
		else
		{
			cout << endl << endl << "Username or password is not valid." << endl << endl;
			cout << "Press any key ...";
    		cin.get();
			system("clear");
			login_menu();
			break;
		}
	case 2:
		system("clear");
		cout << "\tUsername: ";
		cin >> input_username;
		cout << "\tPassword: ";
		input_password = get_password();

		administrator.login(input_username, input_password);

		if (bool logged_in = administrator.get_is_logged_in())
		{
			cout << endl << endl << "Valid login." << endl << endl;
			cout << "Press any key ...";
			cin.get();
			system("clear");
			administrator.add();
			cin.clear();
    		cin.ignore(numeric_limits<streamsize>::max(), '\n');
    		cin.get();
			system("clear");
			administrator.logout();
			cin.get();
			system("clear");
			login_menu();
			break;
		}
		else
		{
			cout << endl << endl << "Username or password is not valid." << endl << endl;
			cout << "Press any key ...";
    		cin.get();
			system("clear");
			login_menu();
			break;
		}
	case 3:
		exit(1);
	default:
		system("clear");
		cout << "Wrong Input" << endl << endl << "Invalid input" << endl;
		cin.clear();
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
    	cin.get();
		system("clear");
		login_menu();
		break;
	}
}

void main_menu()
{
    int c;

	admin administrator;
	string admin_username = administrator.get_username();

	cout << "*************************************************" << endl;
	cout << "         BOOK SHOP MANGEMENT SYSTEM" << endl;
	cout << "*************************************************" << endl;
	cout << admin_username << endl;
	cout << "\t1. BOOKS" << endl;
	cout << "\t2. SUPPLIERS" << endl;
	cout << "\t3. PURCHASES" << endl;
	cout << "\t4. EMPLOYEES" << endl;
	cout << "\t5. MEMBERS" << endl;
	cout << "\t6. SALES" << endl;
	cout << "\t7. LOGOUT" << endl;
	cout << "\t8. EXIT" << endl << endl;
	cout << "Enter Your Choice: ";
	cin >> c;
	switch (c)
	{
		case 1:
			system("clear");
			book_menu();
    		cin.get();
			break;
		case 2:
			system("clear");
			supplier_menu();
    		cin.get();
			break;
		case 3:
			system("clear");
			purchase_menu();
    		cin.get();
			break;
		case 4:
			system("clear");
			employee_menu();
    		cin.get();
			break;
		case 5:
			system("clear");
			member_menu();
    		cin.get();
			break;
		case 6:
			system("clear");
			sale_menu();
    		cin.get();
			break;
		case 7:
			system("clear");
			administrator.logout();
    		cin.get();
			system("clear");
			login_menu();
			break;
		case 8:
			exit(1);
		default:
			system("clear");
			cout << "Wrong Input" << endl << endl << "Invalid input" << endl;
    		cin.get();
			break;
	}
	return;
}

void book_menu() 
{
	int c;
	books b;
	cout << "*************************************************" << endl;
	cout << "                  BOOK MENU" << endl;
	cout << "*************************************************" << endl;
	cout << "   1. ADD" << endl;
	cout << "   2. UPDATE PRICE" << endl;
	cout << "   3. SEARCH" << endl;
	cout << "   4. UPDATE STATUS" << endl;
	cout << "   5. DISPLAY ALL" << endl;
	cout << "   6. RETURN TO MAIN MENU" << endl << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
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