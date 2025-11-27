#include <vector>
#include <string>
#include "lib.hpp"
using namespace std;

vector<char> split(const string toSplit, const string delimeter) {
	vector<string> strings = splitStr(toSplit, delimeter);
	vector<char> toReturn;
	for (int i = 0; i < (int)strings.size(); i++) {
		if(!strings[i].empty()) toReturn.push_back(strings[i][0]);
	}
	return toReturn;
}
vector<string> splitStr(const string toSplit, const string delimeter) {
	vector<string> toReturn;
	size_t indexAfter = 0;
	for (; indexAfter < toSplit.size() - 1;) {
		size_t next = toSplit.find(delimeter, indexAfter);
		string toAdd;
		if ((int)next == -1) {
			toAdd = toSplit.substr(indexAfter, toSplit.size());
			indexAfter = toSplit.size();
		}
		else {
			toAdd = toSplit.substr(indexAfter, next - indexAfter);
			indexAfter = next + 1;
		}
		toReturn.push_back(toAdd);
	}
	return toReturn;
}