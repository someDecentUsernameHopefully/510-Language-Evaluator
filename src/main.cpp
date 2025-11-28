#include <vector>
#include <string>
#include <fstream>
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
		case 4:
			cout << "Cannot make state not in the Automata an accepting state!" << endl;
			break;
		default:
			cout << "Invalid Formatting!" << endl;
		}
		exit(1);
	}

	// Get the test strings
	ifstream testStrings(testFilename);
	string line;

	for (; getline(testStrings, line); ) {
		string output;
		if (line.back() == '\r') line = line.substr(0, line.size() - 1);
		if (A->Accept(line, &output, -1)) {
			cout << line << " is accepted. The output is: " << output << endl;
		}
		else {
			cout << line << " is not recognized by the turing machine.";
		}
	}

	testStrings.close();
	*/
	delete A;
	return 0;
}