#ifndef __ADMIN
#define __ADMIN

#include <iostream>
#include <mysql/mysql.h>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <string>
#include <sstream>

using namespace std;

extern MYSQL *conn;
extern MYSQL_RES *res_set;
extern MYSQL_ROW row;
extern stringstream stmt;
extern const char* q;
extern string query;

class admin
{
    int id; // primary key
    string username;
    string password;
private:
    bool is_logged_in = false;
public:
    string sha256(const string& str);
    void add();
    bool login(string input_username, string input_password);
    void logout();
    bool get_is_logged_in() const;
    string get_username() const;
};

#endif