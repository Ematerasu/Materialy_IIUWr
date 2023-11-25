// Lista6 Zad2b
MATCH (n:Movie{title:'Changeling'}) SET n.rating = '9.0'
MATCH (n:Movie{title:'Gladiator'}) SET n.rating = '8.5'
MATCH (n:Movie{title:'Changeling'}) SET n.type = 'Drama'
MATCH (n:Movie{title:'Gladiator'}) SET n.type = 'Drama'