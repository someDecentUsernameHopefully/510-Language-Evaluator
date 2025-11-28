#ifndef STATE_H
#define STATE_H

class Transition;

#include <string>
#include <map>
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
	map<char, Transition*> transitions;
	Transition* lambdaTransition;
	string name;
	bool _isAccept;
};

#endif