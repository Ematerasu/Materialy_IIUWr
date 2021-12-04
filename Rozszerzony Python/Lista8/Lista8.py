from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import Column, Integer, String, ForeignKey
from sqlalchemy import create_engine
from sqlalchemy.orm import sessionmaker, relationship
import sys

"""
Dominik Budzki 314625 Lista 8, Zadanie 2

Sam interfejs jest w jezyku polskim, tak jak na liscie pokazane. Nazwy zmiennych, klas etc. zrobilem po angielsku,
jakos lepiej mi sie patrzy na kod w jezyku angielskim.

Nazwy które posiadaja spacje wprowadzamy do programu w formie "Slowo_slowo_....", czyli zamiast spacji dajemy podloge, podczas wypisania podloga znika i zamieniamy ja na spacje

"""

Base = declarative_base()

class Movies(Base):
    __tablename__ = 'Movies'

    id = Column(Integer, primary_key=True)
    title = Column(String)
    year = Column(Integer)
    category = Column(String)
    director_id = Column(Integer, ForeignKey('Directors.id'))
    director = relationship("Directors", back_populates="movies")

    def __repr__(self):
        title = " ".join(self.title.split('_'))
        name = " ".join(self.director.name.split('_'))
        return f"[Tytul: '{title}', Rok produkcji: {self.year}, Kategoria: {self.category}, Rezyser: {name}]"

    
class Directors(Base):
    __tablename__ = 'Directors'

    id = Column(Integer, primary_key=True)
    name = Column(String) # Dla prostoty reżysera będziemy opisywać w formacie Imie_Nazwisko, albo same nazwisko, jak kto woli

    movies = relationship("Movies", order_by=Movies.id, back_populates="director") # one-to-many relacja, rezyser moze nakrecic wiele filmow ale film moze miec jednego rezysera (uproszczenie, oczywiscie
                                                                                   # mamy kontrprzykłady np. Matrix)

    def __repr__(self) -> str:
        name = " ".join(self.name.split('_'))
        movies = [" ".join(movie.title.split('_')) for movie in self.movies]
        return f"[Imie i Nazwisko: {name}, movies: {movies}]"

def insert_movie():
    engine = create_engine('sqlite:///Lista8.db')
    Session = sessionmaker(bind=engine)
    session = Session()

    title = sys.argv[3]
    year = sys.argv[4]
    category = sys.argv[5]
    director = sys.argv[6]
    try:
        d = session.query(Directors).filter_by(name=director).one()
        movie = Movies(title=title, year=year, category=category)
        d.movies.append(movie)
        session.add(movie)
        session.commit()
    except Exception as e:
        #print(e) #Debugging
        print("Rezyser nie znajduje sie w bazie danych! Dodaj go zanim dodasz film!")

def insert_director():
    engine = create_engine('sqlite:///Lista8.db')
    Session = sessionmaker(bind=engine)
    session = Session()

    name = sys.argv[3]

    director = Directors(name=name)
    session.add(director)
    session.commit()

if __name__ == "__main__":
    if len(sys.argv) == 2 and sys.argv[1] == 'start':
        print("Witaj w programie przechowujacym informacje o filmach!")
        print("Do dyspozycji masz dwie tabele: Filmy oraz Rezyserzy")
        print("Wpisz \'--pomoc\' by zobaczyc w jakim formacie wpisywac dane")
    
        engine = create_engine('sqlite:///Lista8.db')
        Base.metadata.create_all(engine)
        print("Baza danych zostala utworzona!")

    elif (len(sys.argv) == 7 or len(sys.argv) == 4) and sys.argv[2] == '--dodaj' :
        if sys.argv[1] == 'Filmy':
            insert_movie()
        if sys.argv[1] == 'Rezyserzy':
            insert_director()

    elif len(sys.argv) == 3 and sys.argv[2] == '--wypisz':
        engine = create_engine('sqlite:///Lista8.db')
        Session = sessionmaker(bind=engine)
        session = Session()
        if sys.argv[1] == 'Filmy':
            print("Movies Set:")
            for i in session.query(Movies).order_by(Movies.id):
                print(i)
        elif sys.argv[1] == "Rezyserzy":
            print("Directors Set:")
            for i in session.query(Directors).order_by(Directors.id):
                print(i)

    elif len(sys.argv) == 2 and sys.argv[1] == 'pomoc':
        print("dodaj film: Filmy --dodaj <tytul> <rok_produkcji> <kategoria> <rezyser>'")
        print("dodaj rezysera: Rezyserzy --dodaj <imie_nazwisko>'")
        print("Uwaga! Aby dodać film z rezyserem nalezy najpierw zarejestrowac Rezysera w bazie danych!")
        print("Wypisz elementy: <model> --wypisz")

    else:
        print("Blad wejscia!")
        print("Wpisz \'pomoc\' by zobaczyc polecenia")
