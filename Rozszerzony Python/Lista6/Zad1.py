import requests
from bs4 import BeautifulSoup
import re

# Regex dla adresow 
adres = '(https?:\/\/(?:www\.|(?!www))[a-zA-Z0-9][a-zA-Z0-9-]+[a-zA-Z0-9]\.[^\s]{2,}|www\.[a-zA-Z0-9][a-zA-Z0-9-]+[a-zA-Z0-9]\.[^\s]{2,}|https?:\/\/(?:www\.|(?!www))[a-zA-Z0-9]+\.[^\s]{2,}|www\.[a-zA-Z0-9]+\.[^\s]{2,})'
automat = re.compile(adres)

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

        for link in links:
            self.crawl(link, distance-1, action)


def find_phrases(htmltext, keyword):
    soup = BeautifulSoup(htmltext, "html.parser")
    phrases = soup.findAll(text = lambda x: keyword in x) # szuka po wszystkich taga i sprawdza czy w nich znajduje sie keyword
    return phrases
    

c = Crawler()
result = c.crawl('https://skos.ii.uni.wroc.pl/course/view.php?id=406', 2, find_phrases)
