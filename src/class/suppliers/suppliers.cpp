#include"suppliers.hpp"

void suppliers::add_sup()
{
    cout << "\nAdd Supplier" << endl;
    cout << "\tSupplier Name\t: ";
    cin.ignore();
    getline(cin, name);
    cout << "\tPhone number\t: ";
    cin >> phone_num;
    cin.ignore();
    cout << "\tAddress (in 3 lines, 3rd line is the city): \n";
    getline(cin, addr_line1);
    getline(cin, addr_line2);
    getline(cin, addr_city);
    cout << "\tState\t: ";
    getline(cin, addr_state);
    
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
    cout << "\nRemove Supplier" << endl;
    cout << "\tSupplier id\t: ";
    cin >> id;

    stmt.str("");
    stmt << "SELECT name FROM suppliers WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();

    if (mysql_query(conn, q)) {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }

    res_set = mysql_store_result(conn);

    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        char choice;
        cout << "\tSupplier name\t: " << row[0] << endl;
        cout << "\tDo yout want to remove the supplier? [y/n]: ";
        cin >> choice;
        if (choice == 121 || choice == 89)
        {
            stmt.str("");
            stmt << "DELETE FROM suppliers WHERE id = " << id << ";";
            query = stmt.str();
            q = query.c_str();
            
            if (mysql_query(conn, q)) {
                cout << "Query Error: " << mysql_error(conn) << endl;
                return;
            }

            res_set = mysql_store_result(conn);

            if (!(res_set))
                cout << endl << endl << "Supplier removed." << endl << endl << endl;
            else
                cout << endl << endl << "Entry ERROR!" << endl << "Contact Technical Team" << endl << endl << endl;
        }
        else
        {
            cout << "No change made." << endl;
        }
    }
    else
    {
        cout << "No supplier found." << endl;
    }
}

void suppliers::search_id()
{
    cout << "\nSearch Supplier Details by Id" << endl;
    cout << "\tSupplier id\t: ";
    cin >> id;
    stmt.str("");
    stmt << "SELECT * FROM suppliers WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);

    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "\tName\t\t: " << row[1] << endl;
        cout << "\tPhone Number\t: " << row[2] << endl;
        cout << "\tAddress\t\t: " << row[3] << ", " << row[4] << endl;
        cout << "\tCity\t\t: " << row[5] << endl;
        cout << "\tState\t\t: " << row[6] << endl;
    }
    else
    {
        cout << "No supplier found!" << endl;
    }
}

void suppliers::display()
{
    cout << "\nSuppliers Display" << endl;
    int i = 0;
    query = "SELECT * FROM suppliers"; 
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    while ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "\nSuppliers Details, No." << ++i << endl;
        cout << "\tSupplier id\t: " << row[0] << endl;
        cout << "\tName\t\t: " << row[1] << endl;
        cout << "\tPhone Number\t: " << row[2] << endl;
        cout << "\tAddress\t\t: " << row[3] << ", " << row[4] << endl;
        cout << "\tCity\t\t: " << row[5] << endl;
        cout << "\tState\t\t: " << row[6] << endl;
        cout << endl << endl << endl << endl;
    }
}