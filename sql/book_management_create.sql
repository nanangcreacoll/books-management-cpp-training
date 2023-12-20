-- Active: 1702918408133@@127.0.0.1@3306@book_management

DROP DATABASE book_management;
CREATE DATABASE book_management
    DEFAULT CHARACTER SET utf8mb4;

USE book_management;

--books
CREATE TABLE books
(
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255),
    author VARCHAR(255),
    price INT,
    qty INT
);

--suppliers
CREATE TABLE suppliers
(
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255),
    phone_num BIGINT,
    addr_line1 VARCHAR(255),
    addr_line2 VARCHAR(255),
    addr_city VARCHAR(255),
    addr_state VARCHAR(255)
);

--purchases
CREATE TABLE purchases
(
    order_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    book_id INT,
    sup_id INT,
    qty INT,
    dt_ordered DATE,
    estim_deliv INT,
    received CHAR,
    FOREIGN KEY (book_id) REFERENCES books(id),
    FOREIGN KEY (sup_id) REFERENCES suppliers(id)
);

--employees
CREATE TABLE employees
(
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255),
    addr_line1 VARCHAR(255),
    addr_line2 VARCHAR(255),
    addr_city VARCHAR(255),
    addr_state VARCHAR(255),
    phone_num BIGINT,
    date_of_joining DATE,
    salary BIGINT,
    mgr_status VARCHAR(255)
);

--members
CREATE TABLE members
(
    id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(255),
    addr_line1 VARCHAR(255),
    addr_line2 VARCHAR(255),
    addr_city VARCHAR(255),
    addr_state VARCHAR(255),
    phone_num BIGINT,
    beg_date DATE,
    end_date DATE,
    valid VARCHAR(255)
);

CREATE TABLE sales
(
    invoice_id INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    member_id INT,
    book_id INT,
    qty INT,
    amount INT,
    date_sales DATE,
    FOREIGN KEY (member_id) REFERENCES members(id),
    FOREIGN KEY (book_id) REFERENCES books(id)
);