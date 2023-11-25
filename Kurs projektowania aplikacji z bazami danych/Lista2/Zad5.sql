DROP TABLE IF EXISTS #Tablica;
CREATE TABLE #Tablica(klucz int not null primary key, wartosc varchar(20));

SELECT * FROM tempdb.INFORMATION_SCHEMA.TABLES;