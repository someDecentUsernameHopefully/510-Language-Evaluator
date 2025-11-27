#include <vector>
#include <string>
#include <iostream>
#include "turingMachine.hpp"
using namespace std;

int main(int argc, char* argv[]) {
	// Get the filename to build the automata from
	string filename;
	string testFilename;
	if (argc == 3) {
		filename = argv[1];
		testFilename = argv[2];
	}
	else {
		cout << "Usage: ./executable [AUTOMATA_FILENAME] [TEST_STRING_FILE]\n";
		exit(0);
	}
	// Build the automata
	TuringMachine* A;
	try {
		A = new TuringMachine(filename);
	}
	catch (int err) {
		switch (err) {
		case 1:
			cout << "Bad file input!" << endl;
			break;
		case 2:
			cout << "Missing data from file!" << endl;
			break;
		}
		exit(1);
	}

	delete A;
	return 0;
}