# Repository C++ Training: Book Shop Management System

Book shop management project training c++ to organize books, suppliers, purchases, employees, members, and sales.

Use a MySQL database, name: bookshop-management.

Create a class containing attributes that are data from a database table and some methods for that class.

### Class

- **books**

```c++
// Data table
int id;  //primary key
string name;
string author;
int price;
int qty;

// Method
void add();
void update_price();
void search();
void update();
void display();
```

- **suppliers**

```c++
// Data table
int id; //primary key
string name;
long int phone_num;
string addr_line1;
string addr_line2;
string addr_city;
string addr_state;

// Method
void add_sup();
void remove_supplier();
void search_id();
void display();
```

- **purchases**

```c++
// Data table
int order_id; //primary key
int book_id; //FK ref (books)
int sup_id; //FK ref (supply)
int qty;
date dt_ordered;
int estim_deliv;
char received; //check(T or C or F) def (F)
int inv;

// Method
void new_ord();
void view();
void mark_cancel();
void mark_reciv();
```

- **employees**

```c++
// Data table
int id; //primary key
string name;
string addr_line1;
string addr_line2;
string addr_city;
string addr_state;
long int phone_num;
date date_of_joining;
long int salary;
string mgr_status; //check(T or F) def f

// Method
void add_emp();
void search_emp();
void assign_mgr_status();
void display();
void update_salary();
```

- **members**

```c++
// Data table
int id; //primary key
string name;
string addr_line1;
string addr_line2;
string addr_city;
string addr_state;
long int phone_num;
date beg_date;
date end_date;
string valid;

// Method
void add_member();
void refresh();
void search_member();
```

- **sales**

```c++
// Data table
int invoice_id; //primary key
int member_id; //FK ref member(id)
int book_id; //FK ref books(id)
int qty;
int amount;
date date_sales;

// Method
void add();
void find_total_sales();
```

Create admin class to using for login method

- **Admin**

```c++
// Data Tables
int id; // primary key
string username;
string password;

bool is_logged_in = false;

// Method
string sha256(const string&);
void add();
bool login(const string&, const string&);
void logout();
bool get_is_logged_in() const;
string get_username() const;
```

---

*Reference*: [Arya-Khanijo/Bookshop-Management](https://github.com/Aryan-Khanijo/Bookshop-Management-System-CPP-Project)