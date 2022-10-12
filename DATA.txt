CREATE TABLE e_customer
(id NUMBER(7)
   CONSTRAINT e_customer_id_nn NOT NULL,
 name VARCHAR2(50)
   CONSTRAINT e_customer_name_nn NOT NULL,
 phone VARCHAR2(25),
 address VARCHAR2(400),
 city VARCHAR2(30),
 state VARCHAR2(20),
 country VARCHAR2(30),
 zip_code VARCHAR2(75),
 credit_rating VARCHAR2(9),
 sales_rep_id NUMBER(7),
 region_id NUMBER(7),
 comments VARCHAR2(255),
     CONSTRAINT e_customer_id_pk PRIMARY KEY (id),
     CONSTRAINT e_customer_credit_rating_ck
        CHECK (credit_rating IN ('EXCELLENT', 'GOOD', 'POOR')));

INSERT INTO e_customer VALUES (
   201, 'Unisports', '55-2066101',
   '72 Via Bahia', 'Sao Paolo', NULL, 'Brazil', NULL,
   'EXCELLENT', 12, 2, NULL);
INSERT INTO e_customer VALUES (
   202, 'OJ Atheletics', '81-20101',
   '6741 Takashi Blvd.', 'Osaka', NULL, 'Japan', NULL,
   'POOR', 14, 4, NULL);
INSERT INTO e_customer VALUES (
   203, 'Delhi Sports', '91-10351',
   '11368 Chanakya', 'New Delhi', NULL, 'India', NULL,
   'GOOD', 14, 4, NULL);
INSERT INTO e_customer VALUES (
   204, 'Womansport', '1-206-104-0103',
   '281 King Street', 'Seattle', 'Washington', 'USA', NULL,
   'EXCELLENT', 11, 1, NULL);
INSERT INTO e_customer VALUES (
   205, 'Kam''s Sporting Goods', '852-3692888',
   '15 Henessey Road', 'Hong Kong', NULL, NULL, NULL,
   'EXCELLENT', 15, 4, NULL);
INSERT INTO e_customer VALUES (
   206, 'Sportique', '33-2257201',
   '172 Rue de Rivoli', 'Cannes', NULL, 'France', NULL,
   'EXCELLENT', 15, 5, NULL);
INSERT INTO e_customer VALUES (
   207, 'Sweet Rock Sports', '234-6036201',
   '6 Saint Antoine', 'Lagos', NULL, 'Nigeria', NULL,
   'GOOD', NULL, 3, NULL);
INSERT INTO e_customer VALUES (
   208, 'Muench Sports', '49-527454',
   '435 Gruenestrasse', 'Stuttgart', NULL, 'Germany', NULL,
   'GOOD', 15, 5, NULL);
INSERT INTO e_customer VALUES (
   209, 'Beisbol Si!', '809-352689',
   '792 Playa Del Mar', 'San Pedro de Macon''s', NULL, 'Dominican Republic',
   NULL, 'EXCELLENT', 11, 1, NULL);
INSERT INTO e_customer VALUES (
   210, 'Futbol Sonora', '52-404562',
   '3 Via Saguaro', 'Nogales', NULL, 'Mexico', NULL,
   'EXCELLENT', 12, 2, NULL);
INSERT INTO e_customer VALUES (
   211, 'Kuhn''s Sports', '42-111292',
   '7 Modrany', 'Prague', NULL, 'Czechoslovakia', NULL,
   'EXCELLENT', 15, 5, NULL);
INSERT INTO e_customer VALUES (
   212, 'Hamada Sport', '20-1209211',
   '57A Corniche', 'Alexandria', NULL, 'Egypt', NULL,
   'EXCELLENT', 13, 3, NULL);
INSERT INTO e_customer VALUES (
   213, 'Big John''s Sports Emporium', '1-415-555-6281',
   '4783 18th Street', 'San Francisco', 'CA', 'USA', NULL,
   'EXCELLENT', 11, 1, NULL);
INSERT INTO e_customer VALUES (
   214, 'Ojibway Retail', '1-716-555-7171',
   '415 Main Street', 'Buffalo', 'NY', 'USA', NULL,
   'POOR', 11, 1, NULL);
INSERT INTO e_customer VALUES (
   215, 'Sporta Russia', '7-3892456',
   '6000 Yekatamina', 'Saint Petersburg', NULL, 'Russia', NULL,
   'POOR', 15, 5, NULL);
COMMIT;

CREATE TABLE e_dept
(id NUMBER(7)
   CONSTRAINT e_dept_id_nn NOT NULL,
 name VARCHAR2(25)
   CONSTRAINT e_dept_name_nn NOT NULL,
 region_id NUMBER(7),
     CONSTRAINT e_dept_id_pk PRIMARY KEY (id),
     CONSTRAINT e_dept_name_region_id_uk UNIQUE (name, region_id));
INSERT INTO e_dept VALUES (
   10, 'Finance', 1);
INSERT INTO e_dept VALUES (
   31, 'Sales', 1);
INSERT INTO e_dept VALUES (
   32, 'Sales', 2);
INSERT INTO e_dept VALUES (
   33, 'Sales', 3);
INSERT INTO e_dept VALUES (
   34, 'Sales', 4);
INSERT INTO e_dept VALUES (
   35, 'Sales', 5);
INSERT INTO e_dept VALUES (
   41, 'Operations', 1);
INSERT INTO e_dept VALUES (
   42, 'Operations', 2);
INSERT INTO e_dept VALUES (
   43, 'Operations', 3);
INSERT INTO e_dept VALUES (
   44, 'Operations', 4);
INSERT INTO e_dept VALUES (
   45, 'Operations', 5);
INSERT INTO e_dept VALUES (
   50, 'Administration', 1);
COMMIT;

CREATE TABLE e_emp
(id NUMBER(7)
   CONSTRAINT e_emp_id_nn NOT NULL,
 last_name VARCHAR2(25)
   CONSTRAINT e_emp_last_name_nn NOT NULL,
 first_name VARCHAR2(25),
 userid VARCHAR2(8),
 start_date DATE,
 comments VARCHAR2(255),
 manager_id NUMBER(7),
 title VARCHAR2(25),
 dept_id NUMBER(7),
 salary NUMBER(11, 2),
 commission_pct NUMBER(4, 2),
     CONSTRAINT e_emp_id_pk PRIMARY KEY (id),
     CONSTRAINT e_emp_userid_uk UNIQUE (userid),
     CONSTRAINT e_emp_commission_pct_ck
        CHECK (commission_pct IN (10, 12.5, 15, 17.5, 20)));

INSERT INTO e_emp VALUES (1, 'Velasquez', 'Carmen', 'cvelasqu', '1990-03-03', NULL, NULL, 'President', 50, 2500, NULL);
INSERT INTO e_emp VALUES (3, 'Nagayama', 'Midori', 'mnagayam','1991-06-17', NULL, 1, 'VP, Sales',31, 1400, NULL);
INSERT INTO e_emp VALUES (
   2, 'Ngao', 'LaDoris', 'lngao',
   '1990-08-03', NULL, 1, 'VP, Operations',
   41, 1450, NULL);
INSERT INTO e_emp VALUES (
   4, 'Quick-To-See', '03k', 'mquickto',
   '1990-07-04', NULL, 1, 'VP, Finance',
   10, 1450, NULL);
INSERT INTO e_emp VALUES (
   5, 'Ropeburn', 'Audry', 'aropebur',
   '1990-04-03', NULL, 1, 'VP, Administration',
   50, 1550, NULL);
INSERT INTO e_emp VALUES (
   6, 'Urguhart', 'Molly', 'murguhar',
   '1991-01-18', NULL, 2, 'Warehouse Manager',
   41, 1200, NULL);
INSERT INTO e_emp VALUES (
   7, 'Menchu', 'Roberta', 'rmenchu',
   '1990-05-14', NULL, 2, 'Warehouse Manager',
   42, 1250, NULL);
INSERT INTO e_emp VALUES (
   8, 'Biri', 'Ben', 'bbiri',
   '1990-07-04', NULL, 2, 'Warehouse Manager',
   43, 1100, NULL);
INSERT INTO e_emp VALUES (
   9, 'Catchpole', 'Antoinette', 'acatchpo',
   '1992-09-02', NULL, 2, 'Warehouse Manager',
   44, 1300, NULL);
INSERT INTO e_emp VALUES (
   10, 'Havel', '03ta', 'mhavel',
   '1991-02-27', NULL, 2, 'Warehouse Manager',
   45, 1307, NULL);
INSERT INTO e_emp VALUES (
   11, 'Magee', 'Colin', 'cmagee',
   '1990-05-14', NULL, 3, 'Sales Representative',
   31, 1400, 10);
INSERT INTO e_emp VALUES (
   12, 'Giljum', 'Henry', 'hgiljum',
   '1992-01-18', NULL, 3, 'Sales Representative',
   32, 1490, 12.5);
INSERT INTO e_emp VALUES (
   13, 'Sedeghi', 'Yasmin', 'ysedeghi',
   '1991-02-18', NULL, 3, 'Sales Representative',
   33, 1515, 10);
INSERT INTO e_emp VALUES (
   14, 'Nguyen', 'Mai', 'mnguyen',
   '1992-01-22', NULL, 3, 'Sales Representative',
   34, 1525, 15);
INSERT INTO e_emp VALUES (
   15, 'Dumas', 'Andre', 'adumas',
   '1991-09-10', NULL, 3, 'Sales Representative',
   35, 1450, 17.5);
INSERT INTO e_emp VALUES (
   16, 'Maduro', 'Elena', 'emaduro',
   '1992-07-02', NULL, 6, 'Stock Clerk',
   41, 1400, NULL);
INSERT INTO e_emp VALUES (
   17, 'Smith', 'George', 'gsmith',
   '1990-08-03', NULL, 6, 'Stock Clerk',
   41, 940, NULL);
INSERT INTO e_emp VALUES (
   18, 'Nozaki', 'Akira', 'anozaki',
   '1991-09-02', NULL, 7, 'Stock Clerk',
   42, 1200, NULL);
INSERT INTO e_emp VALUES (
   19, 'Patel', 'Vikram', 'vpatel',
   '1991-06-08', NULL, 7, 'Stock Clerk',
   42, 795, NULL);
INSERT INTO e_emp VALUES (
   20, 'Newman', 'Chad', 'cnewman',
   '1991-1-07', NULL, 8, 'Stock Clerk',
   43, 750, NULL);
INSERT INTO e_emp VALUES (
   21, 'Makarian', 'Alexander', 'amarkari',
   '1991-6-05', NULL, 8, 'Stock Clerk',
   43, 850, NULL);
INSERT INTO e_emp VALUES (
   22, 'Chang', 'Eddie', 'echang',
   '1990-11-30', NULL, 9, 'Stock Clerk',
   44, 800, NULL);
INSERT INTO e_emp VALUES (
   23, 'Patel', 'Radha', 'rpatel',
   '1990-7-10', NULL, 9, 'Stock Clerk',
   34, 795, NULL);
INSERT INTO e_emp VALUES (
   24, 'Dancs', 'Bela', 'bdancs',
   '1991-03-17', NULL, 10, 'Stock Clerk',
   45, 860, NULL);
INSERT INTO e_emp VALUES (
   25, 'Schwartz', 'Sylvie', 'sschwart',
   '1991-09-05', NULL, 10, 'Stock Clerk',
   45, 1100, NULL);
CREATE TABLE e_ord
(id NUMBER(7)
   CONSTRAINT e_ord_id_nn NOT NULL,
 customer_id NUMBER(7)
   CONSTRAINT e_ord_customer_id_nn NOT NULL,
 date_ordered DATE,
 date_shipped DATE,
 sales_rep_id NUMBER(7),
 total NUMBER(11, 2),
 payment_type VARCHAR2(6),
 order_filled VARCHAR2(1),
     CONSTRAINT e_ord_id_pk PRIMARY KEY (id),
     CONSTRAINT e_ord_payment_type_ck
        CHECK (payment_type in ('CASH', 'CREDIT')),
     CONSTRAINT e_ord_order_filled_ck
       CHECK (order_filled in ('Y', 'N')));
INSERT INTO e_ord VALUES (
   100, 204, '1992-08-31', '1992-09-10',
   11, 601100, 'CREDIT', 'Y');
INSERT INTO e_ord VALUES (
   101, 205, '1992-08-31', '1992-09-15',
   14, 8056.6, 'CREDIT', 'Y');
INSERT INTO e_ord VALUES (
   102, 206, '1992-09-01', '1992-09-08',
   15, 8335, 'CREDIT', 'Y');
INSERT INTO e_ord VALUES (
   103, 208, '1992-09-02', '1992-09-22',
   15, 377, 'CASH', 'Y');
INSERT INTO e_ord VALUES (
   104, 208, '1992-09-03', '1992-09-23',
   15, 32430, 'CREDIT', 'Y');
INSERT INTO e_ord VALUES (
   105, 209, '1992-09-04', '1992-09-18',
   11, 2722.24, 'CREDIT', 'Y');
INSERT INTO e_ord VALUES (
   106, 210, '1992-09-07', '1992-09-15',
   12, 15634, 'CREDIT', 'Y');
INSERT INTO e_ord VALUES (
   107, 211, '1992-09-07', '1992-09-21',
   15, 142171, 'CREDIT', 'Y');
INSERT INTO e_ord VALUES (
   108, 212, '1992-09-07', '1992-09-10',
   13, 149570, 'CREDIT', 'Y');
INSERT INTO e_ord VALUES (
   109, 213, '1992-09-08', '1992-09-28',
   11, 1020935, 'CREDIT', 'Y');
INSERT INTO e_ord VALUES (
   110, 214, '1992-09-09', '1992-09-21',
   11, 1539.13, 'CASH', 'Y');
INSERT INTO e_ord VALUES (
   111, 204, '1992-09-09', '1992-09-21',
   11, 2770, 'CASH', 'Y');
INSERT INTO e_ord VALUES (
   97, 201, '1992-0828', '1992-09-17',
   12, 84000, 'CREDIT', 'Y');
INSERT INTO e_ord VALUES (
   98, 202, '1992-08-31', '1992-09-10',
   14, 595, 'CASH', 'Y');
INSERT INTO e_ord VALUES (
   99, 203, '1992-08-31', '1992-09-18',
   14, 7707, 'CREDIT', 'Y');
INSERT INTO e_ord VALUES (
   112, 210, '1992-08-31', '1992-09-10',
   12, 550, 'CREDIT', 'Y');

CREATE TABLE e_region
(id                         NUMBER(7)
   CONSTRAINT e_region_id_nn NOT NULL,
 name                       VARCHAR2(50)
   CONSTRAINT e_region_name_nn NOT NULL,
     CONSTRAINT e_region_id_pk PRIMARY KEY (id),
     CONSTRAINT e_region_name_uk UNIQUE (name));

INSERT INTO e_region VALUES (
   1, 'North America');
INSERT INTO e_region VALUES (
   2, 'South America');
INSERT INTO e_region VALUES (
   3, 'Africa / Middle East');
INSERT INTO e_region VALUES (
   4, 'Asia');
INSERT INTO e_region VALUES (
   5, 'Europe');
COMMIT;


  
