SELECT Address.City, COUNT(CustomerAddress.CustomerID) as Num_of_customers, COUNT(Customer.SalesPerson) as Num_of_SalesPerson
FROM SalesLT.Address as Address,
	 SalesLT.CustomerAddress as CustomerAddress,
	 SalesLT.Customer as Customer
WHERE Address.AddressID = CustomerAddress.AddressID
	  AND Customer.CustomerID=CustomerAddress.CustomerID
GROUP BY Address.City;