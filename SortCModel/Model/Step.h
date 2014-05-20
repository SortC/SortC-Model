#pragma once


#include <string>
#include <vector>
#include <sstream>

using namespace std;

static enum Operation {SWAP, COMP, MARK };
class Step
{
public:
	Step(int firstValue, int secondValue, Operation operation, unsigned int number, string explanation);

	Step(int firstValue, int secondValue, Operation operation, unsigned int number);

	~Step(void);

	Operation getOperation() { return op;};

	int getNumber(){ return number;};

	string toString();

protected:
	int firstValue;
	int secondValue;
	Operation op;
	int number;
	string explanation;
};

