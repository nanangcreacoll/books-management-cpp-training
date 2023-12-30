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

//classes
#include "class/books/books.hpp"
#include "class/suppliers/suppliers.hpp"
#include "class/purchases/purchases.hpp"
#include "class/employees/employees.hpp"
#include "class/members/members.hpp"
#include "class/sales/sales.hpp"
#include "class/admin/admin.hpp"

//Global Variable
MYSQL* conn;
MYSQL_RES* res_set;
MYSQL_ROW row;
stringstream stmt;
const char* q;
string query;
admin administrator;

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

	cout << "*************************************************" << endl;
	cout << "                 LOGIN MENU" << endl;
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

		administrator.login(input_username.c_str(), input_password.c_str());

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
		exit(0);
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

	cout << "Admin: " << administrator.get_username() << endl;
	cout << "*************************************************" << endl;
	cout << "         BOOK SHOP MANGEMENT SYSTEM" << endl;
	cout << "*************************************************" << endl;
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
			cin.clear();
			cin.get();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("clear");
			login_menu();
			break;
		case 8:
			exit(0);
		default:
			cout << "\nWrong Input" << endl << endl << "Invalid input" << endl;
			cin.clear();
			cin.get();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
	}
	return;
}

void book_menu() 
{
	int c;
	books b;

	cout << "Admin: " << administrator.get_username() << endl;
	cout << "*************************************************" << endl;
	cout << "                  BOOK MENU" << endl;
	cout << "*************************************************" << endl;
	cout << "\t1. ADD" << endl;
	cout << "\t2. UPDATE PRICE" << endl;
	cout << "\t3. SEARCH" << endl;
	cout << "\t4. UPDATE STATUS" << endl;
	cout << "\t5. DISPLAY ALL" << endl;
	cout << "\t6. RETURN TO MAIN MENU" << endl << endl << endl;
	cout << "Enter Your Choice: ";
	cin >> c;
	switch (c)
	{
		case 1:
			b.add();
			break;
		case 2:
			b.update_price();
			cin.get();
			break;
		case 3:
			b.search();
			cin.get();
			break;
		case 4:
			b.update();
			cin.get();
			break;
		case 5:
			b.display();
			cin.get();
			break;
		case 6:
			return;
			break;
		default:
			cout << "\nWrong Input" << endl << "Invalid input";
			cin.clear();
			cin.get();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
	}
	return;
}

void supplier_menu()
{
	int c;
	suppliers s;

	cout << "Admin: " << administrator.get_username() << endl;
	cout << "*************************************************" << endl;
	cout << "                SUPPLIER MENU" << endl;
	cout << "*************************************************" << endl;
	cout << "\t1. ADD" << endl;
	cout << "\t2. REMOVE" << endl;
	cout << "\t3. SEARCH" << endl;
	cout << "\t4. DISPLAY ALL" << endl;
	cout << "\t5. RETURN TO MAIN MENU" << endl << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
		case 1:
			s.add_sup();
			break;
		case 2:
			s.remove_supplier();
			cin.get();
			break;
		case 3:
			s.search_id();
			cin.get();
			break;
		case 4:
			s.display();
			cin.get();
			break;
		case 5:
			return;
			break;
		default:
			cout << "Wrong Input" << endl << "Invalid input";
			cin.clear();
			cin.get();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
	}

}

void purchase_menu()
{
	int c;
	purchases p;

	cout << "Admin: " << administrator.get_username() << endl;
	cout << "*************************************************" << endl;
	cout << "                PURCHASES MENU" << endl;
	cout << "*************************************************" << endl;
	cout << "   1. New Order" << endl;
	cout << "   2. View All" << endl;
	cout << "   3. Cancel Order" << endl;
	cout << "   4. Recieved Order" << endl;
	cout << "   5. RETURN TO MAIN MENU" << endl << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
		case 1:
			p.new_ord();
			cin.get();
			break;
		case 2:
			p.view();
			cin.get();
			break;
		case 3:
			p.mark_cancel();
			cin.get();
			break;
		case 4:
			p.mark_reciv();
			cin.get();
			break;
		case 5:
			return;
			break;
		default:
			cout << "Wrong Input" << endl << "Invalid input";
			cin.clear();
			cin.get();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
	}
}

void employee_menu()
{
	int c;
	employees e;

	cout << "Admin: " << administrator.get_username() << endl;
	cout << "*************************************************" << endl;
	cout << "                 EMPLOYEE MENU" << endl;
	cout << "*************************************************" << endl;
	cout << "\t1. New Employee" << endl;
	cout << "\t2. Search Employee" << endl;
	cout << "\t3. Assign Manager" << endl;
	cout << "\t4. View All" << endl;
	cout << "\t5. Update Salary" << endl;
	cout << "\t6. RETURN TO MAIN MENU" << endl << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
		case 1:
			e.add_emp();
			cin.get();
			break;
		case 2:
			e.search_emp();
			cin.get();
			break;
		case 3:
			e.assign_mgr_status();
			cin.get();
			break;
		case 4:
			e.display();
			cin.get();
			break;
		case 5:
			e.update_salary();
			cin.get();
			break;
		case 6:
			return;
			break;
		default:
			cout << "Wrong Input" << endl << "Invalid input";
			cin.clear();
			cin.get();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
	}
}

void member_menu()
{
	int c;
	members m;
	m.refresh();

	cout << "Admin: " << administrator.get_username() << endl;
	cout << "*************************************************" << endl;
	cout << "                 MEMBERS MENU" << endl;
	cout << "*************************************************" << endl;
	cout << "\t1. New Member" << endl;
	cout << "\t2. Search Member" << endl;
	cout << "\t3. RETURN TO MAIN MENU" << endl << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
		case 1:
			m.add_member();
			break;
		case 2:
			m.search_member();
			cin.get();
			break;
		case 3:
			return;
			break;
		default:
			cout << "Wrong Input" << endl << "Invalid input";
			cin.clear();
			cin.get();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
	}
}

void sale_menu()
{
	int c;
	sales s;

	cout << "Admin: " << administrator.get_username() << endl;
	cout << "*************************************************" << endl;
	cout << "                 SALES MENU" << endl;
	cout << "*************************************************" << endl;
	cout << "\t1. Add New Bill" << endl;
	cout << "\t2. Total Sales Of The Year" << endl;
	cout << "\t3. RETURN TO MAIN MENU" << endl << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
		case 1:
			s.add();
			cin.get();
			break;
		case 2:
			s.find_total_sales();
			cin.get();
			break;
		case 3:
			return;
		default:
			cout << "Wrong Input" << endl << "Invalid input";
			cin.clear();
			cin.get();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
	}
}