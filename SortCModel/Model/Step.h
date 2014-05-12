#pragma once


#include <string>
#include <vector>

using namespace std;

static enum Operation {SWAP, COMP, MARK };
class Step
{
public:
	Step(vector<int> *values, Operation operation, unsigned int number, string explantion);

	Step(vector<int> *values, Operation operation, unsigned int number);

	~Step(void);

	Operation getOperation() { return op ;}

private:
	vector<int> values;
	Operation op;
	int number;
	string explantion;
};

