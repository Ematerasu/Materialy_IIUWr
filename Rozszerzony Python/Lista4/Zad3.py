
"""
Sudoku solver Dominik Budzki

Sudoku podajemy w postaci tablicy 9x9

Przykladowe sudoku z generatora znalezionego w internecie
0 to puste pole, liczba od 1 do 9 to liczba w polu
[0,8,9,3,0,0,7,6,0],
[0,7,1,4,6,9,0,8,0],
[3,6,4,8,5,0,0,9,0],
[0,4,0,0,8,0,0,0,1],
[0,3,0,0,9,0,2,0,0],
[0,5,8,0,2,0,9,0,3],
[0,0,5,9,0,8,0,0,0],
[4,1,0,0,7,5,0,0,0],
[0,9,0,2,4,0,0,0,0]

Moje rozwiazanie polega na backtrackingu

"""

def isSafe(board, x, y, num):
    for i in range(9):
        if board[x][i] == num:
            return False
    for i in range(9):
        if board[i][y] == num:
            return False

    beginOfBox_x, beginOfBox_y = x - x % 3, y - y % 3

    for i in range(beginOfBox_x, beginOfBox_x+3):
        for j in range(beginOfBox_y, beginOfBox_y+3):
            if board[i][j] == num:
                return False
    return True

        
def rozwiazanie_sudoku(board):
    x, y = 0, 0

    finished = True

    # Szukamy pustych pól, jeśli nie ma pustych pól to skończyliśmy sudoku
    for i in range(9):
        for j in range(9):
            if board[i][j] == 0:
                x = i
                y = j
                finished = False
                break
        if not finished:
            break
    
    if finished:
        return True
    
    # Sprawdzamy po kolei każdą cyfrę czy pasuje
    for num in range(1,10):
        if isSafe(board, x, y, num):
            board[x][y] = num

            if rozwiazanie_sudoku(board):
                return True
            else:
                board[x][y] = 0

    
    return None
    

def printBoard(board):
    for i in range(9):
        for j in range(9):
            print(board[i][j], end = " ", flush = True)
            if j != 8 and (j+1) % 3 == 0:
                print("|", end = " ", flush = True)
        if (i+1) % 3 == 0:
            print("\n----------------------")
        else:
            print("")

if __name__ == "__main__":
    
    example = [ [0,8,9,3,0,0,7,6,0],
                [0,7,1,4,6,9,0,8,0],
                [3,6,4,8,5,0,0,9,0],
                [0,4,0,0,8,0,0,0,1],
                [0,3,0,0,9,0,2,0,0],
                [0,5,8,0,2,0,9,0,3],
                [0,0,5,9,0,8,0,0,0],
                [4,1,0,0,7,5,0,0,0],
                [0,9,0,2,4,0,0,0,0]]

    result = rozwiazanie_sudoku(example)

    if result:
        printBoard(example)
    else:
        print("Nie da się rozwiązać tego sudoku!")
