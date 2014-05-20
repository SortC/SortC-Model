#include "Algorithm.h"
#include <time.h>

Algorithm::Algorithm(int* values, int numberOfValues) {
	this->startTuple = values;
	this->currentTupel = values;
	this->numbOfValues = numberOfValues;
	this->numbOfCurrentStep = 0;
	this->numbOfSteps = 0;

}

Algorithm::Algorithm(int numberOfValues)
{
	this->numbOfValues = numberOfValues;
	this->currentTupel = new int[numberOfValues];

	srand(time(nullptr));
	for (int i = 0; i < numberOfValues; i++)
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
