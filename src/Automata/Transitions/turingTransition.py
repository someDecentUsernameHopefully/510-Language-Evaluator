from Automata.Transitions.transition import Transition
from Automata.DataStructures.tape import Tape, LEFT, RIGHT

class TuringTransition(Transition):
    def __init__(self, _from, consumed, replace, direction, to):
        super().__init__(_from, consumed, to)
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
        dirStr = "<-" if self.dir == LEFT else "->"
        return f"{self._from.name} | {self.consumed}/{self.replace}, {dirStr} | {self.to.name}"