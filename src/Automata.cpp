#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "Automata.hpp"
#include "State.hpp"
#include "Lib.hpp"
using namespace std;

Automata::Automata(string filename) {
	ifstream file(filename);
	bool done = false;

	try {
		for (int lineNo = 0; true; lineNo++) {
			string line;
			if (!getline(file, line)) break;
			switch (lineNo) {
			case 0: // Get the type of machine.
				switch (line) {
				case "SMP":
					this->type = Automata::Type.Simple;
					break;
				case "PDA":
					this->type = Automata::Type.Pushdown;
					break;
				case "TUR":
					this->type = Automata::Type.Turing;
					break;
				default:
					throw 1;
				};
				break;
			case 1: // Get the language alphabet
				this->LanguageAlphabet = split(line, " ");
				// If the automata is a simple automata, skip the next iteration because it involves
				// The stack alphabet.
				if (this->type == Automata::Type.Simple) lineNo++;
				// If the automata is a turing machine, copy the language alphabet to the stack alphabet.
				if (this->type == Automata::Type.Turing) this->AuxAlphabet = copy(this->LanguageAlphabet);
				break;
			case 2: // Get the stack alphabet
				vector<char> stackAlpha = split(line, " ");
				for (int i = 0; i < stackAlpha.size(); i++) {
					this->AuxAlphabet.push_back(stackAlpha[i]);
				}
				break;
			case 3: // Get a list of state names
				break;
			case 4: // Get a list of accepting states
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