# Constants to represent the directions
LEFT = 0
RIGHT = 1

"""
    The tape, for use with Turing Machines
"""
class Tape:
    def __init__(self, string=None):
        self.left = None
        self.right = None
        # Base case: string is empty or None
        if(string is None or len(string) == 0):
            self.char = None
        # Recursive case: create another tape and attach it to itself
        else:
            self.char = string[0] if string[0] != " " else None
            self.right = Tape(string[1:])
            self.right.left = self
    # Make sure that Tape can be deleted after it is no longer necessary
    # Deleting one tape segment cascades across the entire tape.
    def __del__(self):
        if(self.left is not None):
            self.left.right = None
            del self.left
        if(self.right is not None):
            self.right.left = None
            del self.right
    def __str__(self):
        #return self.char if self.char is not None else "None"
        # Find the leftmost position on the tape
        t = self
        while(t.left is not None):
            t = t.left
        # Build the string to return by progressing right until the end of the tape is reached.
        toReturn = ""
        while(t is not None):
            if (t.char is not None):
                toReturn += t.char
            t = t.right
        return toReturn
    """
        Progresses the tape to the next position
        Returns: The next tape's position
    """
    def Progress(self, consumed, overwrite, _dir):
        # Check that the correct character is being consumed
        if(self.char != consumed):
            raise RuntimeError("Attempted to consume incorrect character on Tape!")
        # Overwrite the character
        self.char = overwrite
        # Get the appropriate part of the tape to return, expanding the tape if necessary
        if (_dir == LEFT):
            if(self.left is None):
                self.left = Tape()
                self.left.right = self
            return self.left
        elif (_dir == RIGHT):
            if(self.right is None):
                self.right = Tape()
                self.right.left = self
            return self.right
        else:
            raise ValueError(f"{_dir} is not LEFT or RIGHT!")