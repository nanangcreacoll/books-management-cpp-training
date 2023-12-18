#include "books.hpp"

void books::add()
{
    cout << "\nAdd Book Data" << endl;
    cout << "\tName: ";
    cin >> name;
    cout << "\tAuthor: ";
    cin >> author;
    cout << "\tPrice: ";
    cin >> price;
    cout << "\tQuantity received: ";
    cin >> qty;
    
    stmt.str("");
    stmt << "INSERT INTO books(name,author,price,qty) values('" << name << "','" << author << "'," << price << "," << qty << ");";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);

    if (!(res_set))
        cout << endl << endl << "Book Record Inserted Successfully" << endl << endl << endl;
    else 
        cout << endl << endl << "Entry ERROR !" << endl << "Contact Technical Team " << endl << endl << endl;
}

void books::update_price()
{
    char choice;
    cout << "\nBook Update in Price" << endl;
    cout << "\tBook Id: ";
    cin >> id;
    
    stmt.str("");
    stmt << "SELECT name, price FROM books WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);

    res_set = mysql_store_result(conn);
    
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "Book name: " << row[0] << endl;
        cout << "Current price of the book: " << row[1] << endl;
        cout << "Do yout want to update the price? [y/n]: ";
        cin >> choice;
        
        if (choice == 121 || choice == 89)
        {
            cout << "New price: ";
            cin >> price;

            stmt.str("");
            stmt << "UPDATE books SET price = " << price << "WHERE id = " << id << ";";
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
    cout << "\tBook id for details: ";
    cin >> id;

    stmt.str("");
    stmt << "SELECT * FROM books WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn); 
    
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "\nThe Details of Book Id " << row[0] << endl;
        cout << "The Name of the book is: " << row[1] << endl;
        cout << "The Author of " << row[1] << " is " << row[2] << endl;
        cout << "The price of the book is " << row[3] << endl;
        cout << "The inventory count is " << row[4] << endl;
    }
    else
    {
        cout << "No record found" << endl;
    }
}

void books::update()
{
    int b_id[100], qty[100], i=0, max;
    
    stmt.str("");
    stmt << "SELECT book_id, qty FROM purchases WHERE recives = 'T' AND inv IS NULL;";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    
    stmt.str("");
    stmt << "UPDATE purchases SET inv = 1 WHERE recives = 'T' AND inv IS NULL;";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    
    while ((row = mysql_fetch_row(res_set)) != NULL)
    {
        b_id[i] = (int) row[0];
        qty[i] = (int) row[1];
        i++;
    }
    
    max = i;
    for (i = 0; i <= max; i++)
    {
        stmt.str("");
        stmt << "UPDATE books SET qty = " << qty[i] << " WHERE id = " << b_id[i] << ";";
        query = stmt.str();
        q = query.c_str();
        mysql_query(conn, q);
    }

    cout << "The orders received have been updated." << endl;
}

void books::display()
{
    int i = 0;
    query = "SELECT * FROM books"; 
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    while ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "Name for book " << i++ << " : " << row[1] << endl;
        cout << "Name of Author: " << row[2] << endl;
        cout << "Price: " << row[3] << endl;
        cout << "Quantity: " << row[4] << endl;
        cout << endl << endl << endl << endl;
    }
}