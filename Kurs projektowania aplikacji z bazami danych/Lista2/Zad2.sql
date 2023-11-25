DROP TABLE IF EXISTS imiona
DROP TABLE IF EXISTS nazwiska
DROP TABLE IF EXISTS dane
GO
CREATE TABLE imiona(id INT PRIMARY KEY, imie VARCHAR(30))
GO

CREATE TABLE nazwiska(id INT PRIMARY KEY, nazwisko VARCHAR(30))
GO

CREATE TABLE dane(imie VARCHAR(30), nazwisko VARCHAR(30))
GO

INSERT INTO imiona VALUES(1, 'imie1')
INSERT INTO imiona VALUES(2, 'imie2')
INSERT INTO imiona VALUES(3, 'imie3')
INSERT INTO imiona VALUES(4, 'imie4')

INSERT INTO nazwiska VALUES(1, 'nazwisko1')
INSERT INTO nazwiska VALUES(2, 'nazwisko2')
INSERT INTO nazwiska VALUES(3, 'nazwisko3')
INSERT INTO nazwiska VALUES(4, 'nazwisko4')

DROP PROCEDURE IF EXISTS zad2
GO

CREATE PROCEDURE zad2 @n INT
AS
BEGIN
	DECLARE @ilosc_imion INT
	DECLARE @ilosc_nazwisk INT
	DECLARE @polowa INT

	SET @ilosc_imion = (SELECT COUNT(id) FROM imiona)
	SET @ilosc_nazwisk = (SELECT COUNT(id) FROM nazwiska)
	SET @polowa = @ilosc_imion * @ilosc_nazwisk / 2

	IF (@polowa < @n)
		BEGIN
			;THROW 60000, 'n musi byc niewieksze od polowy wszystkich mozliwosci', 1;
		END

	DECLARE @i INT
	SET @i = 0

	WHILE(@i < @n)
	BEGIN
		DECLARE @imie VARCHAR(30)
		DECLARE @nazwisko VARCHAR(30)
		set @imie = (SELECT TOP 1 imie FROM imiona ORDER BY NEWID())
		set @nazwisko = (SELECT TOP 1 nazwisko FROM nazwiska ORDER BY NEWID())
		IF NOT EXISTS (SELECT * FROM dane WHERE imie=@imie AND nazwisko=@nazwisko)
		BEGIN
			INSERT INTO dane VALUES(@imie, @nazwisko)
			SET @i = @i + 1
		END
	END
	
END
GO
EXEC zad2 @n = 5
GO

SELECT imie, nazwisko FROM dane
GO