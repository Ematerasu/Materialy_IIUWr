import random

"""
Zauważmy że Figurant nie jest w stanie stworzyć pokera (królewskiego tym bardziej) bo ma tylko 4 różne figury a potrzebuje 5
Podobnie blotkarz nie jest w stanie stworzyc pokera krolewskiego bo nie posiada figur do tego potrzebnych
"""

card_val = {
    '2': 2,
    '3': 3,
    '4': 4,
    '5': 5,
    '6': 6,
    '7': 7,
    '8': 8,
    '9': 9,
    '10': 10,
    'J': 11,
    'Q': 12,
    'K': 13,
    'A': 14
}

def get_card_value(card):
    return card_val[card[:-1]]

def get_card_color(card):
    return card[-1]

def sort_hand(cards):
    cards.sort(key=get_card_value)


def straight_flush(hand):
    sort_hand(hand)

    for i in range(1, len(hand)):
        if get_card_value(hand[i]) != get_card_value(hand[i - 1]) + 1:
            return False

        if get_card_color(hand[i]) != get_card_value(hand[i-1]):
            return False

    return True


def four_of_a_kind(hand):
    sort_hand(hand)

    first_4 = get_card_value(hand[0]) == get_card_value(hand[1]) == get_card_value(hand[2]) == get_card_value(hand[3])
    last_4 = get_card_value(hand[1]) == get_card_value(hand[2]) == get_card_value(hand[3]) == get_card_value(hand[4])
    if first_4 or last_4:
        return True

    return False


def full_house(hand):
    sort_hand(hand)

    first_3 = get_card_value(hand[0]) == get_card_value(hand[1]) == get_card_value(hand[2])
    last_2 = get_card_value(hand[3]) == get_card_value(hand[4])

    first_2 = get_card_value(hand[0]) == get_card_value(hand[1])
    last_3 = get_card_value(hand[2]) == get_card_value(hand[3]) == get_card_value(hand[4])

    if first_3 and last_2 or first_2 and last_3:
        return True

    return False


def flush(hand):
    for i in range(1, len(hand)):
        if get_card_color(hand[i]) != get_card_color(hand[i - 1]):
            return False

    return True


def straight(hand):
    sort_hand(hand)

    for i in range(1, len(hand)):
        if get_card_value(hand[i]) != get_card_value(hand[i-1]) + 1:
            return False

    return True


def three_of_a_kind(hand):
    sort_hand(hand)

    first_3 = get_card_value(hand[0]) == get_card_value(hand[1]) == get_card_value(hand[2])
    middle_3 = get_card_value(hand[1]) == get_card_value(hand[2]) == get_card_value(hand[3])
    last_3 = get_card_value(hand[2]) == get_card_value(hand[3]) == get_card_value(hand[4])

    if first_3 or middle_3 or last_3:
        return True

    return False


def two_pairs(hand):
    sort_hand(hand)

    pair_first = get_card_value(hand[0]) == get_card_value(hand[1])
    pair_mid_l = get_card_value(hand[1]) == get_card_value(hand[2])
    pair_mid_r = get_card_value(hand[2]) == get_card_value(hand[3])
    pair_last = get_card_value(hand[3]) == get_card_value(hand[4])

    if pair_first and pair_mid_r or pair_first and pair_last or pair_mid_l and pair_last:
        return True

    return False


def one_pair(hand):
    sort_hand(hand)

    for i in range(1, len(hand)):
        if get_card_value(hand[i]) == get_card_value(hand[i-1]) + 1:
            return True

    return False


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

Blotkarz_ulepszona = [
    '2C', '2D', '2H', '2S',
    '3C', '3D', '3H', '3S',
    '4C', '4D', '4H', '4S',
]

"""
Figurant ma do dyspozycji 4 najsilniejsze rodzaje kart, więc Blotkarz nie ma szans gdy w jego talii znajduję się >=4 rodzajów
słabszych kart. Taktyką tutaj jest ograniczenie się do 3 różnych blotek by maksymalizować
prawdopodobieństwo np. fulla czy karete, nie ma tutaj znaczenia jakie numery kart to będą, bo koniec końców Blotkarz
nie wygra z fullem albo karetą figuranta.
"""

def gen_Figurant_hand(n):
    cards = []

    cards = random.sample(Figurant, n)

    return cards

def gen_Blotkarz_hand(n):
    cards = []

    cards = random.sample(Blotkarz, n)

    return cards

def gen_Blotkarz_ulepszona_hand(n):
    cards = []

    cards = random.sample(Blotkarz_ulepszona, n)

    return cards
# --------------------------------------------------------------

def compare_hands(hand1, hand2):
    hand_rankings = [straight_flush, four_of_a_kind, full_house, flush, straight, three_of_a_kind, two_pairs, one_pair]
    for ranking in hand_rankings:
        result = (ranking(hand1), ranking(hand2))
        if result[0] == True or result[1] == True:
            return result
    return (True, False)

def simulate_game(hand_size, generator1, generator2):
    Figurant = generator1(hand_size)
    Blotkarz = generator2(hand_size)

    result = compare_hands(Figurant, Blotkarz)

    if result == (True, True):
        return 'f'
    if result == (True, False):
        return 'f'
    if result == (False, True):
        return 'b'
    

if __name__ == "__main__":
    num = 10000
    f, b = 0, 0
    hand_size = 5

    for _ in range(num):
        result = simulate_game(hand_size, gen_Figurant_hand, gen_Blotkarz_hand)
        if result == 'b':
            b += 1
        elif result == 'f':
            f += 1

    print(f'Przy zwykłych taliach:')
    print(f'Liczba rozdań: {num}, \nFigurant wygrał: {f} gier, Blotkarz wygrał: {b} gier\n')
    print(f'Winratio Blotkarza wynosi {b / num * 100}% \n')

    f, b = 0, 0
    for _ in range(num):
        result = simulate_game(hand_size, gen_Figurant_hand, gen_Blotkarz_ulepszona_hand)
        if result == 'b':
            b += 1
        elif result == 'f':
            f += 1

    print(f'Przy ulepszonej talii Blotkarza:')
    print(f'Liczba rozdań: {num}, \nFigurant wygrał: {f} gier, Blotkarz wygrał: {b} gier\n')
    print(f'Winratio Blotkarza wynosi {b / num * 100}% \n')