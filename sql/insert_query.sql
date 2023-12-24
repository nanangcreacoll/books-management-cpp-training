-- Active: 1702918408133@@127.0.0.1@3306@book_management
INSERT INTO books(name,author,price,qty) values('Buku Pintar Membuat Cake', 'Diah Surjani Ananto', 42000, 5);

INSERT INTO employees(
    name, 
    addr_line1, 
    addr_line2, 
    addr_city, 
    addr_state, 
    phone_num, 
    date_of_joining, 
    salary,
    mgr_status
    ) 
values(
    'Bambang',
    'Jalan Babarsari no. 22',
    'Caturtunggal',
    'Sleman',
    'DI Yogyakarta',
    LPAD(FLOOR(RAND() * 999999999999), 12, '0'),
    CURDATE(),
    2320000,
    'F'
);

INSERT INTO members(
    name, 
    addr_line1, 
    addr_line2, 
    addr_city, 
    addr_state,
    phone_num,
    beg_date,
    end_date,
    valid
) 
values(
    'Ivan',
    'Jalan Istana no. 32',
    'Soe',
    'Timur Tengah Selatan',
    'Nusa Tenggara Timur',
    LPAD(FLOOR(RAND() * 999999999999), 12, '0'),
    CURDATE(),
    Date_add(curdate(), INTERVAL 1 YEAR),
    'valid'
);

INSERT INTO sales() values();

INSERT INTO suppliers(
    name,
    phone_num,
    addr_line1,
    addr_line2,
    addr_city,
    addr_state
) 
values(
    'CV. Tirta Buana Media',
    LPAD(FLOOR(RAND() * 999999999999), 12, '0'),
    'Perumahan Tirta Buana Blok H No. 33',
    'Cepor, Sendangtirto, Berbah', 
    'Sleman',
    'DI. Yogyakarta'
);

INSERT INTO purchases(
    book_id,
    sup_id,
    qty,
    dt_ordered,
    estim_deliv,
    received
)
VALUES(
    4,
    1,
    3,
    CURDATE(),
    DATE_ADD(CURDATE(), INTERVAL 2 DAY),
    'T'
);

INSERT INTO sales(
    member_id,
    book_id,
    qty,
    amount,
    date_sales
)
VALUES (
    2,
    6,
    5,
    580000,
    CURDATE()
);

