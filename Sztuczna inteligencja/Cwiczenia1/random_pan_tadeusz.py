import random

DICTIONARY = set(open("words_for_ai1.txt", "r").read().split("\n"))


maxWordLength = 25


def randomSpaces(sentence):

    indexes = list(range(1, min(maxWordLength, len(sentence))))
    random.shuffle(indexes)

    if sentence == '':
        return ''

    for i in indexes:
        if (sentence[0:i] in DICTIONARY):
            output = randomSpaces(sentence[i:])

            if output != -1:
                return sentence[0:i] + ' ' + output

    return -1

if __name__ == '__main__':

    open("zad2_output.txt", "w").close()
    input = open("pan_tadeusz.txt", "r").read().split("\n")
    for sentence in input:
        result = randomSpaces(sentence)
        f = open("zad2_output.txt", "a")
        f.write(f"\n{result}")
        f.close()
