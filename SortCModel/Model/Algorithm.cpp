#include "Algorithm.h"

Algorithm::Algorithm(vector<int> startTuple) {
	this->startTuple = startTuple;
	this->numbOfactualStep = 0;
	this->numbOfSteps = 0;
	this->steps;
}

Algorithm::Algorithm(int anzValues){
	for (int i = 0; i < anzValues; i++)
	{
		this->startTuple.push_back((rand() % 100) + 1);
	}
	this->numbOfactualStep = 0;
	this->numbOfSteps = 0;

}



Algorithm::~Algorithm(void)
{
}

Step Algorithm::getNextStep() {
	if (numbOfactualStep < numbOfSteps)
	{
		numbOfactualStep++;
		return steps[numbOfactualStep];
	}
	else
	{
		throw "Keine nachfolgenden Schritte mehr vorhanden";
	}
}

Step Algorithm::getPrevStep() {
	if (numbOfactualStep > 0)
	{
		numbOfactualStep--;
		return steps[numbOfactualStep];
	}
	else
	{
		throw "Keine vorherigen Schritte mehr vorhanden";
	}
}
