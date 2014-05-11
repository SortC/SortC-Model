#include "Step.h"
Step::Step(vector<int> values, operation operation, unsigned int number, string explantion){
	this->values = values;
	this->op = operation;
	this->number = number;
	this->explantion = explantion;
}
	
Step::Step(vector<int> values, operation operation, unsigned int number){
	this->values = values;
	this->op = operation;
	this->number = number;
}

Step::~Step(void)
{
}
