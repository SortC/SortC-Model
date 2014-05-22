#include "Step.h"

Step::Step(int firstValue, int secondValue, Operation operation, unsigned int number, string explanation){
	this->firstValue = firstValue;
	this->secondValue = secondValue;
	this->op = operation;
	this->number = number;
	this->explanation = explanation;
}
	
Step::Step(int firstValue, int secondValue, Operation operation, unsigned int number){
	this->firstValue = firstValue;
	this->secondValue = secondValue;
	this->op = operation;
	this->number = number;
	this->explanation = "";
}

string Step::toString(){
	if(explanation.empty()){
		stringstream buffer;
		switch (op)
		{
		case SWAP: buffer << "Tausche \t [" << firstValue << "] mit [" << secondValue << "]"<< endl;
			break;
		case COMP: buffer << "Vergleiche \t [" << firstValue << "] mit [" << secondValue << "]" << endl;
			break;
		case MARK: buffer << "Betrachte \t [" << firstValue << "] bis [" << secondValue << "]" << endl;
			break;
		case PIVOT: buffer << "Setze Pivotelement auf \t [" << firstValue<< "]"  <<endl;
			break;
		case CPY: buffer << "Kopiere \t [" << firstValue << "] ins Hilfsarray nach [" << secondValue << "]" << endl;
			break;
		case R_CPY: buffer << "Kopiere \t [" << firstValue << "] aus dem Hilfsarray [" << secondValue << "]" << endl;
			break;
		case MIN: buffer << "Setzt\t \t [" << firstValue << "] als kleinstes Element" << endl;
			break;
		default:
			break;
		}
		explanation = buffer.str();
	}
	return this->explanation;
}

Step::~Step(void){
}
