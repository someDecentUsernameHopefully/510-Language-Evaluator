from Automata.state import State

"""
    This is an "abstract" class representing Automatas
    Regular, PDAs, and Turing Machines inherit from this,
    but an instance of Automata should never be created.
"""
class Automata:
    def __init__(self, filename):
        raise NotImplementedError()
    def __del__(self):
        keys = []
        for key in self.states.keys():
            keys.append(key)
        for key in keys:
            del self.states[key]
    def Accept(self, _input):
        raise NotImplementedError()
    def InputInAlpha(self, _input):
        for char in _input:
            if char not in self.alphabet:
                return False
        return True
    def _setupAlphabet(self, line):
        # Get the space-separated language alphabet
        self.alphabet = line.split(" ")
    def _setupStates(self, line):
        self.states = {}
        self.start = None
        # Get the space-separated list of state names
        for name in line.split(" "):
            # Generate the state, add it to the list
            # The first state listed is the start state
            S = State(name)
            self.states[name] = S
            if self.start is None:
                self.start = S
        if(len(self.states) == 0):
            raise RuntimeError("Automata must have at least one state!")
    def _setAccepting(self, line):
        # Get the list of accepting states
        for name in line.split(" "):
            self.states[name].accepting = True