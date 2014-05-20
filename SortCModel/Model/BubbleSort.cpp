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

void BubbleSort::ausgabe()
{
    for(int i = 0; i< numberOfValues; i++){
        cout << i << ": " << currentTupel[i] << endl;
    }
    cout << "Anzahl Schritte " << numbOfSteps << endl;
} 

void BubbleSort::sort()
{ 
    for (int i = 0; i < numberOfValues - 1; ++i)
    {
        for (int j = 0; j < numberOfValues - i - 1; ++j)
        {
            int currentValues[2] = {j,j+1};
			steps.push_back(Step(currentValues, Operation::COMP, ++numbOfSteps));
            if (currentTupel[j] > currentTupel[j + 1])
            {

                int currentValues[2] = {j,j+1};
				steps.push_back(Step(currentValues, Operation::SWAP, ++numbOfSteps));
                int tmp = currentTupel[j];
                currentTupel[j] = currentTupel[j + 1];
                currentTupel[j + 1] = tmp;
            }
        }
    }

}