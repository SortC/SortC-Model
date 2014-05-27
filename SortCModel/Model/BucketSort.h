#pragma once
#include "algorithm.h"
#include <queue>

class BucketSort :
	public Algorithm
{
public:
	BucketSort(int* values, int numbOfValues);
	BucketSort(int numbOfValues);
	~BucketSort(void);
	void sort() override;
	queue<int>* getBuckets(){return buckets;};
protected:
	int hash(int n);
	void doinsertionsortforbucket(int* input, int len);

	queue<int> *buckets;
};

