--Ustawianie poziomów izolacji transakcji
--SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED; -- brudne dane, niepowtarzalnosc odczytow, odczyty fantomow
--SET TRANSACTION ISOLATION LEVEL READ COMMITTED --domyœlny -- niepowtarzalnosc odczytow, odczyty fantomow
--SET TRANSACTION ISOLATION LEVEL REPEATABLE READ -- odczyty fantomow
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE -- Zadne z powyzszych
GO
-- Jakas testowa tabela
DROP TABLE IF EXISTS Ubrania
GO

CREATE TABLE Ubrania (ID INT PRIMARY KEY, Nazwa VARCHAR(20), Cena INT, Ilosc INT)
GO

INSERT INTO Ubrania VALUES (1, 'Bluza', 100, 1)
INSERT INTO Ubrania VALUES (2, 'Spodnie', 120, 6)
INSERT INTO Ubrania VALUES (3, 'Koszulka', 60, 9)
GO

-- Dirty reads

BEGIN TRANSACTION
UPDATE Ubrania SET Ilosc = 0 WHERE ID = 1;
WAITFOR DELAY '00:00:10'
SELECT * FROM Ubrania;
ROLLBACK TRANSACTION
SELECT * FROM Ubrania;

-- Nonrepeatable reads
BEGIN TRANSACTION
SELECT * FROM Ubrania
WAITFOR DELAY '00:00:10'
SELECT * FROM Ubrania;
COMMIT

-- Phantom
BEGIN TRANSACTION
SELECT * FROM Ubrania WHERE Cena < 70;
WAITFOR DELAY '00:00:10'
SELECT * FROM Ubrania WHERE Cena < 70;
COMMIT