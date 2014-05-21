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
protected:
	void merge(int *a, int *b, int low, int pivot, int high);
	void merge_sort(int *a, int*b, int low, int high);
	int* helperArray;
};

