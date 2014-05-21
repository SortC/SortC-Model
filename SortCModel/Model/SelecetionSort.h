#pragma once
#include "algorithm.h"
class SelecetionSort :
	public Algorithm
{
public:
	SelecetionSort(int* values, int numbOfValues);
	SelecetionSort(int numbOfValues);
	~SelecetionSort(void);
	void sort() override;
};

