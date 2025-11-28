#ifndef TRANSITION_H
#define TRANSITION_H

class State;

#include "state.hpp"
#include "tape.hpp"

class Transition {
public:
	Transition(char* consumed, char* overwrite, bool tapeRight, State* to);
	~Transition();
	State NextState() const;
	/// <summary>
	/// Updates the tape based on the transition.
	/// </summary>
	/// <param name="t">The tape to be updated.</param>
	/// <returns>Whether or not the transition was successful.</returns>
	bool UpdateTape(Tape* t) const;
private:
	char* consumed;
	char* overwrite;
	bool tapeRight;
	State* to;
};

#endif // !TRANSITION_H