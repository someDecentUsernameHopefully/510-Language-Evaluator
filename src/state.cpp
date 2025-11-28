#include "state.hpp"
#include <string>
#include <map>
#include "transition.hpp"
using namespace std;

State::State(string name, bool accept) :
	name(name),
	_isAccept(accept)
{
	this->lambdaTransition = nullptr;
}

State::~State() {
	// Delete all pointers in the hash table
	for (auto itr = this->transitions.begin(); itr != this->transitions.end(); itr++) {
		delete itr->second;
	}
	// Delete all pointers in the special lambda transition list
	delete this->lambdaTransition;
}

void State::AddTransition(char* consumed, Transition* t) {
	// Lambda Transition
	if (consumed == nullptr && lambdaTransition == nullptr) {
		this->lambdaTransition = t;
		return;
	}
	else if (consumed == nullptr) {
		throw t;
	}
	// All other transitions
	if (this->transitions.find(*consumed) == this->transitions.end()) {
		this->transitions.insert({ *consumed, t });
	}
	else {
		throw t;
	}
}

string State::GetName() const {
	return this->name;
}

bool State::IsAccepting() const {
	return this->_isAccept;
}

void State::SetAccepting(bool a) {
	this->_isAccept = a;
}