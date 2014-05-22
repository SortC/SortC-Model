#pragma once
#include "algorithm.h"
class BubbleSort :
	public Algorithm
{
public:
	BubbleSort(int* values, int numbOfValues);
	BubbleSort(int numbOfValues);
	~BubbleSort(void);
	void sort() override;
};

