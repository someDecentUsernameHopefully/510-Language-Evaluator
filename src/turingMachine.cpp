#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "turingMachine.hpp"
#include "state.hpp"
#include "transition.hpp"
#include "lib.hpp"
using namespace std;

TuringMachine::TuringMachine(string filename) {
	ifstream file(filename);
	bool done = false;
	try {
		for (int lineNo = 0; true; lineNo++) {
			string line;
			cout << line << endl;
			if (!getline(file, line)) break;
			switch (lineNo) {
			case 0: // Get the language alphabet
				this->LanguageAlphabet = split(line, " ");
				// If the automata is a turing machine, copy the language alphabet to the stack alphabet.
				this->AuxAlphabet = vector<char>(this->LanguageAlphabet); //copy(this->LanguageAlphabet);
				break;
			case 1: // Get the stack alphabet
			{
				vector<char> stackAlpha = split(line, " ");
				for (size_t i = 0; i < stackAlpha.size(); i++) {
					this->AuxAlphabet.push_back(stackAlpha[i]);
				}
			}
				break;
			case 2: // Get a list of state names
			{
				vector<string> names = splitStr(line, " ");
				for (size_t i = 0; i < names.size(); i++) {
					State* s = new State(names[i], false);
					this->states.insert({ names[i], s });
				}
			}
				break;
			case 3: // Get a list of accepting states
			{
				vector<string> names = splitStr(line, " ");
				for (size_t i = 0; i < names.size(); i++) {
					this->states[names[i]]->SetAccepting(true);
				}
			}
				/*
					Mark the creation of the Automata is done.
					This constructor is NOT responsible for evaluating that each state is used, or that an accepting state
					Can be reached.
				*/
				done = true;
				break;
			default: // Implement each transition.
				// The format for a transition will be:
				// [FROM_STATE] [CONSUMED]/[REPLACED], [DIRECTION] [TO_STATE]
			{
				char* consume;
				char* replace;
				bool right;
				State* from;
				State* to;
				vector<string> dataRaw = splitStr(line, " ");
				// Handle States
				from = this->states[dataRaw[0]];
				to = this->states[dataRaw[3]];
				
				// Get Tape Direction
				if (dataRaw[2].size() == 0) throw 3;
				else if (dataRaw[2][0] == 'l' || dataRaw[2][0] == 'L') right = false;
				else if (dataRaw[2][0] == 'r' || dataRaw[2][0] == 'R') right = true;
				else throw 3;
				// Get consumed/replaced characters
				vector<string> moreData = splitStr(dataRaw[1], "/");
				if (moreData[0] == (string)"lambda") consume = nullptr;
				else {
					consume = new char;
					*consume = moreData[0][0];
				}
				if (moreData[1] == (string)"lambda,") replace = nullptr;
				else {
					replace = new char;
					*replace = moreData[1][0];
				}
				// Create Transition, add it to from state
				Transition* T = new Transition(consume, replace, right, to);
				from->AddTransition(consume, T);
			}
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