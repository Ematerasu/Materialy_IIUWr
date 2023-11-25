// Lista6 Zad3b
MATCH (p:Person)-[:PRODUCED]->(movie:Movie),
(p)-[:DIRECTED]->(movie)
RETURN movie.title
//RETURN p,movie