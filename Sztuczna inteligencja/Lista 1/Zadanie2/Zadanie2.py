DICTIONARY = set(open("words_for_ai1.txt", "r").read().split("\n"))


def solve(sentence):
    
    if len(sentence) < 1:
        return ""
    valid_sentence = [0 for _ in range(len(sentence))]

    start_index = [[] for _ in range(len(sentence))]

    for i in range(1, len(sentence)+1):
        if sentence[:i] in DICTIONARY:
            valid_sentence[i-1] = True
            start_index[i-1].append(0)   

        for j in range(i):
            if valid_sentence[j] and sentence[j+1:i] in DICTIONARY:
                valid_sentence[i-1] = True
                start_index[i-1].append(j)        

    values = [0 for _ in range(len(sentence))]
    space_indexes =[[] for _ in range(len(sentence))] 

    for i in range(len(sentence)-1, 0, -1):
        for start_word in start_index[i]:
            val = values[i] + (i - start_word) ** 2
            if val > values[start_word]:
                values[start_word] = val
                space_indexes[start_word] = space_indexes[i] + [start_word+1]

    sentence = list(sentence)

    for index in space_indexes[0][:-1]:
        sentence.insert(index, " ")

    sentence = ''.join(sentence).strip()
    
    # bug
    sentence = sentence.split(' ')
    if sentence[0] not in DICTIONARY:
        one_letter_word = sentence[0][0]
        second_word = sentence[0][1:]
        sentence[0] = one_letter_word
        sentence.insert(1, second_word)
    return (' '.join(sentence)).strip()

if __name__ == "__main__":

    open("zad2_output.txt", "w").close()
    input = open("pan_tadeusz.txt", "r").read().split("\n")
    for sentence in input:
        result = solve(sentence)
        f = open("zad2_output.txt", "a")
        f.write(f"\n{result}")
        f.close()


    