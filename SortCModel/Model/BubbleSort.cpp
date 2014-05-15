#include "BubbleSort.h"
#include <iostream>

BubbleSort::BubbleSort(vector<int> startTuple) : Algorithm(startTuple)
{

}

BubbleSort::BubbleSort(int anzValues) : Algorithm(anzValues) 
{

}


BubbleSort::~BubbleSort(void)
{
}

void BubbleSort::ausgabe()
{
	cout << "Anzahl Schritte " << numbOfSteps << endl;
} 

void BubbleSort::sort()
{ 
	vector<int>* v1;
	currentTupel = Algorithm::get_startTupel();
	for (int i = 0; i < currentTupel.size() - 1; ++i)
	{
		for (int j = 0; j < currentTupel.size() - i - 1; ++j)
		{
			/*v1 = new vector<int>;
			v1->push_back(j);
			v1->push_back(j+1);
			steps.push_back(Step(v1, Operation::COMP, ++numbOfcurrentStep));*/
			numbOfSteps++;
			if (currentTupel[j] > currentTupel[j + 1])
			{

				/*v1 = new vector<int>;
				v1->push_back(j);
				v1->push_back(j+1);
				steps.push_back(Step(v1, Operation::SWAP, ++numbOfcurrentStep));*/
				numbOfSteps++;
			    int tmp = currentTupel[j];
				currentTupel[j] = currentTupel[j + 1];
				currentTupel[j + 1] = tmp;
			}
		}
	}

}

Step BubbleSort::getNextStep(){
	vector<int> *v1 = new vector<int>();

	return Step(v1, Operation::COMP, 1);
}

Step BubbleSort::getPrevStep(){
	vector<int> *v1 = new vector<int>();

	return Step(v1, Operation::COMP, 1);
}