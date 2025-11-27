#include "tape.hpp"
#include <string>
using namespace std;

//*
Tape::Tape(string inputString, Tape* left) {
	this->left = left;
	string next;
	switch (inputString.length()) {
	case 0:
		// Special Case: Empty String
		this->value = nullptr;
		this->right = nullptr;
		break;
	default:
		next = inputString.substr(1);
		this->right = new Tape(next, this);
		// Intentionally fall through to case 1
	case 1:
		// Read the first character into the string
		this->value = new char;
		*(this->value) = inputString.front();
		break;
	}
}
//*/
Tape::Tape(Tape* adj, bool fromLeft) {
	if (fromLeft) {
		this->left = adj;
		this->right = nullptr;
	}
	else {
		this->left = nullptr;
		this->right = adj;
	}
	this->value = nullptr;
}
Tape::~Tape() {
	delete this->value;
	this->right->left = nullptr;
	delete this->right;
	this->left->right = nullptr;
	delete this->left;
}
string Tape::ToString() const {
	const Tape* ptr = this;
	string toReturn = "";
	while (ptr->left != nullptr) ptr = ptr->left;
	while (ptr->right != nullptr) {
		char c;
		if (GetValue(&c)) toReturn.append(1, c);
		ptr = ptr->right;
	}
	return toReturn;
}
bool Tape::GetValue(char* returnAddress) const {
	if (this->value == nullptr) {
		return false;
	}
	else {
		*returnAddress = *(this->value);
		return true;
	}
}
Tape* Tape::Progress(char* newChar, bool right) {
	// Update value
	delete this->value;
	this->value = newChar;
	
	// Extend the tape if necessary
	if (right && this->right == nullptr) {
		this->right = new Tape(this, true);
	}
	else if (!right && this->left == nullptr) {
		this->left = new Tape(this, false);
	}

	// Return the new tape position
	return right ? this->right : this->left;
}