DROP TABLE IF EXISTS Bufor
GO
DROP TABLE IF EXISTS Historia
GO
DROP TABLE IF EXISTS Parametry
GO
DROP TRIGGER IF EXISTS zad3;
GO

CREATE TABLE Bufor(ID INT IDENTITY PRIMARY KEY, AdresUrl VARCHAR(50), OstatnieWejscie DATETIME)
GO
CREATE TABLE Historia(ID INT IDENTITY PRIMARY KEY, AdresUrl VARCHAR(50), OstatnieWejscie DATETIME)
GO
CREATE TABLE Parametry(nazwa VARCHAR(50), wartosc INT)
GO

INSERT INTO Parametry VALUES('max_cache', 3) --3 powinno byc dobra liczba na potrzebe zadania, latwo pokazac rzeczy
GO

CREATE TRIGGER zad3 ON Bufor INSTEAD OF INSERT
AS
BEGIN
	DECLARE @toinsert_AdresUrl varchar(50), @toinsert_OstatnieWejscie DATETIME;
	SET @toinsert_AdresUrl = (SELECT AdresUrl FROM INSERTED)
	SET @toinsert_OstatnieWejscie = (SELECT OstatnieWejscie FROM INSERTED)	

	IF EXISTS (SELECT * FROM Bufor WHERE AdresUrl = @toinsert_AdresUrl)
	BEGIN
		UPDATE Bufor SET OstatnieWejscie = @toinsert_OstatnieWejscie WHERE AdresUrl = @toinsert_AdresUrl;
	END	
	ELSE
	BEGIN
		IF ((SELECT COUNT(*) FROM Bufor) < (SELECT wartosc FROM Parametry))
		BEGIN
			INSERT INTO Bufor VALUES (@toinsert_AdresUrl, @toinsert_OstatnieWejscie)
		END
		ELSE
		BEGIN
			DECLARE @temp_ID INT, @temp_AdresUrl varchar(50), @temp_OstatnieWejscie DATETIME
			SET @temp_ID = (SELECT TOP 1 ID FROM Bufor ORDER BY OstatnieWejscie)
			SET @temp_AdresUrl = (SELECT TOP 1 AdresUrl FROM Bufor ORDER BY OstatnieWejscie)
			SET @temp_OstatnieWejscie = (SELECT TOP 1 OstatnieWejscie FROM Bufor ORDER BY OstatnieWejscie)

			DELETE FROM Bufor WHERE ID=@temp_ID

			IF EXISTS (SELECT * FROM Historia WHERE AdresUrl=@temp_AdresUrl)
				UPDATE Historia SET OstatnieWejscie = @temp_OstatnieWejscie WHERE AdresUrl = @temp_AdresUrl
			ELSE
				INSERT INTO Historia VALUES(@temp_AdresUrl, @temp_OstatnieWejscie)

			INSERT INTO Bufor VALUES (@toinsert_AdresUrl, @toinsert_OstatnieWejscie)
		END
	END
END
GO

INSERT INTO Bufor VALUES('ii.uni.wroc.pl', '2022-03-27 11:30:00')
--INSERT INTO Bufor VALUES('ii.uni.wroc.pl', '2022-03-27 11:31:00') -- update
--INSERT INTO Bufor VALUES('facebook.com', '2022-03-27 11:32:00')
--INSERT INTO Bufor VALUES('youtube.com', '2022-03-27 11:35:00')
--INSERT INTO Bufor VALUES('twitch.tv', '2022-03-27 11:37:00') -- wywali ii.uni.wroc do historii bo bufor ma rozmiar 3
--INSERT INTO Bufor VALUES('ii.uni.wroc.pl', '2022-03-27 11:40:00')
--INSERT INTO Bufor VALUES('youtube.com', '2022-03-27 11:42:00')
--INSERT INTO Bufor VALUES('twitch.tv', '2022-03-27 11:44:00')
--INSERT INTO Bufor VALUES('twitter.com', '2022-03-27 11:50:00') -- wywali ii.uni.wroc do historii ale tylko update'uje tam czas
GO

SELECT AdresUrl, OstatnieWejscie FROM Bufor ORDER BY OstatnieWejscie DESC
SELECT AdresUrl, OstatnieWejscie FROM Historia ORDER BY OstatnieWejscie DESC
GO