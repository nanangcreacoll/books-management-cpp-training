#include "sales.hpp"

void sales::add()
{
    cout << "\nSales Add" << endl;
    cout << "\tMember id: ";
    cin >> member_id;
    cout << "\tBook id: ";
    cin >> book_id;
    cout << "\tQuantity: ";
    cin >> qty;

    stmt.str("");
    stmt << "SELECT price*" << qty << " FROM books WHERE id = " << book_id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "The bill amount: " << row[0] << endl << endl;
        amount = stoi(row[0]);
    }
    else
    {
        cout << "Book id invalid!" << endl;
        cin.get();
        return;
    }

    stmt.str("");
    stmt << "INSERT INTO sales (member_id, book_id, qty, amount, date_sales) VALUES (" << member_id << ", " << book_id << ", " << qty << ", " << amount << ", curdate());";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);

    // fetching invoice id
    stmt.str("");
    stmt << "SELECT invoice_id FROM sales WHERE member_id = " << member_id << " AND book_id = " << book_id << " AND qty = " << qty << " AND date_sales = curdate();";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);

    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "The invoice id for the bill is " << row[0] << endl << endl << endl;
    }
    else
    {
        cout << "The entered details maybe wrong." << endl << "Please recheck and enter again" << endl << endl << endl;
    }
}

void sales::find_total_sales()
{
    query = "SELECT SUM(amount) FROM sales WHERE year(date_sales) = year(curdate());";
    q = query.c_str();
    mysql_query(conn, q);

    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "Total sales this year: " << row[0] << endl << endl << endl;
    }
}