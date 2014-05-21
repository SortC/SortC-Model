#pragma once


#include <string>
#include <vector>
#include <sstream>

using namespace std;

static enum Operation {SWAP, COMP, MARK, PIVOT, CPY, R_CPY, MIN };
class Step
{
public:
	Step(int firstValue, int secondValue, Operation operation, unsigned int number, string explanation);

	Step(int firstValue, int secondValue, Operation operation, unsigned int number);

	~Step(void);

	/**
	* Liefert explanation zurück
	* erstellt eine Explanation aus den vorliegenden Informationen, falls keine Existiert
	*/
	string toString();

	/**
	* Getter-Funktionen
	*/
	Operation getOperation() { return op; };
	int getNumber(){ return number; };
	int getFirstValue(){ return firstValue; };
	int getSecondValue(){ return secondValue; };

protected:
	int firstValue;
	int secondValue;
	Operation op;
	int number;
	string explanation;
};

