#ifndef __DATABASE_SEEDERS
#define __DATABASE_SEEDERS

#include <iostream>
#include <string>
#include <sstream>
#include <mysql/mysql.h>
#include <openssl/evp.h>
#include <openssl/sha.h>
#include <thread>
#include <chrono>

using namespace std;

extern MYSQL *conn;
extern MYSQL_RES *res_set;
extern MYSQL_ROW row;
extern stringstream stmt;
extern const char* q;
extern string query;

class database_seeders
{
private:
    // admin seed
    string username = "admin";
    string password = "password";

    // books seed
    string book_name1 = "Buku Pintar Membuat Cake";
    string book_author1 = "Diah Surjani Ananto";
    int book_price1 = 45000;
    int book_qty1 = 5;

    string book_name2 = "Buku Pintar Membuat CakeBuku Ajar Fisika Dasar: 1";
    string book_author2 = "Dr. Marta Rianna, S.Si";
    int book_price2 = 116000;
    int book_qty2 = 10; 

    string book_name3 = "Schaum's Outlines Fluid Mechanics And Hydraulics Fourth Edition";
    string book_author3 = "William Hughes";
    int book_price3 = 145000;
    int book_qty3 = 15;

    string book_name4 = "Sistem kendali proses industri";
    string book_author4 = "Kiagus Ahmad Roni";
    int book_price4 = 60000;
    int book_qty4 = 6;

    // members seed
    string member1_name = "Maria";
    string member1_addr_line1 = "Jalan Siliwangi no. 31";
    string member1_addr_line2 = "LLBK";
    string member1_addr_city = "Kupang";
    string member1_addr_state = "Nusa Tenggara Timur";

    string member2_name = "Ivan";
    string member2_addr_line1 = "Jalan Istana no. 32";
    string member2_addr_line2 = "Soe";
    string member2_addr_city = "Timor Tengah Selatan";
    string member2_addr_state = "Nusa Tenggara Timur";

    string member3_name = "Nima";
    string member3_addr_line1 = "Jalan Ikan Terbang no.24";
    string member3_addr_line2 = "Depok";
    string member3_addr_city = "Sleman";
    string member3_addr_state = "DI Yogyakarta";

    // suppliers seed
    string supplier1_name = "CV. Tirta Buana Media";
    string supplier1_addr_line1 = "Perumahan Tirta Buana Blok H No. 33";
    string supplier1_addr_line2 = "Cepor, Sendangtirto, Berbah";
    string supplier1_addr_city = "Sleman";
    string supplier1_addr_state = "DI Yogyakarta";

    string supplier2_name = "Adipura Books";
    string supplier2_addr_line1 = "Jalan KH. Djawad Faqih MG III/876";
    string supplier2_addr_line2 = "Mergangsan";
    string supplier2_addr_city = "Yogyakarta";
    string supplier2_addr_state = "DI Yogyakarta";

    // employees seed
    string employee1_name = "Rahmat";
    string employee1_addr_line1 = "Jalan Puger 1";
    string employee1_addr_line2 = "Perumahan Pugeran";
    string employee1_addr_city = "Sleman";
    string employee1_addr_state = "DI Yogyakarta";
    long int employee1_salary = 2500000;
    char employee1_mgr_status = 'T';

    string employee2_name = "Bambang";
    string employee2_addr_line1 = "Jalan Babarsari no. 22";
    string employee2_addr_line2 = "Caturtunggal";
    string employee2_addr_city = "Sleman";
    string employee2_addr_state = "DI Yogyakarta";
    long int employee2_salary = 2100000;
    char employee2_mgr_status = 'F';

    string employee3_name = "Afian";
    string employee3_addr_line1 = "Jalan Perkutut no.3";
    string employee3_addr_line2 = "Kuanino";
    string employee3_addr_city = "Kupang";
    string employee3_addr_state = "Nusa Tenggara Timur";
    long int employee3_salary = 1500000;
    char employee3_mgr_status = 'F';

    // purchases seed
    int purchases1_book_id = 1;
    int purchases1_sup_id = 2;
    int purchases1_qty = 4;
    int purchases1_estim_deliv = 5;
    char purchases1_received = 'T'; 

    int purchases2_book_id = 4;
    int purchases2_sup_id = 1;
    int purchases2_qty = 10;
    int purchases2_estim_deliv = 3;
    char purchases2_received = 'F'; 

    int purchases3_book_id = 2;
    int purchases3_sup_id = 2;
    int purchases3_qty = 6;
    int purchases3_estim_deliv = 8;
    char purchases3_received = 'C';

    // sales seed
    int sale1_member_id = 2;
    int sale1_book_id = 1;
    int sale1_qty = 3;
    int sale1_amount = book_price1 * sale1_qty;

    int sale2_member_id = 1;
    int sale2_book_id = 3;
    int sale2_qty = 6;
    int sale2_amount = book_price3 * sale2_qty;

    int sale3_member_id = 3;
    int sale3_book_id = 4;
    int sale3_qty = 2;
    int sale3_amount = book_price3 * sale3_qty;

public:
    string sha256(const string&);
    void admin_seed();
    void books_seed();
    void suppliers_seed();
    void purchases_seed();
    void employees_seed();
    void members_seed();
    void sales_seed();
    database_seeders();
    ~database_seeders();
};

#endif