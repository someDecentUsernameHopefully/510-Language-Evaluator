from Automata.automata import Automata
from Automata.Transitions.turingTransition import TuringTransition
from Automata.DataStructures.tape import Tape

class TuringMachine(Automata):
    def __init__(self, filename):
        F = open(filename, "r")
        tracker = 0
        for line in F:
            line = line.strip("\n")
            if(line[0] == "#" or len(line) == 0):
                continue
            match tracker:
                case 0:
                    # This is just the type of automata. We already know this.
                    pass
                case 1:
                    self._setupAlphabet(line)
                    self.stackAlphabet = line.split(" ")
                case 2:
                    # Get the space-separated stack alphabet
                    for char in line.split(" "):
                        if char != "":
                            self.stackAlphabet.append(char)
                case 3:
                    self._setupStates(line)
                case 4:
                    self._setAccepting(line)
                case _:
                    # Define each transition
                    # The format for a transition for turing automata is:
                    # [FROM] [CONSUMED_CHAR] [REPLACED] [DIRECTION] [TO]
                    raw = line.split(" ")
                    origin = self.states[raw[0]]
                    dest = self.states[raw[4]]
                    for i in range(1,3):
                        raw[i] = None if raw[i] == "" else raw[i]
                    T = TuringTransition(origin, raw[1], raw[2], raw[3], dest)
                    origin.AddTransition(raw[1], T)
            tracker += 1
        F.close()
        if(tracker < 4):
            raise RuntimeError("States must be defined!")
        self.maxSteps = lambda steps : 16 * steps ** 2 + 16
    def Accept(self, _input):
        # Check if the entire string is in the alphabet
        if not self.InputInAlpha(_input):
            return (False, None, None)
        # Since turing machines can loop infinitely, a maximum number of steps is used to force the machine to halt.
        # This scales with the input size.
        # Add a constant 16 to allow for the empty string to have some transitions
        maxSteps = self.maxSteps(len(_input))
        # Generate the starting tape
        T = Tape(_input)
        # Keep track of the state
        currentState = self.start
        # Keep track of the transitions
        path = ""
        for i in range(maxSteps):
            # Check that the tape is in a valid state.
            # Realistically, this should never not be the case.
            if T.char is not None and T.char not in self.stackAlphabet:
                del T
                return (False, None, None)
            # Find the appropriate transition, and go along it.
            if T.char not in currentState.transitions:
                break
            trans = currentState.transitions[T.char]
            T = trans.AdjustTape(T)
            currentState = trans.to
            path += str(trans) + "\n"
            # If we hit a halt state, exit this loop.
            if currentState.accepting:
                break
        if currentState.accepting:
            toReturn = str(T)
            del T
            return (True, path, toReturn)
        else:
            del T
            return (False, None, None)
    def __str__(self):
        toReturn = f"TURING MACHINE\n{self.alphabet}\n{self.stackAlphabet}\n"
        for state in self.states.values():
            toReturn += str(state) + "\n"
        return toReturn