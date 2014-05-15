#pragma once


#include <string>
#include <vector>

using namespace std;

static enum Operation {SWAP, COMP, MARK };
class Step
{
public:
	Step(int* values, Operation operation, unsigned int number, string explanation);

	Step(int* values, Operation operation, unsigned int number);

	~Step(void);

	Operation getOperation() { return op ;}

protected:
	int* values;
	Operation op;
	int number;
	string explanation;
};

