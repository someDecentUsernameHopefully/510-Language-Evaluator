#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "turingMachine.hpp"
#include "lib.hpp"
using namespace std;

TuringMachine::TuringMachine(string filename) {
	ifstream file(filename);
	bool done = false;
	vector<char> stackAlpha;

	try {
		for (int lineNo = 0; true; lineNo++) {
			string line;
			if (!getline(file, line)) break;
			switch (lineNo) {
			case 0: // Get the language alphabet
				this->LanguageAlphabet = split(line, " ");
				// If the automata is a turing machine, copy the language alphabet to the stack alphabet.
				this->AuxAlphabet = vector<char>(this->LanguageAlphabet); //copy(this->LanguageAlphabet);
				break;
			case 1: // Get the stack alphabet
				stackAlpha = split(line, " ");
				for (size_t i = 0; i < stackAlpha.size(); i++) {
					this->AuxAlphabet.push_back(stackAlpha[i]);
				}
				break;
			case 2: // Get a list of state names
				break;
			case 3: // Get a list of accepting states
				/*
					Mark the creation of the Automata is done.
					This constructor is NOT responsible for evaluating that each state is used, or that an accepting state
					Can be reached.
				*/
				done = true;
				break;
			default: // Implement each transition.
				break;
			};
		}

		if (!done) throw 2;

	}
	catch (int error) {
		file.close();
		throw error;
	}

	file.close();

};

bool TuringMachine::Accept(string input, string* output, long long maxSteps) const {
	throw 1;
}