from Automata.automata import Automata
from Automata.state import State
from Automata.Transitions.transition import Transition

class RegularAutomata(Automata):
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
                    self._setupStates(line)
                case 3:
                    self._setAccepting(line)
                case _:
                    # Define each transition
                    # The format for a transition for regular automata is:
                    # [FROM] [CONSUMED_CHAR] [TO]
                    raw = line.split(" ")
                    dest = self.states[raw[2]]
                    T = Transition(raw[1], dest)
                    self.states[raw[0]].AddTransition(raw[1], T)
            tracker += 1
        F.close()
        if(tracker < 3):
            raise RuntimeError("States must be defined!")
    def Accept(self, _input):
        if not self.InputInAlpha(_input):
            return False
        currentState = self.start
        while(len(_input) > 0):
            if _input[0] not in currentState.transitions:
                return False
            currentState = currentState.transitions[_input[0]].to
            _input = _input[1:]
        return currentState.accepting
    def __str__(self):
        toReturn = f"REGULAR MACHINE\n{self.alphabet}\n"
        for state in self.states.values():
            toReturn += str(state)
        return toReturn