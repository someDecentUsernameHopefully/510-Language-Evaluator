#ifndef STATE_H
#define STATE_H

class Transition;

#include <string>
#include <map>
#include <vector>
#include "transition.hpp"
using namespace std;

class State {
public:
	State(string name, bool accept);
	~State();
	void AddTransition(char*, Transition*);
	string GetName() const;
	bool IsAccepting() const;
	void SetAccepting(bool set);
private:
	map<char, vector<Transition*>*> transitions;
	vector<Transition*> lambdaTransitions;
	string name;
	bool _isAccept;
};

#endif