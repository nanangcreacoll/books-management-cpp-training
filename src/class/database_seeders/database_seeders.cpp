#include "database_seeders.hpp"

void database_seeders::admin_seeders()
{
    string username = "admin";
    string password = "password";

    string hash_password = admin_seed.sha256(password);

    stmt.str("");
    stmt << "SELECT COUNT(*) FROM admin WHERE username = '" << username << "';";
    query = stmt.str();
    q = query.c_str();

    mysql_query(conn, q);
    
    res_set = mysql_store_result(conn);
    
    row = mysql_fetch_row(res_set);
    
    if (row != NULL && row[0] != NULL)
    {
        int count = stoi(row[0]);
        mysql_free_result(res_set);
        
        if (count > 0)
        {
            return;
        }
    }

    stmt.str("");
    stmt << "INSERT INTO admin (username, password) VALUES ('" << username << "', '" << hash_password << "');";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
}

database_seeders::database_seeders()
{
    admin_seeders();
}
