#include "state.hpp"
#include <string>
#include <map>
#include <vector>
#include "transition.hpp"
using namespace std;

State::State(string name, bool accept) :
	name(name),
	_isAccept(accept)
{

}

State::~State() {
	// Delete all pointers in the hash table
	for (auto itr = this->transitions.begin(); itr != this->transitions.end(); itr++) {
		vector<Transition*>* list = itr->second;
		for (size_t i = 0; i < list->size(); i++) {
			delete (*list)[i];
		}
		delete list;
	}
	// Delete all pointers in the special lambda transition list
	for (size_t i = 0; i < this->lambdaTransitions.size(); i++) {
		delete lambdaTransitions[i];
	}
}

void State::AddTransition(char* consumed, Transition* t) {
	if (consumed == nullptr) {
		lambdaTransitions.push_back(t);
		return;
	}
	if (this->transitions.find(*consumed) != this->transitions.end()) {
		vector<Transition*>* vList = new vector<Transition*>();
		this->transitions.insert({ *consumed, vList });
	}
	this->transitions[*consumed]->push_back(t);
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