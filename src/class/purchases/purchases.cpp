#include "purchases.hpp"

void purchases::new_ord()
{
    cout << "New Order Books" << endl;
    cout << "Book id: ";
    cin >> book_id;
    cout << "Supplier id: ";
    cin >> sup_id;
    cout << "Quantity: ";
    cin >> qty;
    cout << "Estimated expected delivery (in days): ";
    cin >> estim_deliv;
    
    stmt.str("");
    stmt << "INSERT INTO purchases (book_id, sup_id, qty, dt_ordered, estim_deliv) VALUES(" << book_id << ", " << sup_id << ", " << qty << ", curdate(), Date_add(curdate(), INTERVAL " << estim_deliv << " DAY));";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);

    cout << "New order added!" << endl;
}

void purchases::mark_reciv()
{
    cout << "Order Received Mark" << endl;
    cout << "Order id: ";
    cin >> order_id;
    
    stmt.str("");
    stmt << "UPDATE purchases SET received = 'T' WHERE order_id = " << order_id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);

    cout << "Received marked successfully!" << endl;
}

void purchases::mark_cancel()
{
    cout << "Order Cancelled Mark" << endl;
    cout << "Order id: ";
    cin >> order_id;
    
    stmt.str("");
    stmt << "UPDATE purchases SET received = 'C' WHERE order_id = " << order_id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);

    cout << "Cancelled marked successfully" << endl;
}

void purchases::view()
{
    int c;
    cout << "Select an Option" << endl;
    cout << "1. View orders not Received" << endl;
    cout << "2. View orders Cancelled" << endl;
    cout << "3. View orders Received" << endl;
    cout << "\nEnter your choice: ";
    cin >> c;
    switch (c)
    {
    case 1:
        received = 'F';
        break;
    case 2:
        received = 'C';
        break;
    case 3:
        received = 'T';
        break;
    default:
        return;
    }

    stmt.str("");
    stmt << "SELECT * FROM purchases WHERE received = " << received << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    
    switch (c)
    {
    case 1:
        cout << endl << "Orders not received are" << endl;
        break;
    case 2:
        cout << endl << "Orders cancelled are" << endl;
    case 3:
        cout << endl << "Orders received are" << endl;
    }
    while ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << endl;
        cout << "Order id: " << row[0] << endl;
        cout << "Book id: " << row[1] << endl;
        cout << "Supplier id: " << row[2] << endl;
        cout << "Quantity: " << row[3] << endl;
        cout << "Date ordered: " << row[4] << endl;
        cout << "Estimated delivery date: " << row[5] << endl;
        cout << endl << endl << endl;
    }
    cout << endl << endl << endl << endl;
}