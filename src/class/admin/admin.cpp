#include "admin.hpp"

string admin::sha256(const string& str)
{
    EVP_MD_CTX* mdctx = EVP_MD_CTX_new();
    const EVP_MD* md = EVP_sha256();
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int hashLen;

    EVP_DigestInit(mdctx, md);
    EVP_DigestUpdate(mdctx, str.c_str(), str.size());
    EVP_DigestFinal_ex(mdctx, hash, &hashLen);
    EVP_MD_CTX_free(mdctx);

    string ss;
    char buf[3];
    for (unsigned int i = 0; i < hashLen; ++i) {
        snprintf(buf, sizeof(buf), "%02x", hash[i]);
        ss += buf;
    }

    return ss;
}

bool admin::login(const char* input_username, const char* input_password)
{
    username = input_username;
    password = input_password;

    stmt.str("");
    stmt << "SELECT username, password FROM admin WHERE username = '" << username << "';";
    query = stmt.str();
    q = query.c_str();
    
    if (mysql_query(conn, q)) {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return false;
    }
    
    if (!(res_set = mysql_store_result(conn))) {
        cout << "Result set is NULL." << endl;
        return false;
    }
    
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        string stored_password = row[1];

        string hash_password = admin::sha256(password);
        is_logged_in = (hash_password == stored_password);
        return is_logged_in;
    }
    else
    {
        mysql_free_result(res_set);
        return false;
    }
}

void admin::add()
{
    string input_username;
    string input_password;

    cout << "\nAdd Admin" << endl;
    cout << "\tUsername: ";
    cin >> input_username;
    cout << "\tPassword: ";
    cin >> input_username;

    string hash_password = admin::sha256(input_password);
    
    stmt.str("");
    stmt << "SELECT username FROM admin WHERE username = '" << input_username << "';";
    query = stmt.str();
    q = query.c_str();

    if (mysql_query(conn, q)) {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }

    res_set = mysql_store_result(conn);

    if (!res_set) {
        cout << "Result set is NULL." << endl;
        return;
    }
    
    if (mysql_num_rows(res_set) > 0) 
    {
        cout << endl << endl << "Admin already exist." << endl << endl << endl;
    }
    else
    {
        stmt.str("");
        stmt << "INSERT INTO admin (username, password) VALUES ('" << input_username << "', '" << hash_password << "');";
        query = stmt.str();
        q = query.c_str();
        mysql_query(conn, q);

        cout << endl << endl << "Admin added successfully." << endl << endl << endl;
    }
    mysql_free_result(res_set);
}

void admin::logout()
{
    is_logged_in = false;
    cout << "You have logout." << endl;
}

bool admin::get_is_logged_in() const
{
    return is_logged_in;
}

string admin::get_username() const
{
    return username;
}