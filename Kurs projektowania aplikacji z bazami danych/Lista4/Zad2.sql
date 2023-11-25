CREATE TABLE Tabelka_base (
		ID INT PRIMARY KEY, 
		Pacjent VARCHAR(50),
		Adres VARCHAR(100),
		Data_i_miejsce_wizyty VARCHAR(50),
		Kwota MONEY,
		Lekarz VARCHAR(50),
		Powod_wizyty VARCHAR(200)
	)

-- 1NF, nie chcemy trzyma� wielu informacji w jednym polu
CREATE TABLE Tabelka_1nf (
		ID INT PRIMARY KEY, 
		Pacjent VARCHAR(50),
		Adres VARCHAR(50),
		Kod_pocztowy VARCHAR(6),
		Miasto VARCHAR(20),
		Data_wizyty DATE,
		Godzina TIME,
		Pok�j INT,
		Kwota MONEY,
		Lekarz VARCHAR(50),
		Typ_wizyty VARCHAR(20),
		Powod_wizyty VARCHAR(100)
	)
-- Przyklad:
INSERT INTO Tabelka_1nf VALUES
(1, 'Jan Kot', 'ul. Dolna 6', '44-444', 'B�r', '2029-02-01', '12:30', '12', 300, 'Marek Z�bek', 'Dentystyczny', 'zalozenie...');

-- 2NF, Chcemy podzieli� na kilka mniejszych tabel
--CREATE TABLE Pacjenci (ID INT PRIMARY KEY, Pacjent VARCHAR(50), Adres VARCHAR(50), Kod_pocztowy VARCHAR(6), Miasto VARCHAR(20));
--CREATE TABLE Wizyty (ID_Pacjenta INT REFERENCES Pacjenci(ID), Data_wizyty DATE, Pok�j INT, Kwota MONEY, Lekarz VARCHAR(50), Typ_wizyty VARCHAR(20), Powod_wizyty VARCHAR(100));

-- Mo�na r�wnie� za�o�y� �e kwota jest w pe�ni zale�na od typu i powodu wizyty o ile mo�na je ograniczy� do jakiej� liczby (nie s�
-- wymy�lan� przez Pani� w recepcji na bie��co, a patrz�c w tre�� zadania wygl�daj� jakby by�y zdefiniowane),
-- podobnie je�li Lekarz ma sw�j wyznaczony pok�j to mo�na r�wnie� utworzy� tabel� "Lekarze" w
-- kt�rej znajdzie si� numer pokoju a w samej tabeli Wizyty da� ID lekarza. Tabele przy takich za�o�eniach:

CREATE TABLE Pacjenci (ID INT PRIMARY KEY, Pacjent VARCHAR(50), Adres VARCHAR(50), Kod_pocztowy VARCHAR(6), Miasto VARCHAR(20));
CREATE TABLE Lekarze (ID INT PRIMARY KEY, Lekarz VARCHAR(50), Pokoj INT);
CREATE TABLE Rodzaje_wizyt (ID INT PRIMARY KEY, Typ VARCHAR(20), Pow�d VARCHAR(50), Kwota MONEY)
CREATE TABLE Wizyty (ID_Pacjenta INT REFERENCES Pacjenci(ID), Data_wizyty DATE, Godzina TIME, ID_Lekarza INT REFERENCES Lekarze(ID), Rodzaj_wizyty INT REFERENCES Rodzaje_wizyt(ID));

-- Przyk�ad:
INSERT INTO Pacjenci VALUES(1, 'Jan Kot', 'ul. Dolna 6', '44-444', 'B�r');
INSERT INTO Wizyty VALUES (1, '2029-02-01', '12:30', 1, 2);
INSERT INTO Lekarze VALUES (1, 'Marek Z�bek', 12);
INSERT INTO Rodzaje_wizyt VALUES (2, 'Dentystyczny', 'Za�o�enie protezy..', 300);

-- 3NF
-- Id�c dalej z za�o�eniem o Lekarzu kt�ry ma sw�j pok�j, mo�emy pozby� si� tego pola
CREATE TABLE Lekarze_3NF (ID INT PRIMARY KEY, Lekarz VARCHAR(50));
-- Mozna rowniez na podstawie lekarza lub powodu wizyty wywnioskowac typ wizyty
CREATE TABLE Rodzaje_wizyt_3NF (ID INT PRIMARY KEY, Pow�d VARCHAR(50), Kwota MONEY)


