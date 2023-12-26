#include "books.hpp"

void books::add()
{
    cout << "\nAdd Book Data" << endl;
    cout << "\tName\t\t\t: ";
    cin.ignore();
    getline(cin, name);
    cout << "\tAuthor\t\t\t: ";
    getline(cin, author);
    cout << "\tPrice\t\t\t: ";
    cin >> price;
    cin.ignore();
    cout << "\tQuantity received\t: ";
    cin >> qty;
    cin.ignore();

    stmt.str("");
    stmt << "INSERT INTO books (name, author, price, qty) VALUES (\"" << name << "\", '" << author << "', " << price << ", " << qty << ");";
    query = stmt.str();
    q = query.c_str();
    
    if (mysql_query(conn, q)) {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }

    res_set = mysql_store_result(conn);

    if (!(res_set))
    {
        cout << endl << endl << "Book Record Inserted Successfully" << endl << endl << endl;
    }
    else
    {
        cout << endl << endl << "Entry ERROR !" << endl << "Contact Technical Team " << endl << endl << endl;
    }
}

void books::update_price()
{
    char choice;
    cout << "\nBook Update in Price" << endl;
    cout << "\tBook Id\t\t\t: ";
    cin >> id;
    
    stmt.str("");
    stmt << "SELECT name, price FROM books WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    
    if (mysql_query(conn, q)) {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }

    res_set = mysql_store_result(conn);
    
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "\tBook name\t\t\t: " << row[0] << endl;
        cout << "\tCurrent price of the book\t: " << row[1] << endl;
        cout << "\tDo yout want to update the price? [y/n]: ";
        cin >> choice;
        
        if (choice == 121 || choice == 89)
        {
            cout << "\tNew price\t\t\t: ";
            cin >> price;

            stmt.str("");
            stmt << "UPDATE books SET price = " << price << " WHERE id = " << id << ";";
            query = stmt.str();
            q = query.c_str();
            
            if (mysql_query(conn, q)) {
                cout << "Query Error: " << mysql_error(conn) << endl;
                return;
            }

            res_set = mysql_store_result(conn);

            if (!(res_set))
                cout << endl << endl << "Book Price Updated Successfully" << endl << endl << endl;
            else
                cout << endl << endl << "Entry ERROR!" << endl << "Contact Technical Team" << endl << endl << endl;
        }
        else
        {
            cout << "No changes made." << endl;
        }
    }
    else
    {
        cout << "No book found." << endl;
    }
}

void books::search()
{
    cout << "\nBook Search" << endl;
    cout << "\tBook id for details\t\t: ";
    cin >> id;

    stmt.str("");
    stmt << "SELECT * FROM books WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn); 
    
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "\tThe Name of the book is\t\t: " << row[1] << endl;
        cout << "\tThe Author is\t\t\t: " << row[2] << endl;
        cout << "\tThe price of the book is\t: " << row[3] << endl;
        cout << "\tThe inventory count is\t\t: " << row[4] << endl;
    }
    else
    {
        cout << "No record found" << endl;
    }
}

void books::update()
{
    int b_id[100], qty[100], i=0, max;
    bool updated = false;
    
    stmt.str("");
    stmt << "SELECT book_id, qty FROM purchases WHERE received = 'T' AND inv IS NULL;";
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
    
    stmt.str("");
    stmt << "UPDATE purchases SET inv = 1 WHERE received = 'T' AND inv IS NULL;";
    query = stmt.str();
    q = query.c_str();
    
    if (mysql_query(conn, q)) {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }
    
    while ((row = mysql_fetch_row(res_set)) != NULL)
    {
        b_id[i] = stoi(row[0]);
        qty[i] = stoi(row[1]);
        i++;
    }
    
    max = i;
    for (i = 0; i <= max; i++)
    {
        stmt.str("");
        stmt << "UPDATE books SET qty = (qty + " << qty[i] << ") WHERE id = " << b_id[i] << ";";
        query = stmt.str();
        q = query.c_str();
        
        if (mysql_query(conn, q)) 
        {
            cout << "Query Error: " << mysql_error(conn) << endl;
            return;
        }
        else 
        {
            if (mysql_affected_rows(conn) > 0)
            {
                updated = true;
            }
        }
    }

    if (updated)
    {
        cout << "The orders received have been updated." << endl;
    }
    else
    {
        cout << "No updates were made." << endl;
    }
}

void books::display()
{
    cout << "\nBooks Display" << endl;
    int i = 0;
    query = "SELECT * FROM books"; 
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    while ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "\tName for book " << ++i << "\t: " << row[1] << endl;
        cout << "\tId for book\t: " << row[0] << endl;
        cout << "\tName of Author\t: " << row[2] << endl;
        cout << "\tPrice\t\t: " << row[3] << endl;
        cout << "\tQuantity\t: " << row[4] << endl;
        cout << endl << endl << endl << endl;
    }
}