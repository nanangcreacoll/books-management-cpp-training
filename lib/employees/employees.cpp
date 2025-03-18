#include "employees.hpp"

void employees::add_emp()
{
    cout << "\nAdd Employees" << endl;
    cout << "\tEnter your id for verification\t: ";
    cin >> id;

    stmt.str("");
    stmt << "SELECT mgr_status FROM employees WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    if (mysql_query(conn, q)) 
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }
    
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) == NULL)
    {
        cout << "Employee not found!" << endl << endl;
        return;
    }
    else
    {
        mgr_status = (char*) row[0];
        if (mgr_status == "F")
        {
            cout << "You do not have Manager rights!" << endl << endl;
            return;
        }
    }

    cout << "\nDetails of New Employees" << endl;
    cout << "\tName\t\t: ";
    cin >> name;
    cout << "\tAddress (in 3 lines, 3rd line is the city): \n";
    cin.ignore();
    getline(cin, addr_line1);
    getline(cin, addr_line2);
    getline(cin, addr_city);
    cout << "\tState\t\t: ";
    getline(cin, addr_state);
    cout << "\tPhone number\t: ";
    cin >> phone_num;
    cout << "\tSalary\t\t: ";
    cin >> salary;
    
    stmt.str(""); 
    stmt << "INSERT INTO employees (name, addr_line1, addr_line2, addr_city, addr_state, phone_num, date_of_joining, salary, mgr_status) VALUES('" << name << "', '" << addr_line1 << "', '" << addr_line2 << "', '" << addr_city << "', '" << addr_state << "', " << phone_num << ", curdate(), " << salary << ", 'F');";
    query = stmt.str();
    q = query.c_str();
    if (mysql_query(conn, q)) 
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }
    cout << endl << endl << "Employee added successfully" << endl << endl << endl;
}

void employees::assign_mgr_status()
{
    cout << "\nAssign Manager Status" << endl;
    cout << "\tEnter your id for verification\t\t: ";
    cin >> id;

    stmt.str("");
    stmt << "SELECT mgr_status FROM employees WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    if (mysql_query(conn, q)) 
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }
    
    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) == NULL)
    {
        cout << "Employee not found!" << endl << endl << endl;
        return;
    }
    else
    {
        mgr_status = (char*) row[0];
        if (mgr_status == "F")
        {
            cout << "You do not have Manager rights!" << endl << endl;
            return;
        }
    }

    cout << "\tEmployee id to grant Manager status\t: ";
    cin >> id;

    stmt.str("");
    stmt << "UPDATE employees SET mgr_status = 'T' WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    if (mysql_query(conn, q)) 
    {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }
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
        cout << "\tName\t\t: " << row[1] << endl;
        cout << "\tAddress\t\t: " << row[2] << ", " << row[3] << ", " << row[4] << endl;
        cout << "\tState\t\t: " << row[5] << endl;
        cout << "\tPhone number\t: " << row[6] << endl;
        cout << "\tDate of joining\t: " << row[7] << endl;
        cout << "\tSalary\t\t: " << row[8] << endl << endl << endl;
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
            cout << "\nEmployee Details, No." << ++i << endl;
            cout << "\tEmployee id\t: " << row[0] << endl;
            cout << "\tName\t\t: " << row[1] << endl;
            cout << "\tAddress\t\t: " << row[2] << ", " << row[3] << ", " << row[4] << endl;
            cout << "\tState\t\t: " << row[5] << endl;
            cout << "\tPhone number\t: " << row[6] << endl;
            cout << "\tDate of joining\t: " << row[7] << endl;
            cout << "\tSalary\t\t: " << row[8] << endl;
            cout << endl << endl << endl;
        } while ((row = mysql_fetch_row(res_set)) != NULL);
    }
    else
    {
        cout << "Employees not found" << endl;
    }
}

void employees::update_salary()
{
    cout << "\nEmployees Update Salary" << endl;
    cout << "\tEmployee id\t\t: ";
    cin >> id;
    
    stmt.str("");
    stmt << "SELECT name FROM employees WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();

    if (mysql_query(conn, q)) {
        cout << "Query Error: " << mysql_error(conn) << endl;
        return;
    }

    res_set = mysql_store_result(conn);

    if ((row = mysql_fetch_row(res_set)) != NULL)
    {
        cout << "\tName\t\t\t: " << row[0] << endl;
        cout << "\tEnter updated salaray\t: ";
        cin >> salary;
        
        stmt.str("");
        stmt << "UPDATE employees SET salary = " << salary << " WHERE id = " << id << ";";
        query = stmt.str();
        q = query.c_str();
        if (mysql_query(conn, q)) {
            cout << "Query Error: " << mysql_error(conn) << endl;
            return;
        }
        cout << endl << endl << endl;
        cout << "Salary update successfully" << endl;
        cout << endl << endl << endl;
    }
    else
    {
        cout << endl << endl << endl;
        cout << "No Employee found." << endl;
        cout << endl << endl << endl;
    }
}