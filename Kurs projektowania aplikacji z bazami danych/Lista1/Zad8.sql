/*
SELECT sales.SalesOrderID, sales.ShipDate, sales.OrderDate
FROM SalesLT.SalesOrderHeader as sales;

--ALTER TABLE SalesLT.SalesOrderHeader NOCHECK CONSTRAINT CK_SalesOrderHeader_ShipDate;
--ALTER TABLE SalesLT.SalesOrderHeader CHECK CONSTRAINT CK_SalesOrderHeader_ShipDate;

UPDATE sales
SET sales.ShipDate = '2008-05-30 00:00:00.000'
FROM SalesLT.SalesOrderHeader as sales
WHERE sales.SalesOrderID=71774;
*/

/* NAPRAWKA
UPDATE sales
SET sales.ShipDate = '2008-06-08 00:00:00.000'
FROM SalesLT.SalesOrderHeader as sales
WHERE sales.SalesOrderID=71774;
*/

SELECT sales.SalesOrderID, sales.ShipDate, sales.OrderDate
FROM SalesLT.SalesOrderHeader as sales;

