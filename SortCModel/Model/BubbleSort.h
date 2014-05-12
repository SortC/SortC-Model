#pragma once
#include "algorithm.h"
class BubbleSort :
	public Algorithm
{
public:
	BubbleSort(vector<int> startTuple);
	BubbleSort(int anzValues);
	~BubbleSort(void);
	void sort(vector<int> &liste);
	Step getNextStep() override; 
	Step getPrevStep()  override;
	vector<int> getTupel();

private:
	vector<int> tupel;
};

