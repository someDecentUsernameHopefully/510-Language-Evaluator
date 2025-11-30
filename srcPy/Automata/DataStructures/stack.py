# Normally I would document more, but this is just a stack. We all know what this does.
class Stack:
    def __init__(self):
        self.array = []
    def IsEmpty(self):
        return len(self.array) == 0
    def Push(self, entry):
        self.array.append(entry)
    def Peek(self):
        if(self.IsEmpty()):
            raise RuntimeError("Cannot peek empty stack")
        return self.array[len(self.array) - 1]
    def Pop(self):
        toReturn = self.Peek()
        self.array.pop(len(self.array) - 1)
        return toReturn