from Zadanie3 import get_card_value, get_card_color

def test_get_card_value():
    tc = {
        '8S': 8, 
        'KH': 13,
        '10H': 10,
        'QH': 12
    }
    
    for key, value in tc.items():
        assert get_card_value(key) == value

def test_get_card_color():
    tc = {
        '8S': 'S', 
        'KH': 'H',
        '10H': 'H',
        'QH': 'H'
    }
    
    for key, value in tc.items():
        assert get_card_color(key) == value

if __name__ == '__main__':
    test_get_card_value()
    test_get_card_color
    print("OK!")