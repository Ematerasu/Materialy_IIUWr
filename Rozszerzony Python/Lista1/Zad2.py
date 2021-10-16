
def is_palindrom(text):
    text = text.lower()
    text = [char for char in text if char.isalpha()]
    return text == text[::-1]

print(is_palindrom("oko"))
print(is_palindrom("Kobyła ma mały bok"))
print(is_palindrom("Eine güldne, gute Tugend: Lüge nie!"))
print(is_palindrom("r-o-t-o-r"))
print(is_palindrom("あきすきあ"))
print(is_palindrom("To nie jest palindrom"))
print(is_palindrom("a-------o"))
