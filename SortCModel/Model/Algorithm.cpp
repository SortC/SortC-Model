#include "Algorithm.h"
#include <iostream>
#include <time.h>

Algorithm::Algorithm(int* values, int numberOfValues) {
	this->startTuple = values;
    this->currentTupel = values;
    this->numberOfValues = numberOfValues;
    this->numbOfcurrentStep = 0;
	this->numbOfSteps = 0;
	
}

Algorithm::Algorithm(int numberOfValues)
{
    this->numberOfValues = numberOfValues;
    this->currentTupel = new int[numberOfValues];
    
    srand(time(nullptr));
	for (int i = 0; i < numberOfValues; i++)
	{
		this->currentTupel[i] = rand() % 100;
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

int* Algorithm::get_currentTupel()
{
	return currentTupel;
}

int* Algorithm::get_startTupel()
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
