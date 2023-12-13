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

    if (!(res_set))
        cout << endl << endl << "Book Record Inserted Successfully" << endl << endl << endl;
    else 
        cout << endl << endl << "Entry ERROR !" << endl << "Contact Technical Team " << endl << endl << endl;
}

void books::update_price()
{

}

void books::search()
{

}

void books::update()
{
    
}

void books::display()
{

}