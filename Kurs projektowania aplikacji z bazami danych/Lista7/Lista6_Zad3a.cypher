// Lista6 Zad3a
MATCH (p:Person {name:'Angelina Jolie'})->[:ACTED_IN]-(movie:Movie)
RETURN movie.title