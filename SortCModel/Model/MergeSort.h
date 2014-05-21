#pragma once
#include "algorithm.h"
class MergeSort :
	public Algorithm
{
public:
	MergeSort(int* values, int numbOfValues);
	MergeSort(int numbOfValues);
	~MergeSort();
	void sort();
};

