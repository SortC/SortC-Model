#include "BubbleSort.h"
#include <iostream>

BubbleSort::BubbleSort(vector<int> startTuple) : Algorithm(startTuple)
{

}
BubbleSort::BubbleSort(int anzValues) : Algorithm(anzValues) 
{
	for (int i = 0; i < anzValues - 1; i++)
	{
		tupel.push_back(rand() % 100);
		cout << tupel[i] << endl;
	}
}


BubbleSort::~BubbleSort(void)
{
}

void BubbleSort::sort(vector<int> &liste)
{ 
    for (int i = 0; i < liste.size() -1; ++i) 
    {
 		for (int j = 0; j < liste.size() - i - 1; ++j) 
		{
 			if (liste[j] > liste[j + 1]) 
			{
 				int tmp = liste[j];
 				liste[j] = liste[j + 1];
 				liste[j + 1] = tmp;
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

vector<int> BubbleSort::getTupel()
{
	return tupel;
} 