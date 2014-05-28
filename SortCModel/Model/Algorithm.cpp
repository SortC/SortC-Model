#include "Algorithm.h"
#include <time.h>

Algorithm::Algorithm(int* values, int numbOfValues) {
	this->currentTuple = new int[numbOfValues];
	this->startTuple = new int[numbOfValues];
	maxValue = 0;
	for (int i = 0; i < numbOfValues; i++)
	{
		this->currentTuple[i] = values[i];
		this->startTuple[i] = values[i];
		if(maxValue < values[i])
			maxValue = values[i];
	}
	this->numbOfValues = numbOfValues;
	this->numbOfCurrentStep = 0;
	this->numbOfSteps = 0;
	this->isSorted = false;
}

Algorithm::Algorithm(int numbOfValues)
{
	this->numbOfValues = numbOfValues;
	this->currentTuple = new int[numbOfValues];
	this->startTuple = new int[numbOfValues];
	srand(time(nullptr));
	maxValue = 100;
	for (int i = 0; i < numbOfValues; i++)
	{
		this->currentTuple[i] = rand() % maxValue;
		this->startTuple[i] = this->currentTuple[i];
	}

	this->numbOfCurrentStep = 0;
	this->numbOfSteps = 0;
	this->isSorted = false;
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

void Algorithm::doSort(){
	if(!isSorted){
		sort();
		isSorted= true;
	}
}

Step* Algorithm::getNextStep() {
	if(numbOfSteps == 0)
		doSort();
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
