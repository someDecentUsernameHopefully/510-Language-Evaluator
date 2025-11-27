#include <string>
using namespace std;

#ifndef TAPE_H
#define TAPE_H

class Tape {
public:
	/// <summary>
	/// Creates a new Tape based on an input string.
	/// </summary>
	/// <param name="inputString">The inital string to be processed</param>
	/// <param name="left">The previous position on the tape.
	/// This should not be messed with outside of being called within the Tape's methods.</param>
	Tape(string inputString, Tape* left = nullptr);
	Tape(Tape* adj, bool fromLeft);
	~Tape();
	explicit operator string() const { return this->ToString(); }
	/// <summary>
	/// The function used to progress the tape on a transition.
	/// </summary>
	/// <param name="newChar">The value to overwrite the character at this tape position</param>
	/// <param name="right">Whether the tape should go right (or left)</param>
	/// <returns>A pointer to the next tape position.</returns>
	Tape* Progress(char* newChar, bool right);
	/// <summary>
	/// Gets the value at the current position in the tape.
	/// </summary>
	/// <param name="returnAddress">The pointer to put the output to.</param>
	/// <returns>Whether or not this position on the Tape is not null</returns>
	bool GetValue(char* returnAddress) const;
	string ToString() const;
private:
	char* value;
	Tape* left;
	Tape* right;
};

#endif