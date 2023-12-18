#include"suppliers.hpp"

void suppliers::add_sup()
{
    cout << "Enter the Supplier Name: ";
    cin >> name;
    cout << "Enter Phone number: ";
    cin >> phone_num;
    cout << "Enter the address (in 3 lines, 3rd line is the city): ";
    cin >> addr_line1;
    cin >> addr_line2;
    cin >> addr_city;
    cout << "Enter State: ";
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