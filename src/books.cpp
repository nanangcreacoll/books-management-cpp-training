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

}

void books::update()
{
    
}

void books::display()
{

}