DROP PROCEDURE IF EXISTS create_czytelnik;
GO


CREATE PROCEDURE create_czytelnik @pesel VARCHAR(30), @nazwisko VARCHAR(30), @miasto VARCHAR(30), @data VARCHAR(10), @ostatnie VARCHAR(10)
AS
BEGIN
	IF (LEN(@pesel) != 11 OR ISNUMERIC(@pesel) = 0)
	BEGIN
		;THROW 60000, 'ZLY PESEL', 1;
	END

	DECLARE @first_letter CHAR(1)
	SET @first_letter = LEFT(@nazwisko, 1)
	IF (LEN(@nazwisko) < 2 OR @first_letter = LOWER(@first_letter) COLLATE Latin1_General_CS_AI)
	BEGIN
		;THROW 60000, 'ZLE NAZWISKO', 2;
	END

	IF (ISDATE(@data) = 0)
	BEGIN
		;THROW 60000, 'ZLA DATA', 3;
	END

	DECLARE @rok INT;
	DECLARE @miesiac INT;
	DECLARE @dzien INT;

	SET @rok = CAST(YEAR(@data) as INT);
	SET @miesiac = CAST(MONTH(@data) as INT);
	SET @dzien = DAY(@data)

	IF (@rok >= 2000)
	BEGIN
		SET @miesiac = @miesiac + 20
	END

	SET @rok = CAST(@rok as VARCHAR);

	IF (LEFT(@pesel, 2) != RIGHT(@rok, 2)
		OR CAST(SUBSTRING(@pesel, 3, 2) as INT) != @miesiac
		OR CAST(SUBSTRING(@pesel, 5, 2) as INT) != @dzien
		)
	BEGIN
		;THROW 60000, 'NIEZGODNY PESEL Z DATA URODZENIA', 4;
	END

	INSERT INTO Czytelnik VALUES(@pesel, @nazwisko, @miasto, @data, @ostatnie);
END
GO

DELETE FROM Czytelnik WHERE PESEL='00210108658';
GO

DELETE FROM Czytelnik WHERE PESEL='99031508658';
GO

EXEC create_czytelnik @pesel='00210108658', @nazwisko='Kowalski', @miasto='Warszawa', @data='2000-01-01', @ostatnie='2022-03-15'
GO

EXEC create_czytelnik @pesel='99031508658', @nazwisko='Kowalski2', @miasto='Lublin', @data='1999-03-15', @ostatnie='2022-03-15'
GO

SELECT * FROM Czytelnik;
GO