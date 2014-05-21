#pragma once
#include "algorithm.h"
class BucketSort :
	public Algorithm
{
public:
	BucketSort(int* values, int numbOfValues);
	BucketSort(int numbOfValues);
	~BucketSort(void);
	void sort() override;
};

