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
    cout << "Order Recieved Mark" << endl;
    cout << "Order id: ";
    cin >> order_id;
    
    stmt.str("");
    stmt << "UPDATE purchases SET recieved = 'T' WHERE order_id = " << order_id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    
    cout << "Recieved marked successfully!" << endl;
}