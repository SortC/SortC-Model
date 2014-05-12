#pragma once
#include "algorithm.h"
class BubbleSort :
	public Algorithm
{
public:
	BubbleSort(vector<int> startTuple);
	BubbleSort(int anzValues);
	~BubbleSort(void);
	void sort() override;
	Step getNextStep() override; 
	Step getPrevStep()  override;

};

