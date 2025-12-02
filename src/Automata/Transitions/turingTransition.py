from Automata.Transitions.transition import Transition
from Automata.DataStructures.tape import Tape, LEFT, RIGHT

class TuringTransition(Transition):
    def __init__(self, consumed, replace, direction, to):
        super().__init__(consumed, to)
        self.replace = replace
        match direction.upper():
            case "L":
                self.dir = LEFT
            case "R":
                self.dir = RIGHT
            case _:
                raise ValueError("Invalid direction!")
    def AdjustTape(self, tape):
        return tape.Progress(self.consumed, self.replace, self.dir)
    def __str__(self):
        return f"{self.consumed}/{self.replace}, {"L" if self.dir == LEFT else "R"} | {self.to.name}"