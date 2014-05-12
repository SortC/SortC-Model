#pragma once


#include <string>
#include <vector>

using namespace std;
class Step
{
public:
	enum Operation {swap,  };
	Step(vector<int> values, Operation operation, unsigned int number, string explantion);

	Step(vector<int> values, Operation operation, unsigned int number);

	~Step(void);

	Operation getOperation() { return op ;}

private:
	vector<int> values;
	Operation op;
	int number;
	string explantion;
};

