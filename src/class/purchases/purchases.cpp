#include "purchases.hpp"

void purchases::new_ord()
{
    cout << "\nNew Order Books" << endl;
    cout << "\tBook id: ";
    cin >> book_id;
    cout << "\tSupplier id: ";
    cin >> sup_id;
    cout << "\tQuantity: ";
    cin >> qty;
    cout << "\tEstimated expected delivery (in days): ";
    cin >> estim_deliv;
    
    stmt.str("");
    stmt << "INSERT INTO purchases (book_id, sup_id, qty, dt_ordered, estim_deliv, recieved) VALUES(" << book_id << ", " << sup_id << ", " << qty << ", curdate(), Date_add(curdate(), INTERVAL " << estim_deliv << " DAY), 'F');";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);

    cout << "New order added!" << endl;
}

void purchases::mark_reciv()
{
    cout << "\nOrder Received Mark" << endl;
    cout << "\tOrder id: ";
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
    cout << "\nOrder Cancelled Mark" << endl;
    cout << "\tOrder id: ";
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
    cout << "\nSelect an Option" << endl;
    cout << "\t1. View orders not Received" << endl;
    cout << "\t2. View orders Cancelled" << endl;
    cout << "\t3. View orders Received" << endl;
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
        cout << endl << "\nOrders not received are" << endl;
        break;
    case 2:
        cout << endl << "\nOrders cancelled are" << endl;
    case 3:
        cout << endl << "\nOrders received are" << endl;
    }
    while ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << endl;
        cout << "\tOrder id: " << row[0] << endl;
        cout << "\tBook id: " << row[1] << endl;
        cout << "\tSupplier id: " << row[2] << endl;
        cout << "\tQuantity: " << row[3] << endl;
        cout << "\tDate ordered: " << row[4] << endl;
        cout << "\tEstimated delivery date: " << row[5] << endl;
        cout << endl << endl << endl;
    }
    cout << endl << endl << endl << endl;
}