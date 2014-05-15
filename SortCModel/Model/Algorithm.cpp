#include "Algorithm.h"
#include <iostream>
#include <time.h>

Algorithm::Algorithm(vector<int> startTuple) {
	this->startTuple = startTuple;
	this->numbOfcurrentStep = 0;
	this->numbOfSteps = 0;
	this->steps;
}

Algorithm::Algorithm(int anzValues)
{
	srand(time(nullptr));
	for (int i = 0; i < anzValues; i++)
	{
		this->startTuple.push_back(rand() % 100);
	}

	this->numbOfcurrentStep = 0;
	this->numbOfSteps = 0;
}

Algorithm::~Algorithm(void)
{
}

void Algorithm::sort()
{
	
}

vector<int> Algorithm::get_currentTupel()
{
	return currentTupel;
}

vector<int> Algorithm::get_startTupel()
{
	return startTuple;
}


Step Algorithm::getNextStep() {
	if (numbOfcurrentStep < numbOfSteps)
	{
		numbOfcurrentStep++;
		return steps[numbOfcurrentStep];
	}
	else
	{
		throw "Keine nachfolgenden Schritte mehr vorhanden";
	}
}

Step Algorithm::getPrevStep() {
	if (numbOfcurrentStep > 0)
	{
		numbOfcurrentStep--;
		return steps[numbOfcurrentStep];
	}
	else
	{
		throw "Keine vorherigen Schritte mehr vorhanden";
	}
}
