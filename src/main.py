from os import read
import sys
from Automata.regular import RegularAutomata
from Automata.pda import PDA
from Automata.turing import TuringMachine

def main():
    # Verify that there are the correct number of arguments.
    argv = sys.argv
    if(len(argv) != 3):
        print("Usage: ./main.py [MACHINE_FILE] [TEST_STRINGS]")
        sys.exit(1)
    # Assemble the automata
    automata = None
    automataType = None
    # Determine the type of machine so we know what type to use
    try:
        f = open(argv[1], 'r')
        automataType = f.read(3).upper()
        f.close()
        if automataType not in ("REG", "PDA", "TUR"):
            raise RuntimeError("Invalid machine type!")
    except RuntimeError as e:
        print(e)
        sys.exit(1)
    except FileNotFoundError as e:
        print(f"Could not find file {argv[2]}")
        sys.exit(1)
    # Build the machine
    match automataType:
        case "REG":
            automata = RegularAutomata(argv[1])
        case "PDA":
            automata = PDA(argv[1])
        case "TUR":
            automata = TuringMachine(argv[1])
    #print("The machine has been formed. It is:")
    #print(str(automata))
    # Get the file of test strings
    testStrings = None
    try:
        testStrings = open(argv[2], "r")
    except FileNotFoundError as e:
        print(f"Could not find file {argv[2]}")
    # Test each string
    for line in testStrings:
        line = line.strip("\n")
        output = automata.Accept(line)
        if(output is None or output is False):
            print(f"{line} is not recognized by the automata.")
        elif(isinstance(automata, TuringMachine)):
            print(f"{line} is recognized by the automata. The output is {output}")
        else:
            print(f"{line} is recognized by the automata.")
    testStrings.close()

main()