class State:
    def __init__(self, name):
        self.name = name
        self.accepting = False
        self.transitions = {}
    def AddTransition(self, consume, trans):
        if consume in self.transitions:
            raise RuntimeError("Non-determinism is not supported!")
        self.transitions[consume] = trans