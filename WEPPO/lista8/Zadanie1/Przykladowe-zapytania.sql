-- Wszystko z tabeli osoba
SELECT * FROM OSOBA;

-- Wszystkie imiona
SELECT imie FROM OSOBA;

-- Wszystkie unikalne imiona
SELECT DISTINCT imie FROM OSOBA;

-- Osoby z nazwiskiem "Kowalski"
SELECT * FROM OSOBA WHERE nazwisko = 'Kowalski'

-- Liczba osob z nazwiskiem "Kowalski"
SELECT COUNT(osoba_id) FROM OSOBA WHERE nazwisko = 'Nowak'

-- Liczba kobiet
SELECT COUNT(osoba_id) FROM OSOBA WHERE plec = "K"

-- Liczba kobiet zakladajac ze tylko imiona kobiece koncza sie na litere 'a'
SELECT COUNT(imie) FROM OSOBA WHERE imie LIKE '%a'

-- Liczba osób z danym nazwiskiem.
SELECT COUNT(osoba_id), nazwisko FROM Osoba GROUP BY nazwisko;