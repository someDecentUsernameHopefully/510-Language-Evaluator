from Automata.automata import Automata

class PDA(Automata):
    def __init__(self, filename):
        super().__init__(filename)
    def Accept(self, _input):
        return super().Accept(_input)