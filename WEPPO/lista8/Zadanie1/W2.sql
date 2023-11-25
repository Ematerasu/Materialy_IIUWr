
CREATE TABLE Osoba (
    osoba_id SERIAL PRIMARY KEY,  -- surrogate key
    imie     VARCHAR NOT NULL,    -- VARCHAR czyli string o zmiennej dlugosci jako ze imiona i nazwiska
    nazwisko VARCHAR NOT NULL,    -- moga miec dowolna dlugosc
    plec     CHAR(1) NOT NULL,    -- Mozemy uzyc konwencji K - kobieta, M-mezczyzna, oczywiscie mozna dodac 'B' dla osob niebinarnych itd.
    miasto   VARCHAR NOT NULL     -- Miasto moze miec dowolna dlugosc
);


INSERT INTO Osoba VALUES ('Dominik', 'Budzki', 'M', 'Wroclaw');