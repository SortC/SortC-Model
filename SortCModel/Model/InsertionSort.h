#pragma once
#include "algorithm.h"
class InsertionSort :
	public Algorithm
{
public:
	InsertionSort(int* values, int numbOfValues);
	InsertionSort(int numbOfValues);
	~InsertionSort(void);
	void sort() override;
};

