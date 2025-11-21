#include <vector>
#include <string>
#include <iostream>
#include "Automata.hpp"
using namespace std;

int main(int argc, char* argv[]) {
	// Get the filename to build the automata from
	string filename;
	string testOutput;
	if (argc == 3) {
		filename = argv[1];
		testOutput = argv[2];
	}
	else {
		cout << "Usage: ./executable [AUTOMATA_FILENAME] [TEST_STRING]\n";
		exit(0);
	}
	// Build the automata
	Automata* A;
	try {
		A = new Automata(filename);
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