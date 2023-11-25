DROP TABLE IF EXISTS Ceny
GO

DROP TABLE IF EXISTS Towary
GO

DROP TABLE IF EXISTS Kursy
GO

CREATE TABLE Towary(ID INT PRIMARY KEY, NazwaTowaru VARCHAR(30))
GO

INSERT INTO Towary VALUES(1, 'Coca-cola')
INSERT INTO Towary VALUES(2, 'Fanta')
INSERT INTO Towary VALUES(3, 'Sprite')
GO

CREATE TABLE Kursy(Waluta VARCHAR(3) PRIMARY KEY, CenaPLN MONEY)
GO

INSERT INTO Kursy VALUES('PLN', 1.00)
INSERT INTO Kursy VALUES('EUR', 4.66)
INSERT INTO Kursy VALUES('USD', 4.25)
GO

CREATE TABLE Ceny(TowarID INT REFERENCES Towary(ID), Waluta VARCHAR(3) REFERENCES Kursy(Waluta), Cena MONEY)
GO

INSERT INTO Ceny VALUES(1, 'PLN', 6.49)
INSERT INTO Ceny VALUES(2, 'PLN', 4.79)
INSERT INTO Ceny VALUES(3, 'PLN', 5.99)
INSERT INTO Ceny VALUES(2, 'EUR', 1.20)
INSERT INTO Ceny VALUES(3, 'EUR', 1.67)
INSERT INTO Ceny VALUES(1, 'USD', 2.45)
INSERT INTO Ceny VALUES(2, 'USD', 1.60)
GO 

/*
ALTER TABLE Ceny NOCHECK CONSTRAINT ALL
DELETE from Kursy WHERE Waluta = 'USD'
ALTER TABLE Ceny CHECK CONSTRAINT ALL
GO
*/

SELECT * FROM Kursy;

DECLARE towary CURSOR FOR SELECT TowarID, Waluta FROM Ceny

OPEN towary

DECLARE @towarid INT, @waluta VARCHAR(3)

FETCH NEXT FROM towary INTO @towarid, @waluta
WHILE (@@FETCH_STATUS = 0)
BEGIN
	IF NOT EXISTS (SELECT Waluta FROM Kursy WHERE Waluta=@waluta)
	BEGIN
		DELETE FROM Ceny WHERE TowarID = @towarid AND Waluta = @waluta
	END
	ELSE
	BEGIN
		DECLARE @cena_in_PLN MONEY
		SET @cena_in_PLN = (SELECT Cena from Ceny WHERE TowarID = @towarid AND Waluta = 'PLN')
		DECLARE @kurs MONEY
		SET @kurs = (SELECT CenaPLN FROM Kursy WHERE Waluta=@waluta)

		UPDATE Ceny SET Cena = ROUND(@cena_in_PLN / @kurs, 2) WHERE TowarID = @towarid AND Waluta = @waluta
	END
	FETCH NEXT FROM towary INTO @towarid, @waluta
END
CLOSE towary
DEALLOCATE towary
GO

SELECT Towary.NazwaTowaru, Ceny.Cena, Ceny.Waluta FROM Ceny JOIN Towary ON Ceny.TowarID = Towary.ID ORDER BY Towary.NazwaTowaru
GO