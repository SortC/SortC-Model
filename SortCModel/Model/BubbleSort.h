#pragma once
#include "algorithm.h"
class BubbleSort :
	public Algorithm
{
public:
	BubbleSort(vector<int> startTuple);
	BubbleSort(int anzValues);
	~BubbleSort(void);
	void sort();
	void ausgabe();
	Step getNextStep() override; 
	Step getPrevStep()  override;

};

