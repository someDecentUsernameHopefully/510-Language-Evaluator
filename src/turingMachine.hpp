#include <vector>
#include <map>
#include <string>
#include "state.hpp"
using namespace std;

#ifndef TURING_H
#define TURING_H

class TuringMachine {
public:
	TuringMachine(string filename);
	~TuringMachine();
	/// <summary>
	/// Determines if a string belongs to a Turing Machine.
	/// </summary>
	/// <param name="input">The input string.</param>
	/// <param name="output">A pointer to a string for output.</param>
	/// <param name="maxSteps">The maximum allowed amount of transitions before a failure.
	/// A negative value allows a test to run indefinitely.</param>
	/// <returns>Whether or not the string is accepted by the Automata</returns>
	bool Accept(string input, string* output, long long maxSteps = -1) const;
private:
	vector<char> LanguageAlphabet;
	vector<char> AuxAlphabet;
	map<string, State*> states;
};

#endif // !AUTOMATA_H