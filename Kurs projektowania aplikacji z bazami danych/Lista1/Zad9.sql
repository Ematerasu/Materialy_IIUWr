/*
ALTER TABLE SalesLT.Customer
ADD CreditCardNumber VARCHAR(20);

UPDATE SalesLT.SalesOrderHeader
SET CreditCardApprovalCode = SalesLT.SalesOrderHeader.SalesOrderID
WHERE SalesLT.SalesOrderHeader.SalesOrderID=71774 OR 
	SalesLT.SalesOrderHeader.SalesOrderID=71776 OR
	SalesLT.SalesOrderHeader.SalesOrderID=71780;
*/

UPDATE customer
SET customer.CreditCardNumber = 'X'
FROM SalesLT.Customer as customer
JOIN SalesLT.SalesOrderHeader as sale ON sale.CustomerID=customer.CustomerID
WHERE sale.CreditCardApprovalCode IS NOT NULL;

SELECT customer.CustomerID, customer.CreditCardNumber, sale.CreditCardApprovalCode
FROM SalesLT.Customer as customer
JOIN SalesLT.SalesOrderHeader as sale on sale.CustomerID=customer.CustomerID