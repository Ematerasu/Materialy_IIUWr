--SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED; -- brudne dane, niepowtarzalnosc odczytow, odczyty fantomow
--SET TRANSACTION ISOLATION LEVEL READ COMMITTED --domyœlny -- niepowtarzalnosc odczytow, odczyty fantomow
--SET TRANSACTION ISOLATION LEVEL REPEATABLE READ -- odczyty fantomow
SET TRANSACTION ISOLATION LEVEL SERIALIZABLE -- Zadne z powyzszych
GO

-- Dirty reads
SELECT * FROM Ubrania;

-- Nonrepeatable reads
BEGIN TRANSACTION
UPDATE Ubrania SET Ilosc = 0 WHERE ID = 1;
COMMIT

-- Phantom
BEGIN TRANSACTION
INSERT INTO Ubrania VALUES(4, 'Skarpety', 20, 5)
COMMIT