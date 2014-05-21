#pragma once
#include "algorithm.h"
class HeapSort :
	public Algorithm
{
public:
	HeapSort(int* values, int numbOfValues);
	HeapSort(int numbOfValues);
	~HeapSort(void);
	void sort() override;
};

