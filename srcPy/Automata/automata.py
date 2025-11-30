"""
    This is an "abstract" class representing Automatas
    Regular, PDAs, and Turing Machines inherit from this,
    but an instance of Automata should never be created.
"""
class Automata:
    def __init__(self, filename):
        raise NotImplementedError()
    def Accept(self, _input):
        raise NotImplementedError()