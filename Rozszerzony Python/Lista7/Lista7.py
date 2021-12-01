import requests
from bs4 import BeautifulSoup
import re

### Lista7 ###
import threading
################

# Regex dla adresow 
adres = '(https?:\/\/(?:www\.|(?!www))[a-zA-Z0-9][a-zA-Z0-9-]+[a-zA-Z0-9]\.[^\s]{2,}|www\.[a-zA-Z0-9][a-zA-Z0-9-]+[a-zA-Z0-9]\.[^\s]{2,}|https?:\/\/(?:www\.|(?!www))[a-zA-Z0-9]+\.[^\s]{2,}|www\.[a-zA-Z0-9]+\.[^\s]{2,})'
automat = re.compile(adres)


### Komentarz do Listy 7 ###
#   W programie wątki nie używają tych samych zasobów, każdy podproces będzie operował na własnej liście.
#   Korzystają z innych linków, na nich tworzą własne listy które potrzebne są do dalszego "pełzania"
#   Nie potrzeba więc implementacji zamków.
#   Jedyne co wątki mają wspólne to korzystanie z tej samej funkcji, jednak "ta sama" jest jedynie deklaracja, instancje są inne.


class Crawler:

    visited = []

    def crawl(self, start_page, distance, action):
        if distance <= 0 or start_page in self.visited:
            return
        self.visited.append(start_page)

        page = requests.get(start_page).content    
        res = action(page, 'Python')
        if len(res) > 0:
            print((start_page, res))

        soup = BeautifulSoup(page, "html.parser")
        links = []
        for link in soup.findAll('a'):
            if link.get('href') != '#':
                if re.match(automat, str(link.get('href'))):
                    links.append(link.get('href'))

        ### Lista 7 ###
        threads = []
        for link in links:
            threads.append(threading.Thread(target=self.crawl,args=(link, distance-1, action)))

        n = len(threads)
        for i in range(n):
            threads[i].start()
        
        for i in range(n):
            threads[i].join()
        ################


def find_phrases(htmltext, keyword):
    soup = BeautifulSoup(htmltext, "html.parser")
    phrases = soup.findAll(text = lambda x: keyword in x) # szuka po wszystkich taga i sprawdza czy w nich znajduje sie keyword
    return phrases
    

c = Crawler()
result = c.crawl('https://skos.ii.uni.wroc.pl/course/view.php?id=406', 2, find_phrases)