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
 
		newStep = new Step(i,i+1, Operation::COMP, ++numbOfSteps);
		steps.push_back(newStep);
		while (j > 0 && currentTupel[j - 1] > currentTupel[j]) 
		{
			newStep = new Step(j,j+1, Operation::SWAP, ++numbOfSteps);
			steps.push_back(newStep);
			tmp = currentTupel[j];
			currentTupel[j] = currentTupel[j - 1];
			currentTupel[j - 1] = tmp;
			j--;
		}
	}
 }