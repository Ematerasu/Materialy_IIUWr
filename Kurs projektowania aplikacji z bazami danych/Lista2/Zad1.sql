DROP FUNCTION IF EXISTS readers
GO
CREATE FUNCTION readers (@num_of_days int) RETURNS TABLE
RETURN 
  SELECT c.PESEL, count(w.Egzemplarz_ID) as liczba_egzemplarzy, min(w.Liczba_Dni) as Najkrócej_trzymana_ksi¹¿ka
  FROM Czytelnik as c
  JOIN Wypozyczenie as w
  ON c.Czytelnik_ID=w.Czytelnik_ID
  WHERE @num_of_days<=w.Liczba_Dni
  GROUP BY c.PESEL

go
SELECT * FROM readers(14)
SELECT * FROM readers(5)
go