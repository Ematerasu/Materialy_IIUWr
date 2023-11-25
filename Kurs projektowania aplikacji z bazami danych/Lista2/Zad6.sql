DROP PROCEDURE IF EXISTS zad6;
GO

DROP TYPE IF EXISTS Product_IDS
GO

CREATE TYPE Product_IDS AS TABLE(id INT)
GO

CREATE PROCEDURE zad6 @products_ids Product_IDS READONLY, @data DATE
AS
BEGIN
    IF EXISTS (SELECT * FROM SalesLT.Product WHERE ProductID in (SELECT id FROM @products_ids) AND DiscontinuedDate IS NOT NULL)
    BEGIN
        ;THROW 60000, 'Któryœ produkt ma ustawione DiscontinuedDate', 1
    END

    UPDATE SalesLT.Product SET DiscontinuedDate = @data
    WHERE ProductID IN (SELECT id FROM @products_ids)

END
GO

DECLARE @id Product_IDS
INSERT INTO @id VALUES (680), (706), (718)

DECLARE @date DATE = '2022-03-22'

EXEC zad6 @products_ids=@id, @data=@date
GO

-- Wyczyœæ baze
--UPDATE SalesLT.Product SET DiscontinuedDate = NULL WHERE DiscontinuedDate IS NOT NULL