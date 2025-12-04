class State:
    def __init__(self, name):
        self.name = name
        self.accepting = False
        self.transitions = {}
    def __del__(self):
        keys = []
        for key in self.transitions.keys():
            keys.append(key)
        for key in keys:
            del self.transitions[key]
    def AddTransition(self, consume, trans):
        if consume in self.transitions:
            raise RuntimeError("Non-determinism is not supported!")
        self.transitions[consume] = trans
    def __str__(self):
        accepting = "+" if self.accepting else ""
        toReturn = f"{accepting}{self.name}\n"
        for trans in self.transitions.values():
            toReturn += "\t" + str(trans) + "\n"
        return toReturn