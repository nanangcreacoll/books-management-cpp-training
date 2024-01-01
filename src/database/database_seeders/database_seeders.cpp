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
        cout << "Admin table found. Drop table.\n" << endl;
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
    stmt << "CREATE TABLE admin ( " 
        << "id INT NOT NULL AUTO_INCREMENT PRIMARY KEY, "
        << "username VARCHAR(255) UNIQUE NOT NULL, "
        << "password VARCHAR(255) NOT NULL )"
        << ";";
    query = stmt.str();
    q = query.c_str();
    if (mysql_query(conn, q)) 
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }

    stmt.str("");
    stmt << "INSERT INTO admin ("
        << "username, "
        << "password) " 
        << "VALUES ('" << username << "', '" << sha256(password) << "')"
        << ";";
    query = stmt.str();
    q = query.c_str();
    if (mysql_query(conn, q)) 
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }
}

void database_seeders::books_seed()
{
    stmt.str("");
    stmt << "SHOW TABLES LIKE 'books';";
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
        cout << "Books table found. Drop table.\n" << endl;
        this_thread::sleep_for(chrono::seconds(2));

        stmt.str("");
        stmt << "SET foreign_key_checks = 0;";
        query = stmt.str();
        q = query.c_str();
        if (mysql_query(conn, q)) 
        {
            cout << "Query Error: " << mysql_error(conn) << endl;
            return;
        }

        stmt.str("");
        stmt << "DROP TABLE books;";
        query = stmt.str();
        q = query.c_str();
        if (mysql_query(conn, q)) 
        {
            cout << "Query Error: " << mysql_error(conn) << endl;
            return;
        }
        
        stmt.str("");
        stmt << "SET foreign_key_checks = 1;";
        query = stmt.str();
        q = query.c_str();
        if (mysql_query(conn, q)) 
        {
            cout << "Query Error: " << mysql_error(conn) << endl;
            return;
        }
    }

    stmt.str("");
    stmt << "CREATE TABLE books ( "
        << "id INT NOT NULL AUTO_INCREMENT PRIMARY KEY, "
        << "name VARCHAR(255), "
        << "author VARCHAR(255), "
        << "price INT, "
        << "qty INT )"
        << ";";
    query = stmt.str();
    q = query.c_str();
    if (mysql_query(conn, q))
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }

    stmt.str("");
    stmt << "INSERT INTO books(name, author, price, qty) "
        << "VALUES "
        << "(\"" << book_name1 << "\", \"" << book_author1 << "\", " << book_price1 << ", " << book_qty1 << "), "
        << "(\"" << book_name2 << "\", \"" << book_author2 << "\", " << book_price2 << ", " << book_qty2 << "), "
        << "(\"" << book_name3 << "\", \"" << book_author3 << "\", " << book_price3 << ", " << book_qty3 << "), "
        << "(\"" << book_name4 << "\", \"" << book_author4 << "\", " << book_price4 << ", " << book_qty4 << ") "
        << ";";
    query = stmt.str();
    q = query.c_str();
    if (mysql_query(conn, q))
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }
}

void database_seeders::suppliers_seed()
{
    stmt.str("");
    stmt << "SHOW TABLES LIKE 'suppliers';";
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
        cout << "Suppliers table found. Drop table.\n" << endl;
        this_thread::sleep_for(chrono::seconds(2));
        
        stmt.str("");
        stmt << "SET foreign_key_checks = 0;";
        query = stmt.str();
        q = query.c_str();
        if (mysql_query(conn, q)) 
        {
            cout << "Query Error: " << mysql_error(conn) << endl;
            return;
        }

        stmt.str("");
        stmt << "DROP TABLE suppliers;";
        query = stmt.str();
        q = query.c_str();
        if (mysql_query(conn, q)) 
        {
            cout << "Query Error: " << mysql_error(conn) << endl;
            return;
        }

        stmt.str("");
        stmt << "SET foreign_key_checks = 1;";
        query = stmt.str();
        q = query.c_str();
        if (mysql_query(conn, q)) 
        {
            cout << "Query Error: " << mysql_error(conn) << endl;
            return;
        }
    }

    stmt.str("");
    stmt << "CREATE TABLE suppliers ( "
        << "id INT NOT NULL AUTO_INCREMENT PRIMARY KEY, "
        << "name VARCHAR(255), "
        << "phone_num BIGINT, "
        << "addr_line1 VARCHAR(255), "
        << "addr_line2 VARCHAR(255), "
        << "addr_city VARCHAR(255), "
        << "addr_state VARCHAR(255) )"
        << ";";
    query = stmt.str();
    q = query.c_str();
    if (mysql_query(conn, q))
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }

    stmt.str("");
    stmt << "INSERT INTO suppliers(name, phone_num, addr_line1, addr_line2, addr_city, addr_state) "
        << "VALUES "
        << "(\""<< supplier1_name <<"\", LPAD(FLOOR(RAND() * 999999999999), 12, '0'), \""<< supplier1_addr_line1 <<"\", \""<< supplier1_addr_line2 <<"\", \""<< supplier1_addr_city <<"\", \""<< supplier1_addr_city <<"\"), "
        << "(\""<< supplier2_name <<"\", LPAD(FLOOR(RAND() * 999999999999), 12, '0'), \""<< supplier2_addr_line1 <<"\", \""<< supplier2_addr_line2 <<"\", \""<< supplier2_addr_city <<"\", \""<< supplier2_addr_city <<"\")"
        << ";";
    query = stmt.str();
    q = query.c_str();
    if (mysql_query(conn, q))
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }
}

void database_seeders::employees_seed()
{
    stmt.str("");
    stmt << "SHOW TABLES LIKE 'employees';";
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
        cout << "Employees table found. Drop table.\n" << endl;
        this_thread::sleep_for(chrono::seconds(2));

        stmt.str("");
        stmt << "DROP TABLE employees;";
        query = stmt.str();
        q = query.c_str();
        if (mysql_query(conn, q)) 
        {
            cout << "Query Error: " << mysql_error(conn) << endl;
            return;
        }
    }

    stmt.str("");
    stmt << "CREATE TABLE employees ( "
        << "id INT NOT NULL AUTO_INCREMENT PRIMARY KEY, "
        << "name VARCHAR(255), "
        << "addr_line1 VARCHAR(255), "
        << "addr_line2 VARCHAR(255), "
        << "addr_city VARCHAR(255), "
        << "addr_state VARCHAR(255), "
        << "phone_num BIGINT, "
        << "date_of_joining DATE, "
        << "salary BIGINT, "
        << "mgr_status VARCHAR(255) )"
        << ";";
    query = stmt.str();
    q = query.c_str();
    if (mysql_query(conn, q))
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }

    stmt.str("");
    stmt << "INSERT INTO employees(name, addr_line1, addr_line2, addr_city, addr_state, phone_num, date_of_joining, salary, mgr_status) "
        << "VALUES "
        << "(\""<< employee1_name <<"\", \""<< employee1_addr_line1 <<"\", \""<< employee1_addr_line2 <<"\", \""<< employee1_addr_city <<"\", \""<< employee1_addr_city <<"\", LPAD(FLOOR(RAND() * 999999999999), 12, '0'), CURDATE(), "<< employee1_salary <<", '"<< employee1_mgr_status <<"'), "
        << "(\""<< employee2_name <<"\", \""<< employee2_addr_line1 <<"\", \""<< employee2_addr_line2 <<"\", \""<< employee2_addr_city <<"\", \""<< employee2_addr_city <<"\", LPAD(FLOOR(RAND() * 999999999999), 12, '0'), CURDATE(), "<< employee2_salary <<", '"<< employee2_mgr_status <<"'), "
        << "(\""<< employee3_name <<"\", \""<< employee3_addr_line1 <<"\", \""<< employee3_addr_line2 <<"\", \""<< employee3_addr_city <<"\", \""<< employee3_addr_city <<"\", LPAD(FLOOR(RAND() * 999999999999), 12, '0'), CURDATE(), "<< employee3_salary <<", '"<< employee3_mgr_status <<"') "
        << ";";
    query = stmt.str();
    q = query.c_str();
    if (mysql_query(conn, q))
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }
}

void database_seeders::purchases_seed()
{
    stmt.str("");
    stmt << "SHOW TABLES LIKE 'purchases';";
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
        cout << "Purchases table found. Drop table.\n" << endl;
        this_thread::sleep_for(chrono::seconds(2));

        stmt.str("");
        stmt << "DROP TABLE purchases;";
        query = stmt.str();
        q = query.c_str();
        if (mysql_query(conn, q)) 
        {
            cout << "Query Error: " << mysql_error(conn) << endl;
            return;
        }
    }

    stmt.str("");
    stmt << "CREATE TABLE purchases ( "
        << "order_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY, "
        << "book_id INT, "
        << "sup_id INT, "
        << "qty INT, "
        << "dt_ordered DATE, "
        << "estim_deliv DATE, "
        << "received CHAR, "
        << "inv INT, "
        << "FOREIGN KEY (book_id) REFERENCES books(id), "
        << "FOREIGN KEY (sup_id) REFERENCES suppliers(id) )"
        << ";";
    query = stmt.str();
    q = query.c_str();
    if (mysql_query(conn, q))
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }

    stmt.str("");
    stmt << "INSERT INTO purchases(book_id, sup_id, qty, dt_ordered, estim_deliv, received) "
        << "VALUES "
        << "("<< purchases1_book_id <<", "<< purchases1_sup_id <<", "<< purchases1_qty <<", CURDATE(), DATE_ADD(CURDATE(), INTERVAL "<< purchases1_estim_deliv << " DAY), '"<< purchases1_received <<"'), "
        << "("<< purchases2_book_id <<", "<< purchases2_sup_id <<", "<< purchases2_qty <<", CURDATE(), DATE_ADD(CURDATE(), INTERVAL "<< purchases2_estim_deliv << " DAY), '"<< purchases2_received <<"'), "
        << "("<< purchases3_book_id <<", "<< purchases3_sup_id <<", "<< purchases3_qty <<", CURDATE(), DATE_ADD(CURDATE(), INTERVAL "<< purchases3_estim_deliv << " DAY), '"<< purchases3_received <<"') "
        << ";";
    query = stmt.str();
    q = query.c_str();
    if (mysql_query(conn, q))
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }
}

void database_seeders::members_seed()
{
    stmt.str("");
    stmt << "SHOW TABLES LIKE 'members';";
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
        cout << "Members table found. Drop table.\n" << endl;
        this_thread::sleep_for(chrono::seconds(2));

        stmt.str("");
        stmt << "SET foreign_key_checks = 0;";
        query = stmt.str();
        q = query.c_str();
        if (mysql_query(conn, q)) 
        {
            cout << "Query Error: " << mysql_error(conn) << endl;
            return;
        }

        stmt.str("");
        stmt << "DROP TABLE members;";
        query = stmt.str();
        q = query.c_str();
        if (mysql_query(conn, q)) 
        {
            cout << "Query Error: " << mysql_error(conn) << endl;
            return;
        }

        stmt.str("");
        stmt << "SET foreign_key_checks = 1;";
        query = stmt.str();
        q = query.c_str();
        if (mysql_query(conn, q)) 
        {
            cout << "Query Error: " << mysql_error(conn) << endl;
            return;
        }
    }

    stmt.str("");
    stmt << "CREATE TABLE members ( "
        << "id INT NOT NULL AUTO_INCREMENT PRIMARY KEY, "
        << "name VARCHAR(255), "
        << "addr_line1 VARCHAR(255), "
        << "addr_line2 VARCHAR(255), "
        << "addr_city VARCHAR(255), "
        << "addr_state VARCHAR(255), "
        << "phone_num BIGINT, "
        << "beg_date DATE, "
        << "end_date DATE, "
        << "valid VARCHAR(255) )"
        << ";";
    query = stmt.str();
    q = query.c_str();
    if (mysql_query(conn, q))
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }

    stmt.str("");
    stmt << "INSERT INTO members(name, addr_line1, addr_line2, addr_city, addr_state, phone_num, beg_date, end_date, valid) "
        << "VALUES "
        << "(\"" << member1_name << "\", \"" << member1_addr_line1 << "\", \"" << member1_addr_line2 << "\" , \"" << member1_addr_city << "\", \"" << member1_addr_state << "\", LPAD(FLOOR(RAND() * 999999999999), 12, '0'), CURDATE(), Date_add(curdate(), INTERVAL 1 YEAR), 'valid'), "
        << "(\"" << member2_name << "\", \"" << member2_addr_line1 << "\", \"" << member2_addr_line2 << "\" , \"" << member2_addr_city << "\", \"" << member2_addr_state << "\", LPAD(FLOOR(RAND() * 999999999999), 12, '0'), CURDATE(), Date_add(curdate(), INTERVAL 1 YEAR), 'valid'), "
        << "(\"" << member3_name << "\", \"" << member3_addr_line1 << "\", \"" << member3_addr_line2 << "\" , \"" << member3_addr_city << "\", \"" << member3_addr_state << "\", LPAD(FLOOR(RAND() * 999999999999), 12, '0'), CURDATE(), Date_add(curdate(), INTERVAL 1 YEAR), 'valid')"
        << ";";
    query = stmt.str();
    q = query.c_str();
    if (mysql_query(conn, q))
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }
}

void database_seeders::sales_seed()
{

}

database_seeders::database_seeders()
{
    cout << "DATABASE SEEDERS\n" << endl;
}

database_seeders::~database_seeders()
{
    cout << "\nDatabase seeding completed successfully." << endl;
}

