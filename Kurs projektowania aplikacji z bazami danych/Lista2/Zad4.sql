DROP PROCEDURE IF EXISTS zad4;
GO

DROP TYPE IF EXISTS Czytelnicy
GO

CREATE TYPE Czytelnicy AS TABLE(czytelnik_id INT)
GO

CREATE PROCEDURE zad4 @czytelnik_ids Czytelnicy READONLY
AS
BEGIN
	SELECT ids.czytelnik_id, SUM(Wypozyczenie.Liczba_Dni) AS suma, Czytelnik.Nazwisko
	FROM
		@czytelnik_ids as ids
	JOIN Czytelnik
	ON Czytelnik.Czytelnik_ID=ids.czytelnik_id
	JOIN Wypozyczenie
	ON Wypozyczenie.Czytelnik_ID=Czytelnik.Czytelnik_ID
	GROUP BY ids.czytelnik_id, Czytelnik.Nazwisko
END
GO

DECLARE @id_czytelnicy Czytelnicy;
INSERT INTO @id_czytelnicy VALUES(1);
INSERT INTO @id_czytelnicy VALUES(2);
INSERT INTO @id_czytelnicy VALUES(3);

EXEC zad4 @id_czytelnicy
GO