# Normally I would document more, but this is just a stack. We all know what this does.
# Also, I don't even think I used it at all.
class Stack:
    def __init__(self):
        self.array = []
    def IsEmpty(self):
        return self.Size() == 0
    def Size(self):
        return len(self.array)
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