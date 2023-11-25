// Lista6 Zad2c
/* MATCH (p:Person), (m:Movie)
WHERE p.name='Angelina Jolie' AND m.title='Changeling'
CREATE (p)-[r:ACTED_IN]->(m)
RETURN type(r) */


/* MATCH (p:Person), (m:Movie)
WHERE p.name='Russell Crowe' AND m.title='Gladiator'
CREATE (p)-[r:ACTED_IN]->(m)
RETURN type(r) */

//MATCH (:Person {name: 'Angelina Jolie'})--(movie:Movie) RETURN movie.title