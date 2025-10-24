#include <vector>
#include <string>
using namespace std;

#ifndef AUTOMATA_H
#define AUTOMATA_H

class Automata {
public:
	Automata(string filename);
	enum Type {
		Simple,
		Pushdown,
		Turing
	};
	Type type;
private:
	vector<char> LanguageAlphabet;
	vector<char> AuxAlphabet;
};

#endif // !AUTOMATA_H