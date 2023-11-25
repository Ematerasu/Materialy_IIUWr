SELECT Model.Name, COUNT(Product.ProductID) as Cnt
FROM SalesLT.ProductModel as Model
JOIN SalesLt.Product as Product
ON Model.ProductModelID = Product.ProductModelID
GROUP BY Model.Name
HAVING COUNT(Product.ProductID) > 1;