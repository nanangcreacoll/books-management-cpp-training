#ifndef __BOOKS
#define __BOOKS

class books
{
    int id;
    string name;
    string auth;
    int price;
    int qty;

public:
    void add();
    void update_price();
    void search();
    void update();
    void display();
};

#endif