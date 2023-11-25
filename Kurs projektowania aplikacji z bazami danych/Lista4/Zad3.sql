set statistics time on

SELECT DISTINCT c.PESEL, c.Nazwisko
FROM Egzemplarz e
JOIN Ksiazka k ON e.Ksiazka_ID=k.Ksiazka_ID
JOIN Wypozyczenie w ON e.Egzemplarz_ID=w.Egzemplarz_ID
JOIN Czytelnik c ON c.Czytelnik_ID = w.Czytelnik_ID;

-- Dla 3 prob, Client processing time: 4,666, Total execution time: 7.0, Wait time on server replies: 2,3333

SELECT c.PESEL, c.Nazwisko
FROM Czytelnik c WHERE c.Czytelnik_ID IN
(SELECT w.Czytelnik_ID FROM Wypozyczenie w
JOIN Egzemplarz e ON e.Egzemplarz_ID=w.Egzemplarz_ID
JOIN Ksiazka k ON e.Ksiazka_ID=k.Ksiazka_ID)

-- Dla 3 prob, Client processing time: 11.0, Total execution time: 16.6667, Wait time on server replies: 5.6667


SELECT c.PESEL, c.Nazwisko
FROM Czytelnik c WHERE c.Czytelnik_ID IN
(SELECT w.Czytelnik_ID FROM Wypozyczenie w
WHERE w.Egzemplarz_ID IN 
(SELECT e.Egzemplarz_ID FROM Egzemplarz e
JOIN Ksiazka k ON e.Ksiazka_ID=k.Ksiazka_ID))

-- Dla 3 prob, Client processing time: 10.0, Total execution time: 17.3333, Wait time on server replies: 7.3333

set statistics time off