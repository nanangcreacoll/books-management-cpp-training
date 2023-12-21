#include "members.hpp"

void members::add_member()
{
    cout << "\nAdd Members" << endl;
    cout << "\tName: ";
    cin >> name;
    cout << "\tPhone number: ";
    cin >> phone_num;
    cout << "\tAddress (in 3 lines, 3rd line is the city): ";
    cin >> addr_line1;
    cin >> addr_line2;
    cin >> addr_city;
    cout << "\tState: ";
    cin >> addr_state;

    stmt.str("");
    stmt << "INSERT INTO members(name, addr_line1, addr_line2, addr_city, addr_state, phone_num, beg_date, end_date, valid) VALUES('" << name << "', '"  << addr_line1 << "', '"  << addr_line2 << "', '" << addr_city << "', '" << addr_state << "', " << phone_num << ", curdate(), Date_add(curdate(), INTERVAL 1 YEAR), 'valid');";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);

    // fetching member id
    stmt.str("");
    stmt << "SELECT id FROM members WHERE name = '" << name << "' AND phone_num = " << phone_num << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);
    res_set = mysql_store_result(conn);
    row = mysql_fetch_row(res_set);
    cout << endl << endl << endl;
    cout << "Member added succesfully." << endl;
    cout << "\tMember id: " << row[0] << endl;
    cout << endl << endl << endl;
}

void members::refresh()
{
    query = "UPDATE members SET valid = 'invalid' WHERE end_date <= curdate();";
    q = query.c_str();
    mysql_query(conn, q);
}

void members::search_member()
{
    cout << "\nMembers Search" << endl;
    cout << "\tMember id: ";
    cin >> id;
    
    stmt.str("");
    stmt << "SELECT * FROM members WHERE id = " << id << ";";
    query = stmt.str();
    q = query.c_str();
    mysql_query(conn, q);

    res_set = mysql_store_result(conn);
    if ((row = mysql_fetch_row(res_set)) !=  NULL)
    {
        cout << "\nMember Details" << endl;
        cout << "\tName: " << row[1] << endl;
        cout << "\tAddres: " << row[2] << ", " << row[3] << ", " << row[4] << endl;
        cout << "\tState: " << row[5] << endl;
        cout << "\tPhone number: " << row[6] << endl;
        cout << "\tMembership begin date: " << row[7] << endl;
        cout << "\tMembership end date: " << row[8] << endl;
        cout << "\tMembership status: " << row[9] << endl;
    }
    else
    {
        cout << "\nNo member found!" << endl << endl << endl;
    }
}