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
                    # Get the space-separated language alphabet
                    self.alphabet = line.split(" ")
                case 2:
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
                case 3:
                    # Get the list of accepting states
                    for name in line.split(" "):
                        self.states[name].accepting = True
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
        currentState = self.start
        while(len(_input) > 0):
            if _input[0] not in currentState.transitions:
                return False
            currentState = currentState.transitions[_input[0]].to
            _input = _input[1:]
        return currentState.accepting