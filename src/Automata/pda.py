from Automata.automata import Automata
from Automata.DataStructures.stack import Stack

class PDA(Automata):
    def __init__(self, filename):
        F = open(filename, "r")
        tracker = 0
        for line in F:
            line = line.strip("\n")
            match tracker:
                case 0:
                    # This is just the type of automata. We already know this.
                    pass
                case 1:
                    self._setupAlphabet(line)
                case 2:
                    # Get the space-separated stack alphabet
                    self.stackAlphabet = line.split(" ")
                case 3:
                    self._setupStates(line)
                case 4:
                    self._setAccepting(line)
                case _:
                    # Define each transition
                    # The format for a transition for regular automata is:
                    # [FROM] [CONSUMED_CHAR] [STACK_TOP] [TO] [STACK_APPEND]
                    raw = line.split(" ")
                    dest = self.states[raw[3]]
                    T = PDATransition(raw[1], dest, raw[2], raw[4])
                    self.states[raw[0]].AddTransition(raw[1], T)
            tracker += 1
        F.close()
        if(tracker < 4):
            raise RuntimeError("States must be defined!")
    def __str__(self):
        toReturn = f"PUSHDOWN AUTOMATA\n{self.alphabet}\n{self.stackAlphabet}\n"
        for state in self.states.values():
            toReturn += str(state) + "\n"
        return toReturn
    def Accept(self, _input):
        if not self.InputInAlpha(_input):
            return (False, None)
        # Setup
        currentState = self.start
        stack = Stack()
        while True:
            # Check if we are able to end in an accepting state
            if len(_input) == 0 and stack.IsEmpty():
                break
        # If we end in an accepting state, 