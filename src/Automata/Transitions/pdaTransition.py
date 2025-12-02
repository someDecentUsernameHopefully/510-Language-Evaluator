from Automata.Transitions.transition import Transition
from Automata.DataStructures.stack import Stack

class PDATransition(Transition):
    def __init__(self, consumed, to, stackTop, stackAppend):
        super().__init__(consumed, to)
        self.stackTop = stackTop
        self.stackAppend = stackAppend
    def ApplyStack(self, stack):
        if self.stackTop is None or (not stack.IsEmpty() and stack.Pop() == self.stackTop):
            # The top of the stack was removed in the check above
            for char in self.stackAppend:
                stack.Push(char)
        else:
            raise RuntimeError("Invalid stack state on transition!")