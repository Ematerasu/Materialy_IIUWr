SELECT pcParent.Name as CategoryName, p.Name as ProductName
FROM SalesLT.ProductCategory pc
JOIN SalesLT.Product p ON p.ProductCategoryID = pc.ProductCategoryID
JOIN SalesLT.ProductCategory pcParent ON pcParent.ProductCategoryID = pc.ParentProductCategoryID;

--Jak wyglada to drzewo, jest ono wysokosci 1
SELECT pc1.Name, pc2.Name
FROM SalesLT.ProductCategory pc1
JOIN SalesLT.ProductCategory pc2 ON pc1.ProductCategoryID=pc2.ParentProductCategoryID