-- Active: 1702918408133@@127.0.0.1@3306

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
    phone_nume BIGINT,
    addr_line1 VARCHAR(255),
    addr_line2 VARCHAR(255),
    addr_city VARCHAR(255),
    addr_state VARCHAR(255),
);
