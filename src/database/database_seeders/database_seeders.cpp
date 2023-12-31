#include "database_seeders.hpp"

string database_seeders::sha256(const string& str)
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


void database_seeders::admin_seed()
{
    stmt.str("");
    stmt << "SHOW TABLES LIKE 'admin';";
    query = stmt.str();
    q = query.c_str();
    if (mysql_query(conn, q)) 
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }

    res_set = mysql_store_result(conn);

    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "Admin table found. Drop Table." << endl;
        this_thread::sleep_for(chrono::seconds(2));
        
        stmt.str("");
        stmt << "DROP TABLE admin;";
        query = stmt.str();
        q = query.c_str();
        if (mysql_query(conn, q)) 
        {
            cout << "Query Error: " << mysql_error(conn) << endl;
            return;
        }
    }

    stmt.str("");
    stmt << "CREATE TABLE admin ( id INT NOT NULL AUTO_INCREMENT PRIMARY KEY, username VARCHAR(255) UNIQUE NOT NULL, password VARCHAR(255) NOT NULL );";
    query = stmt.str();
    q = query.c_str();
    if (mysql_query(conn, q)) 
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }

    stmt.str("");
    stmt << "INSERT INTO admin (username, password) VALUES ('" << username << "', '" << sha256(password) << "');";
    query = stmt.str();
    q = query.c_str();
    if (mysql_query(conn, q)) 
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }
}

database_seeders::database_seeders()
{
    cout << "DATABASE SEEDERS\n" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Admin Seeding ..." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    admin_seed();
}

database_seeders::~database_seeders()
{
    cout << "\nDatabase seeding completed successfully." << endl;
}

