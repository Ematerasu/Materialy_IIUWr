#### Zad 3 ####

def tabliczka(x1, x2, y1, y2):
    n = x2 - x1
    m = y2 - y1
    table = [ [0]*(n+2) for i in range(m+2)]
    table[0][0] = ""
    for i in range(1,n+2):
        table[0][i] = x1 + i - 1
    for i in range(1,m+2):
        table[i][0] = y1 + i - 1
    
    for i in range(1, m+2):
        for j in range(1, n+2):
            table[i][j] = table[i][0] * table[0][j]
    print('\n'.join(['\t'.join([str(cell) for cell in row]) for row in table]))

tabliczka(3, 5, 2, 4)
print()
tabliczka(1, 9, 1, 9)
