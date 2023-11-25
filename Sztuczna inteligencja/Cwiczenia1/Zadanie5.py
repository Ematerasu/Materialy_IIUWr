from math import factorial
from Zadanie3 import *

Figurant = [
    'AC', 'AD', 'AH', 'AS',
    'KC', 'KD', 'KH', 'KS',
    'QC', 'QD', 'QH', 'QS',
    'JC', 'JD', 'JH', 'JS'
]

Blotkarz = [
    '2C', '2D', '2H', '2S',
    '3C', '3D', '3H', '3S',
    '4C', '4D', '4H', '4S',
    '5C', '5D', '5H', '5S',
    '6C', '6D', '6H', '6S',
    '7C', '7D', '7H', '7S',
    '8C', '8D', '8H', '8S',
    '9C', '9D', '9H', '9S',
    '10C', '10D', '10H', '10S'
]

def getScore(hand):
    hand_rankings = [straight_flush, four_of_a_kind, full_house, flush, straight, three_of_a_kind, two_pairs, one_pair]
    for i, ranking in enumerate(hand_rankings):
        if ranking(hand):
            return 8-i

def generateHands(deck):
    for first in range(len(deck)):
        for second in range(first + 1, len(deck)):
            for third in range(second + 1, len(deck)):
                for fourth in range(third + 1, len(deck)):
                    for fifth in range(fourth + 1, len(deck)):
                        yield [deck[first], deck[second], deck[third], deck[fourth], deck[fifth]]

def count_ranks(deck, rank):
    c = 0
    for hand in generateHands(deck):
        if getScore(hand) == rank:
            c += 1

    return c

def binomial(n, k):
    return factorial(n)/(factorial(k) * factorial(n-k))

def countPossibility(bDeck, fDeck):
    figurant_combinations = binomial(len(fDeck), 5)
    blotkarz_combinations = binomial(len(bDeck), 5)

    blotkarz_wins = 0

    figIorLower = [0] * 9
    for i in range(1, 9):
        figIorLower[i] = figIorLower[i - 1] + count_ranks(Figurant, i)

    for i in range(1, 9):
        blotkarz_wins += figIorLower[i - 1] * count_ranks(Blotkarz, i)

    return (blotkarz_wins / (blotkarz_combinations * figurant_combinations)) * 100


if __name__ == "__main__":
    print(f"{countPossibility(Blotkarz, Figurant)}%")