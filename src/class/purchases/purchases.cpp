#include "purchases.hpp"

void purchases::new_ord()
{
    cout << "\nNew Order Books" << endl;
    cout << "\tBook id\t\t\t\t\t: ";
    cin >> book_id;
    cout << "\tSupplier id\t\t\t\t: ";
    cin >> sup_id;
    cout << "\tQuantity\t\t\t\t: ";
    cin >> qty;
    cout << "\tEstimated expected delivery (in days)\t: ";
    cin >> estim_deliv;
    
    stmt.str("");
    stmt << "INSERT INTO purchases (book_id, sup_id, qty, dt_ordered, estim_deliv, received) VALUES(" << book_id << ", " << sup_id << ", " << qty << ", curdate(), Date_add(curdate(), INTERVAL " << estim_deliv << " DAY), 'F');";
    query = stmt.str();
    q = query.c_str();
    
    if (mysql_query(conn, q)) 
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }

    cout << "New order added!" << endl;
}

void purchases::mark_reciv()
{
    cout << "\nOrder Received Mark" << endl;
    cout << "\tOrder id: ";
    cin >> order_id;

    stmt.str("");
    stmt << "SELECT received FROM purchases WHERE order_id = " << order_id << ";";
    query = stmt.str();
    q = query.c_str();

    if (mysql_query(conn, q)) {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }
    
    res_set = mysql_store_result(conn);

    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        received = *row[0];
        if (received == 'T')
        { 
            cout << endl << endl << "Order already received." << endl << endl << endl;
        }
        else
        {
            stmt.str("");
            stmt << "UPDATE purchases SET received = 'T' WHERE order_id = " << order_id << ";";
            query = stmt.str();
            q = query.c_str();
            if (mysql_query(conn, q)) {
                cout << "Query Error: " << mysql_error(conn) << endl;
            }

            res_set = mysql_store_result(conn);
            
            if (!(res_set))
                cout << endl << endl << "Received marked successfully!" << endl << endl << endl;
            else
                cout << endl << endl << "Entry ERROR!" << endl << "Contact Technical Team" << endl << endl << endl;
        }
    }
    else
    {
        cout << endl << endl << "No order found." << endl << endl << endl;
    }
}

void purchases::mark_cancel()
{
    cout << "\nOrder Cancelled Mark" << endl;
    cout << "\tOrder id: ";
    cin >> order_id;

    stmt.str("");
    stmt << "SELECT received FROM purchases WHERE order_id = " << order_id << ";";
    query = stmt.str();
    q = query.c_str();

    if (mysql_query(conn, q)) {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }
    
    res_set = mysql_store_result(conn);
    
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        received = *row[0];
        if (received == 'C')
        { 
            cout << endl << endl << "Order already canceled." << endl << endl << endl;
        }
        else
        {
            stmt.str("");
            stmt << "UPDATE purchases SET received = 'C' WHERE order_id = " << order_id << ";";
            query = stmt.str();
            q = query.c_str();
            if (mysql_query(conn, q)) 
            {
                cout << "Query Error: " << mysql_error(conn) << endl;
                return;
            }

            res_set = mysql_store_result(conn);
            
            if (!(res_set))
                cout << endl << endl << "Cancelled marked successfully!" << endl << endl << endl;
            else
                cout << endl << endl << "Entry ERROR!" << endl << "Contact Technical Team" << endl << endl << endl;
        }
    } 
    else
    {
        cout << endl << endl << "No order found." << endl << endl << endl;
    }
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
        cout << "Wrong Input" << endl << "Invalid input";
		cin.get();
        return;
        break;
    }

    stmt.str("");
    stmt << "SELECT * FROM purchases WHERE received = '" << received << "';";
    query = stmt.str();
    q = query.c_str();
    if (mysql_query(conn, q)) 
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }
    res_set = mysql_store_result(conn);
    
    switch (c)
    {
    case 1:
        cout << endl << "\nOrders not received are" << endl;
        break;
    case 2:
        cout << endl << "\nOrders cancelled are" << endl;
        break;
    case 3:
        cout << endl << "\nOrders received are" << endl;
        break;
    default:
        return;
        break;
    }
    while ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << endl;
        cout << "\tOrder id\t\t: " << row[0] << endl;
        cout << "\tBook id\t\t\t: " << row[1] << endl;
        cout << "\tSupplier id\t\t: " << row[2] << endl;
        cout << "\tQuantity\t\t: " << row[3] << endl;
        cout << "\tDate ordered\t\t: " << row[4] << endl;
        cout << "\tEstimated delivery date\t: " << row[5] << endl;
        cout << endl << endl << endl;
    }
    cout << endl << endl << endl << endl;
}