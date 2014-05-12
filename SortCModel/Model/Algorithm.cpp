#include "Algorithm.h"
#include <iostream>

Algorithm::Algorithm(vector<int> startTuple) {
	this->startTuple = startTuple;
	this->numbOfcurrentStep = 0;
	this->numbOfSteps = 0;
	this->steps;
}

Algorithm::Algorithm(int anzValues)
{
	for (int i = 0; i < anzValues; i++)
	{
		this->startTuple.push_back((rand() % 100) + 1);
		cout << startTuple[i] << endl;
	}
	this->numbOfcurrentStep = 0;
	this->numbOfSteps = 0;
}

vector<int> Algorithm::get_currentTupel()
{
	return currentTupel;
}

vector<int> Algorithm::get_startTupel()
{
	return startTuple;
}


Algorithm::~Algorithm(void)
{
}

void Algorithm::sort()
{
	
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
