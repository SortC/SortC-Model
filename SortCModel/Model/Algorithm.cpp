#include "Algorithm.h"
#include <time.h>

Algorithm::Algorithm(int* values, int numbOfValues) {
	this->startTuple = values;
	this->currentTupel = values;
	this->numbOfValues = numbOfValues;
	this->numbOfCurrentStep = 0;
	this->numbOfSteps = 0;

}

Algorithm::Algorithm(int numbOfValues)
{
	this->numbOfValues = numbOfValues;
	this->currentTupel = new int[numbOfValues];
	this->startTuple = new int[numbOfValues];
	srand(time(nullptr));
	for (int i = 0; i < numbOfValues; i++)
	{
		this->currentTupel[i] = rand() % 100;
	}

	this->numbOfCurrentStep = 0;
	this->numbOfSteps = 0;
}

Algorithm::~Algorithm(void)
{
	for(int i = 0; i < numbOfSteps; i++){
		delete(steps[i]);
	}
}

void Algorithm::sort()
{

}

Step* Algorithm::getNextStep() {
	if(numbOfSteps == 0)
		sort();
	if (numbOfCurrentStep < numbOfSteps)
	{
		return steps[numbOfCurrentStep++];
	}
	else
	{
		return NULL;
	}
}

Step* Algorithm::getPrevStep() {
	if (numbOfCurrentStep > 0)
	{
		numbOfCurrentStep--;
		return steps[numbOfCurrentStep];
	}
	else
	{
		return NULL;
	}
}
