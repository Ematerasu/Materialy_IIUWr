
class Formula:

    def __init__(self, left, right=None):
        # Jesli formula jest atomowa to poprostu nie uzywamy parametru "right"
        self.left = left
        self.right = right 

    def __add__(self, w1):
        return Or(self, w1)

    def __mul__(self, w1):
        return And(self, w1)

    @staticmethod
    def tautologia(formula, variables:list):
        """
            Wydaje mi sie ze nie da sie tego zrobic sprawniej majac dowolna formula i jej zmienne, więc poprostu sprawdzam każdą możliwą kombinacje zmiennych
            argument "variables" jest listą zmiennych (stringów) znajdujących się w formule 
            Przykład wywołania:
                Formula.tautologia(Or(Variable("x"), Variable("y")), ["x","y"])
        """
        posibilities = 2**len(variables)
        for mask in range(posibilities):
            temp_vars = {}
            for i, var in enumerate(variables, start=1):
                temp_vars[var] = (mask & i) >> (i-1)
            if not formula.oblicz(temp_vars):
                return False

        return True

    @staticmethod
    def isAtomic(formula):
        if formula.right is None:
            return True
        return False
    
class And(Formula):

    def oblicz(self, zmienne):
        return self.left.oblicz(zmienne) and self.right.oblicz(zmienne)
    
    def __str__(self):
        return "(" + str(self.left) + " \u2227 " + str(self.right) + ")"

class Or(Formula):
    
    def oblicz(self, zmienne):
        return self.left.oblicz(zmienne) or self.right.oblicz(zmienne)
    
    def __str__(self):
        return "(" + str(self.left) + " v " + str(self.right) + ")"

class Implication(Formula):

    def oblicz(self, zmienne):
        return not (self.left.oblicz(zmienne) and (not self.right.oblicz(zmienne)))
    
    def __str__(self):
        return "(" + str(self.left) + " => " + str(self.right) + ")" # Rownowaznosc implikacji

class Equivalence(Formula):

    def oblicz(self, zmienne):
        return self.left.oblicz(zmienne) ==  self.right.oblicz(zmienne)
    
    def __str__(self):
        return "(" + str(self.left) + " <=> " + str(self.right) + ")"

class Not(Formula):

    def oblicz(self, zmienne):
        return not self.left.oblicz(zmienne)
    
    def __str__(self):
        return "\u00AC(" + str(self.left) + ")"

class Variable(Formula):

    def oblicz(self, zmienne):
        if zmienne.get(self.left) is None:
            raise VariableNoValueError(self.left)
        return zmienne[self.left]

    def __str__(self):
        return self.left

class Const(Formula):

    def oblicz(self, zmienne):
        return self.left

    def __str__(self):
        if self.left:
            return "true"
        else:
            return "false"


def simplify(formula:Formula):
    if Formula.isAtomic(formula):
        return formula
    formula.left = simplify(formula.left)
    formula.right = simplify(formula.right)

    if isinstance(formula, And):
        if str(formula.left) == "false" or str(formula.right) == "false":
            return Const(False)
    elif isinstance(formula, Or):
        if str(formula.left) == "true" or str(formula.right) == "true":
            return Const(True)
        elif str(formula.left) == "false":
            return formula.right
        elif str(formula.right) == "false":
            return formula.left


class VariableNoValueError(Exception):
    
    def __init__(self, variable, message="Variable has no value"):
        self.variable = variable
        self.message = message
        super().__init__(self.message)

    def __str__(self):
        return f"{self.variable} -> {self.message}"
    
    
            
    