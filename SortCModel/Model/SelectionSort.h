#pragma once
#include "algorithm.h"
class SelectionSort :
	public Algorithm
{
public:
	SelectionSort(int* values, int numbOfValues);
	SelectionSort(int numbOfValues);
	~SelectionSort(void);
	void sort() override;
};

