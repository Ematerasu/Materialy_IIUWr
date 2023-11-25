DROP TABLE IF EXISTS OrdersToProcess;

CREATE TABLE OrdersToProcess(
	SalesOrderID INT PRIMARY KEY,
	Delayed BIT
);

MERGE OrdersToProcess AS o
USING SalesLT.SalesOrderHeader AS s
ON o.SalesOrderID = s.SalesOrderID
WHEN MATCHED AND ((s.DueDate < GETDATE() AND  o.delayed = 0 ) OR (s.DueDate >= GETDATE() AND o.delayed = 1))
THEN UPDATE SET o.Delayed = (CASE 
								WHEN s.DueDate < GETDATE()
								THEN 1 
								ELSE 0
							END)
WHEN NOT MATCHED THEN 
INSERT (SalesOrderID, Delayed)
VALUES (s.SalesOrderID, (CASE 
							WHEN s.DueDate < GETDATE() 
							THEN 1 
							ELSE 0 
						END));

SELECT o.SalesOrderID, o.Delayed, h.DueDate
FROM OrdersToProcess o
JOIN SalesLT.SalesOrderHeader h
ON o.SalesOrderID=h.SalesOrderID;
