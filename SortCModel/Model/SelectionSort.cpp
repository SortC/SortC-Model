#include "SelectionSort.h"


SelectionSort::SelectionSort(int* values, int numbOfValues) : Algorithm(values,numbOfValues)
{
}

SelectionSort::SelectionSort(int numbOfValues) : Algorithm(numbOfValues) 
{
}


SelectionSort::~SelectionSort(void)
{
}

void SelectionSort::sort()
{
	int i, j, tmp, min;
	Step* newStep;

	for( i = 0; i < numbOfValues - 1; i++)
    {
		newStep = new Step(i+1, 0, Operation::MIN, ++numbOfSteps);
		steps.push_back(newStep);
        min = i;

        for( j = i+1; j < numbOfValues; j++)
        {
			newStep = new Step(min+1,j+1, Operation::COMP, ++numbOfSteps);
			steps.push_back(newStep);
            if( currentTupel[j] < currentTupel[min])
			{
				steps.push_back(new Step(j+1, 0, Operation::MIN, ++numbOfSteps));
                min = j;
			}
        }
		
		newStep = new Step(i+1, min+1, Operation::SWAP, ++numbOfSteps);
		steps.push_back(newStep);
        tmp = currentTupel[min];
        currentTupel[min] = currentTupel[i];
        currentTupel[i] = tmp;
    }
}
