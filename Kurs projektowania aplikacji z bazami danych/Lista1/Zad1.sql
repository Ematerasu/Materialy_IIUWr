SELECT DISTINCT Address.City, Sale.ShipDate, Sale.DueDate
FROM SalesLT.Address as Address
JOIN SalesLT.SalesOrderHeader as Sale
ON Address.AddressID = Sale.ShipToAddressID;


SELECT DISTINCT Address.City, Sale.ShipDate, Sale.DueDate
FROM SalesLT.Address as Address
JOIN SalesLT.SalesOrderHeader as Sale
ON Address.AddressID = Sale.ShipToAddressID
WHERE Sale.ShipDate <= Sale.DueDate
ORDER BY City;