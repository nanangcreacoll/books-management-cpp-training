#include"suppliers.hpp"

void suppliers::add_sup()
{
    cout << "Add Supplier" << endl;
    cout << "Supplier Name: ";
    cin >> name;
    cout << "Phone number: ";
    cin >> phone_num;
    cout << "Address (in 3 lines, 3rd line is the city): ";
    cin >> addr_line1;
    cin >> addr_line2;
    cin >> addr_city;
    cout << "State: ";
    cin >> addr_state;
    
    stmt.str("");
    stmt << "INSERT INTO suppliers(name, phone_num, addr_line1, addr_line2, addr_city, addr_state) VALUES('" << name << "', " << phone_num << ", '"  << addr_line1 << "', '" << addr_line2 << "', '" << addr_city << "', '" << addr_state << "');";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);

    if (!(res_set))
        cout << endl << endl << "Supplier record inserted successfully." << endl << endl << endl;
    else
        cout << endl << endl << "ERROR ENTRY!" << endl << "Contact Technical Team." << endl << endl << endl;
}

void suppliers::remove_supplier()
{
    cout << "Remove Supplier" << endl;
    cout << "Supplier id: ";
    cin >> id;
    stmt.str("");
    stmt << "DELETE FROM suppliers WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    cout << "Supplier Removed." << endl;
}

void suppliers::search_id()
{
    cout << "Search Supplier Details by Id" << endl;
    cout << "Supplier id: ";
    cin >> id;
    stmt.str("");
    stmt << "SELECT * FROM suppliers WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);

    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "Detail of Supplier Id: " << row[0] << endl;
        cout << "Name: " << row[1] << endl;
        cout << "Phone Number: " << row[2] << endl;
        cout << "Address: " << row[3] << " " << row[4] << endl;
        cout << "City: " << row[5] << endl;
        cout << "State: " << row[6] << endl;
    }
    else
    {
        cout << "No supplier found!" << endl;
    }
}