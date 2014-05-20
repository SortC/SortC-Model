#include "BubbleSort.h"
#include <iostream>

BubbleSort::BubbleSort(int* values, int numberOfValues) : Algorithm(values,numberOfValues)
{

}

BubbleSort::BubbleSort(int numberOfValues) : Algorithm(numberOfValues) 
{

}


BubbleSort::~BubbleSort(void)
{

}

void BubbleSort::sort()
{ 
	int tmp = 0;
	Step* newStep;
	for (int i = 0; i < numbOfValues - 1; ++i)
	{
		for (int j = 0; j < numbOfValues - i - 1; ++j)
		{
			newStep = new Step(j,j+1, Operation::COMP, ++numbOfSteps);
			steps.push_back(newStep);
			if (currentTupel[j] > currentTupel[j + 1])
			{
				newStep = new Step(j,j+1, Operation::SWAP, ++numbOfSteps);
				steps.push_back(newStep);
				tmp = currentTupel[j];
				currentTupel[j] = currentTupel[j + 1];
				currentTupel[j + 1] = tmp;
			}
		}
	}

}