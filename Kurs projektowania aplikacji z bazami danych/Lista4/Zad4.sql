SELECT K.Tytul, COUNT(E.Egzemplarz_ID) as Ilosc_egzemplarzy
FROM Egzemplarz E
JOIN Ksiazka K
ON E.Ksiazka_ID = K.Ksiazka_ID
GROUP BY K.Tytul