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

	const int length = 15;
	const int lengthOp = 7;
	const char filler = ' ';
	stringstream buffer;
	buffer << "["<< setfill(' ') << setw(2) << number <<"]"<< setw(3)  << ""  ;
	if(explanation.empty()){
		switch (op)
		{
		case SWAP: buffer << setw(lengthOp) << left << "SWAP" << setfill(filler) << setw(length) << left  << "Tausche"  << "[" << firstValue << "] mit [" << secondValue << "]"<< endl;
			break;
		case COMP: buffer << setw(lengthOp) << left << "COMP" << setfill(filler) << setw(length)  << left << "Vergleiche" <<"[" <<firstValue << "] mit [" << secondValue << "]" << endl;
			break;
		case MARK: buffer << setw(lengthOp) << left << "MARK" << setfill(filler) << setw(length) << left  << "Betrachte" << "[" << firstValue << "] bis [" << secondValue << "]" << endl;
			break;
		case PIVOT: buffer << setw(lengthOp) << left << "PIVOT" <<setfill(filler) << setw(length) << left  << "Setze Pivotelement auf" << "[" << firstValue<< "]"  <<endl;
			break;
		case CPY: buffer << setw(lengthOp) << left << "CPY" << setfill(filler) << setw(length) << left  << "Kopiere" << "[" << firstValue << "] ins Hilfsarray nach [" << secondValue << "]" << endl;
			break;
		case R_CPY: buffer << setw(lengthOp) << left << "R_CPY" << setfill(filler) << setw(length) << left  << "Kopiere"<<"[" << firstValue << "] aus dem Hilfsarray [" << secondValue << "]" << endl;
			break;
		case MIN: buffer << setw(lengthOp) << left << "MIN" << setfill(filler) << setw(length) << left  <<"Setzt" << "[" << firstValue << "] als kleinstes Element" << endl;
			break;
		default:
			break;
		}
		explanation = buffer.str();
	}
	else
	{
			stringstream b2;
			b2 << buffer.str() << explanation;
			explanation = b2.str();
	}
	return this->explanation;
}

Step::~Step(void){
}
