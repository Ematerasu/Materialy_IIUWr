-- Sekwencja do zwiekszania ID o 1
CREATE SEQUENCE sequence_osoba_id
    AS INT
    START WITH 1
    INCREMENT BY 1;

CREATE TABLE Osoba (
    osoba_id INTEGER PRIMARY KEY, -- surrogate key
    imie     VARCHAR NOT NULL,    -- VARCHAR czyli string o zmiennej dlugosci jako ze imiona i nazwiska
    nazwisko VARCHAR NOT NULL,    -- moga miec dowolna dlugosc
    plec     CHAR(1) NOT NULL,    -- Mozemy uzyc konwencji K - kobieta, M-mezczyzna, oczywiscie mozna dodac 'B' dla osob niebinarnych itd.
    miasto   VARCHAR NOT NULL    -- Miasto moze miec dowolna dlugosc
);


INSERT INTO Osoba VALUES (nextval('sequence_osoba_id'), 'Dominik', 'Budzki', 'M', 'Wroclaw');
