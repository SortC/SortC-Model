#include "InsertionSort.h"


InsertionSort::InsertionSort(int* values, int numbOfValues) : Algorithm(values,numbOfValues)
{
}


InsertionSort::InsertionSort(int numberOfValues) : Algorithm(numberOfValues)
{
}

InsertionSort::~InsertionSort()
{
}

void InsertionSort::sort() 
{
	int i, j ,tmp;
	Step* newStep;
 
	for (i = 1; i < numbOfValues; i++) 
	{
		j = i;
 
		newStep = new Step(j-1,j, Operation::COMP, ++numbOfSteps);
		steps.push_back(newStep);
		while (j > 0 && currentTuple[j - 1] > currentTuple[j]) 
		{
			newStep = new Step(j-1,j, Operation::SWAP, ++numbOfSteps);
			steps.push_back(newStep);
			tmp = currentTuple[j];
			currentTuple[j] = currentTuple[j - 1];
			currentTuple[j - 1] = tmp;
			j--;
		}
	}
 }