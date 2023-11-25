SELECT Customer.LastName, Customer.FirstName, SUM(Detail.UnitPriceDiscount) AS Saved 
FROM SalesLT.Customer as Customer,
	SalesLT.SalesOrderHeader as Header,
	SalesLT.SalesOrderDetail as Detail
WHERE
    Customer.CustomerID = Header.CustomerID
    AND Detail.SalesOrderID = Header.SalesOrderID
GROUP BY Customer.FirstName, Customer.LastName;