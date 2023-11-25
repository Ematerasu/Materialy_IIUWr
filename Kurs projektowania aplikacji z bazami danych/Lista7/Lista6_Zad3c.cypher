// Lista6 Zad3c
MATCH(p:Person)
WHERE NOT (p)-[:ACTED_IN]->(:Movie)
return p
