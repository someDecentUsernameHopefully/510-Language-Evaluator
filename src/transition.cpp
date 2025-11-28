#include "transition.hpp"
#include "state.hpp"
#include "tape.hpp"

Transition::Transition(char* consumed, char* overwrite, bool tapeRight, State* to) :
consumed(consumed),
overwrite(overwrite),
tapeRight(tapeRight),
to(to)
{
}

Transition::~Transition() {
	// States should all be deallocated together.
	// Transition destructor is not responsible for this.
	delete consumed;
	delete overwrite;
}

State Transition::NextState() const {
	return *(this->to);
}
bool Transition::UpdateTape(Tape* t) const {
	char* c = nullptr;
	if((!t->GetValue(c) && consumed == nullptr) || (*c == *consumed)) return false;
	char* o = nullptr;
	if (overwrite != nullptr) {
		o = new char;
		*o = *overwrite;
	}
	t = t->Progress(o, this->tapeRight);
	return true;
}