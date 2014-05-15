#include "Step.h"

Step::Step(int* values, Operation operation, unsigned int number, string explantion){
	this->values = values;
	this->op = operation;
	this->number = number;
	this->explanation = explantion;
}
	
Step::Step(int* values, Operation operation, unsigned int number){
	this->values = values;
	this->op = operation;
	this->number = number;
	this->explanation = "";
}

Step::~Step(void){
}
