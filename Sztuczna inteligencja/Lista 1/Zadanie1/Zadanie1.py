import sys
import pdb

PREV_STATES = set()

KING_MOVES = [(-1,-1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]

class State:

    def __init__(self, wk, wr, bk, is_whitemove, move_cnt, prev_state=None):
        self.wk = wk
        self.wr = wr
        self.bk = bk
        self.is_whitemove = is_whitemove
        self.move_cnt = move_cnt
        self.prev_state = prev_state
    
    def __repr__(self) -> str:
        return f"(wk: {untranslate(self.wk)}, wr: {untranslate(self.wr)}, bk: {untranslate(self.bk)})"


def is_checkmate(state):
    if state.bk ==(0, 0) and (abs(state.bk[0] - state.wr[0]) or abs(state.bk[1] - state.wr[1])):
        if (state.wk == (1, 2) and state.wr[1] == 0) or (state.wk == (2, 1) and state.wr[0] == 0):
            return True
        return False

    if state.bk == (7, 0) and (abs(state.bk[0] - state.wr[0]) or abs(state.bk[1] - state.wr[1])):
        if (state.wk == [6, 2] and state.wr[1] == 0) or (state.wk == (5, 1) and state.wr[0] == 7):
            return True
        return False

    if state.bk == (0, 7) and (abs(state.bk[0] - state.wr[0]) or abs(state.bk[1] - state.wr[1])):
        if (state.wk == (1, 5) and state.wr[1] == 7) or (state.wk == (2, 6) and state.wr[0] == 0):
            return True
        return False

    if state.bk == (7, 7) and (abs(state.bk[0] - state.wr[0]) or abs(state.bk[1] - state.wr[1])):
        if (state.wk == (6, 5) and state.wr[1] == 7) or (state.wk == (5, 6) and state.wr[0] == 7):
            return True
        return False

    if (state.bk[0] == 0 or state.bk[0] == 7) and abs(state.bk[0] - state.wk[0]) == 2 and \
            state.bk[1] == state.wk[1] and state.bk[0] == state.wr[0]:
        return True

    if (state.bk[1] == 0 or state.bk[1] == 7) and abs(state.bk[1] - state.wk[1]) == 2 and \
            state.bk[0] == state.wk[0] and state.bk[1] == state.wr[1]:
        return True

    return False

def is_pat(state):
    if state.wr[0] == state.bk[0] or state.wr[1] == state.bk[1]:
        return False
    for i in range(-1, 2):
        for j in range(-1, 2):
            if i == 0 and j == 0:
                continue
            new_x = state.bk[0] + i
            new_y = state.bk[1] + j
            if 0 <= new_x <= 7 and 0 <= new_y <= 7:
                if legal_move('king', (new_x, new_y), state):
                    return False
        
    return True

def rook_to_black_king_vector(state):
    """
    Określa stosunek pozycji wiezy do czarnego krola
    Dokladniej gdzie jest czarny krol w stosunku do wiezy
    Zwraca liczbę ze zbioru [1, 2, 3, 4]
    1 - polnoc-zachod
    2 - polnoc wschod
    3 - poludnie zachod
    4 - poludnie wschod
    jezeli krol jest na tym samym X albo Y to jest mat bo sprawdzamy to
    wtedy gdy wieza ma ruch
    """
    vector = (state.wr[0] - state.bk[0], state.wr[1] - state.bk[1])

    if vector[0] > 0 and vector[1] > 0:
        return 3
    if vector[0] < 0 and vector[1] > 0:
        return 4
    if vector[0] > 0 and vector[1] < 0:
        return 1
    if vector[0] < 0 and vector[1] < 0:
        return 2

def legal_move(piece, to, state):
    if state.is_whitemove:
        if piece == 'king':
            state_tuple = (to, state.wr, state.bk)
            if state_tuple in PREV_STATES:
                return False
            
            PREV_STATES.add(state_tuple)
            # Czy wieza jest na tym polu
            if state.wr == to or state.bk == to:
                return False

            for i in range(8):
                bk_x = state.bk[0]+KING_MOVES[i][0]
                bk_y = state.bk[1]+KING_MOVES[i][1]

                if to == (bk_x, bk_y):
                    return False
            
            return (0 <= to[0] <= 7) and (0 <= to[1] <= 7)
        
        if piece == 'rook':
            state_tuple = (state.wk, to, state.bk)
            if state_tuple in PREV_STATES:
                return False
            
            PREV_STATES.add(state_tuple)
            
            if abs(to[0] - state.bk[0]) <= 1 and abs(to[1] - state.bk[1]) <= 1:
                return False

            return (0 <= to[0] <= 7) and (0 <= to[1] <= 7)
    else:
        # nie mozemy sie ruszyc tam gdzie wieza atakuje krola
        state_tuple = (state.wk, state.wr, to)
        if state_tuple in PREV_STATES:
            return False
    
        rook_x = state.wr[0]
        rook_y = state.wr[1]

        if to[0] == rook_x or to[1] == rook_y:
            return False

        # ani tam gdzie nas bije krol
        for i in range(8):
            wk_x = state.wk[0]+KING_MOVES[i][0]
            wk_y = state.wk[1]+KING_MOVES[i][1]

            if to == (wk_x, wk_y):
                return False

        return (0 <= to[0] <= 7) and (0 <= to[1] <= 7)

def search(state):
    queue = [state]
    PREV_STATES.clear()
    curr_state = None
    while len(queue) > 0:
        curr_state = queue.pop(0)
        if curr_state.is_whitemove:
            # król
            for i in range(8):
                new_x = curr_state.wk[0]+KING_MOVES[i][0]
                new_y = curr_state.wk[1]+KING_MOVES[i][1]

                if legal_move('king', (new_x, new_y), curr_state):
                    queue.append(State((new_x, new_y), curr_state.wr, curr_state.bk, not curr_state.is_whitemove, curr_state.move_cnt+1, curr_state))
            # wieża
            x = curr_state.wr[0]
            y = curr_state.wr[1]

            # musimy sprawdzić jak daleko możemy się ruszac, tzn. czy nasz wlasny krol nas nie blokuje
            # pion
            low = curr_state.wk[1]+1 if curr_state.wk[0] == x and curr_state.wk[1] < y else 0
            high = curr_state.wk[1]-1 if curr_state.wk[0] == x and curr_state.wk[1] > y else 7

            
            for i in range(low, high+1):
                if i == x:
                    continue
                if legal_move('rook', (i, y), curr_state):
                    queue.append(State(curr_state.wk, (i, y), curr_state.bk, not curr_state.is_whitemove, curr_state.move_cnt+1, curr_state))

            # poziom
            low = curr_state.wk[0]+1 if curr_state.wk[1] == y and curr_state.wk[0] < x else 0
            high = curr_state.wk[0]-1 if curr_state.wk[1] == y and curr_state.wk[0] > x else 7

            
            for i in range(low, high+1):
                if i == y:
                    continue
                if legal_move('rook', (x, i), curr_state):
                    queue.append(State(curr_state.wk, (x, i), curr_state.bk, not curr_state.is_whitemove, curr_state.move_cnt+1, curr_state))

        else:
            if is_checkmate(curr_state):
                show_moves(curr_state)
                return

            for i in range(8):
                new_x = curr_state.bk[0]+KING_MOVES[i][0]
                new_y = curr_state.bk[1]+KING_MOVES[i][1]
                if legal_move('king', (new_x, new_y), curr_state):
                    queue.append(State(curr_state.wk, curr_state.wr, (new_x, new_y), not curr_state.is_whitemove, curr_state.move_cnt+1, curr_state))



def translate_position(position):
    mapper = dict(a=0, b=1, c=2, d=3, e=4, f=5, g=6, h=7)
    return (mapper[position[0]], int(position[1])-1)

def untranslate(pos):
    return f"{chr(pos[0]+97)}{pos[1]+1}"

def get_move_in_notation(begin, end):
    if begin.wk != end.wk:
        return untranslate(begin.wk) + untranslate(end.wk)
    
    if begin.wr != end.wr:
        return untranslate(begin.wr) + untranslate(end.wr)
    
    if begin.bk != end.bk:
        return untranslate(begin.bk) + untranslate(end.bk)
    


def show_moves(last_state):
    moves = []
    while last_state:
        moves.insert(0, last_state)
        last_state = last_state.prev_state
    
    for i in range(len(moves) - 1):
        begin = moves[i]
        next = moves[i+1]
        print(get_move_in_notation(begin, next), end=' ')




if __name__ == '__main__':
    line = input().split(' ')
    white_move = line[0] == 'white'
    white_king = translate_position(line[1])
    white_rook = translate_position(line[2])
    black_king = translate_position(line[3])
    state = State(white_king, white_rook, black_king, white_move, 0, None)
    search(state)

