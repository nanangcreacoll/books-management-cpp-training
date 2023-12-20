#include "employees.hpp"

void employees::add_emp()
{
    cout << "Add Employees" << endl;
    cout << "Enter your id for verification: ";
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

    cout << "Details of New Employees" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Address (in 3 lines, 3rd line is the city): ";
    cin >> addr_line1;
    cin >> addr_line2;
    cin >> addr_city;
    cout << "State: ";
    cin >> addr_state;
    cout << "Phone number: ";
    cin >> phone_num;
    cout << "Salary: ";
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
    cout << "Assign Manager Status" << endl;
    cout << "Enter your id for verification: ";
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

    cout << "Employee id to grant Manager status: ";
    cin >> id;

    stmt.str("");
    stmt << "UPDATE employees SET mgr_status = 'T' WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    cout << endl << endl << endl;
    cout << "Manager status granted!" << endl << endl << endl;
}

