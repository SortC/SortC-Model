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
		case SWAP: buffer << "Tausche Stelle " << firstValue << " mit Stelle " << secondValue << endl;
			break;
		case COMP: buffer << "Vergleiche Stelle " << firstValue << " mit Stelle " << secondValue << endl;
			break;
		case MARK: buffer << "Betrachte Bereich von Stelle " << firstValue << " bis Stelle " << secondValue << endl;
			break;
		case PIVOT: buffer << "Setze Pivotelement auf Stelle " << firstValue <<endl;
			break;
		case CPY: buffer << "Kopiere Stelle " << firstValue << " ins Hilfsarray nach Stelle " << secondValue << endl;
			break;
		case R_CPY: buffer << "Kopiere Stelle " << firstValue << " aus dem Hilfsarray nach Stelle " << secondValue << endl;
			break;
		case MIN: buffer << "Setzt das Element an Stelle " << firstValue << " als kleinstes Element" << endl;
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
