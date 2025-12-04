class Transition:
    def __init__(self, _from, consumed, to):
        self._from = _from
        self.consumed = consumed
        self.to = to
    def __str__(self):
        return f"{self._from.name} -> {self.consumed} -> {self.to.name}"