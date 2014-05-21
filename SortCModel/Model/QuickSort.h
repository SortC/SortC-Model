#pragma once
#include "algorithm.h"
#include <stack>

class QuickSort :
	public Algorithm
{
public:
	QuickSort(int* values, int numberOfValues);
	QuickSort(int numberOfValues);
	void sort() override;

private:
	/**
	 * erzeugt eine Teilliste
	 */
	int partition(int a[], int left, int right);
};

