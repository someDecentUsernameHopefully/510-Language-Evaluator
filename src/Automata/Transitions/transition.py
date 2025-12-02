class Transition:
    def __init__(self, consumed, to):
        self.consumed = consumed
        self.to = to
    def __str__(self):
        return f"{self.consumed} -> {self.to.name}"