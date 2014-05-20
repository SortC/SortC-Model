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

string Step::toString(){
	if(explanation.empty()){
		stringstream buffer;
		switch (op)
		{
		case SWAP: buffer << "Tausche Stelle " << values[0] << " mit Stelle " << values[1] << endl;
			break;
		case COMP: buffer << "Vergleiche Stelle " << values[0] << " mit Stelle " << values[1] << endl;
			break;
		case MARK: buffer << "Betrachte Bereich von Stelle " << values[0] << " bis Stelle " << values[1] << endl;
			break;
		default:
			break;
		}
		return buffer.str();
	}else{
		return explanation;
	}
}

Step::~Step(void){
}
