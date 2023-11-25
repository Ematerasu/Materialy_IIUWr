// Lista6 Zad3d
MATCH(p:Person)-[:ACTED_IN]-(m:Movie)
WITH p, count(m) as rels, collect(m) as Movies
WHERE rels > 3
return p, rels, Movies
