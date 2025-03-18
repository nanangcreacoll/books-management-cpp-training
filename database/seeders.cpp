// Header Files
#include <iostream>
#include <string>
#include <mysql/mysql.h>
#include <sstream>
#include <thread>
#include <chrono>

#include "database.h"

using namespace std;

//Global Variable
MYSQL* conn;
MYSQL_RES* res_set;
MYSQL_ROW row;
stringstream stmt;
const char* q;
string query;

#include "database_seeders/database_seeders.hpp"

int main()
{
	system("clear");
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, HOST, MYSQL_USER, MYSQL_PASS, DATABASE, MYSQL_PORT, NULL ,0);
	
	if (conn)
	{
        database_seeders seeders;
		cout << "Admin seeding ..." << endl;
		// this_thread::sleep_for(chrono::seconds(2));
		seeders.admin_seed();

		cout << "Books seeding ..." << endl;
		// this_thread::sleep_for(chrono::seconds(2));
		seeders.books_seed();

		cout << "Suppliers seeding ..." << endl;
		// this_thread::sleep_for(chrono::seconds(2));
		seeders.suppliers_seed();

		cout << "Members seeding ..." << endl;
		// this_thread::sleep_for(chrono::seconds(2));
		seeders.members_seed();
		
		cout << "Employees seeding ..." << endl;
		// this_thread::sleep_for(chrono::seconds(2));
		seeders.employees_seed();

		cout << "Purchases seeding ..." << endl;
		// this_thread::sleep_for(chrono::seconds(2));
		seeders.purchases_seed();

		cout << "Sales seeding ..." << endl;
		// this_thread::sleep_for(chrono::seconds(2));
		seeders.sales_seed();
	}
	else
	{
		system("clear");
		cout << "Error while connecting to database." << endl << "Contact tech expert." << endl;
		cin.get();
    }
	return 0;
}
