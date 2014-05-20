#pragma once
#include "algorithm.h"
class BubbleSort :
	public Algorithm
{
public:
	BubbleSort(int* values, int numberOfValues);
	BubbleSort(int numberOfValues);
	~BubbleSort(void);
	void sort();
};

