CREATE TABLE Tabelka_base (
		ID INT PRIMARY KEY, 
		Pacjent VARCHAR(50),
		Adres VARCHAR(100),
		Data_i_miejsce_wizyty VARCHAR(50),
		Kwota MONEY,
		Lekarz VARCHAR(50),
		Powod_wizyty VARCHAR(200)
	)

-- 1NF, nie chcemy trzymaæ wielu informacji w jednym polu
CREATE TABLE Tabelka_1nf (
		ID INT PRIMARY KEY, 
		Pacjent VARCHAR(50),
		Adres VARCHAR(50),
		Kod_pocztowy VARCHAR(6),
		Miasto VARCHAR(20),
		Data_wizyty DATE,
		Godzina TIME,
		Pokój INT,
		Kwota MONEY,
		Lekarz VARCHAR(50),
		Typ_wizyty VARCHAR(20),
		Powod_wizyty VARCHAR(100)
	)
-- Przyklad:
INSERT INTO Tabelka_1nf VALUES
(1, 'Jan Kot', 'ul. Dolna 6', '44-444', 'Bór', '2029-02-01', '12:30', '12', 300, 'Marek Z¹bek', 'Dentystyczny', 'zalozenie...');

-- 2NF, Chcemy podzieliæ na kilka mniejszych tabel
--CREATE TABLE Pacjenci (ID INT PRIMARY KEY, Pacjent VARCHAR(50), Adres VARCHAR(50), Kod_pocztowy VARCHAR(6), Miasto VARCHAR(20));
--CREATE TABLE Wizyty (ID_Pacjenta INT REFERENCES Pacjenci(ID), Data_wizyty DATE, Pokój INT, Kwota MONEY, Lekarz VARCHAR(50), Typ_wizyty VARCHAR(20), Powod_wizyty VARCHAR(100));

-- Mo¿na równie¿ za³o¿yæ ¿e kwota jest w pe³ni zale¿na od typu i powodu wizyty o ile mo¿na je ograniczyæ do jakiejœ liczby (nie s¹
-- wymyœlanê przez Pani¹ w recepcji na bie¿¹co, a patrz¹c w treœæ zadania wygl¹daj¹ jakby by³y zdefiniowane),
-- podobnie jeœli Lekarz ma swój wyznaczony pokój to mo¿na równie¿ utworzyæ tabelê "Lekarze" w
-- której znajdzie siê numer pokoju a w samej tabeli Wizyty daæ ID lekarza. Tabele przy takich za³o¿eniach:

CREATE TABLE Pacjenci (ID INT PRIMARY KEY, Pacjent VARCHAR(50), Adres VARCHAR(50), Kod_pocztowy VARCHAR(6), Miasto VARCHAR(20));
CREATE TABLE Lekarze (ID INT PRIMARY KEY, Lekarz VARCHAR(50), Pokoj INT);
CREATE TABLE Rodzaje_wizyt (ID INT PRIMARY KEY, Typ VARCHAR(20), Powód VARCHAR(50), Kwota MONEY)
CREATE TABLE Wizyty (ID_Pacjenta INT REFERENCES Pacjenci(ID), Data_wizyty DATE, Godzina TIME, ID_Lekarza INT REFERENCES Lekarze(ID), Rodzaj_wizyty INT REFERENCES Rodzaje_wizyt(ID));

-- Przyk³ad:
INSERT INTO Pacjenci VALUES(1, 'Jan Kot', 'ul. Dolna 6', '44-444', 'Bór');
INSERT INTO Wizyty VALUES (1, '2029-02-01', '12:30', 1, 2);
INSERT INTO Lekarze VALUES (1, 'Marek Z¹bek', 12);
INSERT INTO Rodzaje_wizyt VALUES (2, 'Dentystyczny', 'Za³o¿enie protezy..', 300);

-- 3NF
-- Id¹c dalej z za³o¿eniem o Lekarzu który ma swój pokój, mo¿emy pozbyæ siê tego pola
CREATE TABLE Lekarze_3NF (ID INT PRIMARY KEY, Lekarz VARCHAR(50));
-- Mozna rowniez na podstawie lekarza lub powodu wizyty wywnioskowac typ wizyty
CREATE TABLE Rodzaje_wizyt_3NF (ID INT PRIMARY KEY, Powód VARCHAR(50), Kwota MONEY)


