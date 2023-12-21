#include "employees.hpp"

void employees::add_emp()
{
    cout << "\nAdd Employees" << endl;
    cout << "\tEnter your id for verification: ";
    cin >> id;

    stmt.str("");
    stmt << "SELECT mgr_status FROM employees WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) == NULL)
    {
        cout << "Employee not found!" << endl << endl;
        return;
    }
    else
    {
        mgr_status = (char*) row[0];
        if (mgr_status == "T")
        {
            cout << "You do not have Manager rights!" << endl << endl;
            return;
        }
    }

    cout << "\nDetails of New Employees" << endl;
    cout << "\tName: ";
    cin >> name;
    cout << "\tAddress (in 3 lines, 3rd line is the city): ";
    cin >> addr_line1;
    cin >> addr_line2;
    cin >> addr_city;
    cout << "\tState: ";
    cin >> addr_state;
    cout << "\tPhone number: ";
    cin >> phone_num;
    cout << "\tSalary: ";
    cin >> salary;
    
    stmt.str(""); 
    stmt << "INSERT INTO employees (name, addr_line1, addr_line2, addr_city, addr_state, phone_num, date_of_joining, salary) VALUES('" << name << "', '" << addr_line1 << "', '" << addr_line2 << "', '" << addr_city << "', '" << addr_state << "', " << phone_num << ", curdate(), " << salary << ");";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    cout << endl << endl << "Employee added successfully" << endl << endl << endl;
}

void employees::assign_mgr_status()
{
    cout << "\nAssign Manager Status" << endl;
    cout << "\tEnter your id for verification: ";
    cin >> id;

    stmt.str("");
    stmt << "SELECT mgr_status FROM employees WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) == NULL)
    {
        cout << "Employee not found!" << endl << endl << endl;
        return;
    }
    else
    {
        mgr_status = (char*) row[0];
        if (mgr_status == "T")
        {
            cout << "You do not have Manager rights!" << endl << endl;
            return;
        }
    }

    cout << "\tEmployee id to grant Manager status: ";
    cin >> id;

    stmt.str("");
    stmt << "UPDATE employees SET mgr_status = 'T' WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    cout << endl << endl << endl;
    cout << "Manager status granted!" << endl << endl << endl;
}

void employees::search_emp()
{
    cout << "\nEmployee Search" << endl;
    cout << "\tEmployee id: ";
    cin >> id;

    stmt.str(""); 
    stmt << "SELECT * FROM employees WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "\nEmployee Details" << endl;
        cout << "\tName: " << row[1] << endl;
        cout << "\tAddress: " << row[2] << " " << row[3] << ", " << row[4] << endl;
        cout << "\tState: " << row[5] << endl;
        cout << "\tPhone number: " << row[6] << endl;
        cout << "\tDate of joining: " << row[7] << endl;
        cout << "\tSalary: " << row[8] << endl << endl << endl;
    }
    else
    {
        cout << "No employee found!" << endl << endl << endl;
    }
}

void employees::display()
{
    cout << "\nEmployees Display" << endl;
    int i = 0;
    query = "SELECT * FROM employees;";
    q = query.c_str();
    mysql_query(conn, q);

    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        do
        {
            cout << "\nEmployees Details, No." << ++i << endl;
            cout << "\tName: " << row[1] << endl;
            cout << "\tAddress: " << row[2] << ", " << row[3] << ", " << row[4] << endl;
            cout << "\tState: " << row[5] << endl;
            cout << "\tPhone number: " << row[6] << endl;
            cout << "\tDate of joining: " << row[7] << endl;
            cout << "\tSalary: " << row[8] << endl;
            cout << endl << endl << endl;
        } while ((row = mysql_fetch_row(res_set)) != NULL);
    }
    else
    {
        cout << "Employees not found" << endl;
    }
}