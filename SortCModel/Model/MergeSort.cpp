#include "MergeSort.h"


MergeSort::MergeSort(int* values, int numbOfValues) :Algorithm(values,numbOfValues)
{
	this->helperArray = new int[numbOfValues];
}

MergeSort::MergeSort(int numbOfValues):Algorithm(numbOfValues)
{
	this->helperArray = new int[numbOfValues];
}

MergeSort::~MergeSort(void)
{
}

void MergeSort::sort(){
	merge_sort(currentTupel,helperArray,0,numbOfValues-1);
}

void MergeSort::merge_sort(int *a, int*b, int low, int high)
{
	Step* newStep = new Step(low,high,Operation::MARK, ++numbOfSteps);
	steps.push_back(newStep);
	int pivot;
	if(low<high)
	{
		pivot=(low+high)/2;
		merge_sort(a,b,low,pivot);
		merge_sort(a,b,pivot+1,high);
		merge(a,b,low,pivot,high);
	}
}

void MergeSort::merge(int *a, int *b, int low, int pivot, int high)
{
	int h,i,j,k;
	h=low;
	i=low;
	j=pivot+1;

	while((h<=pivot)&&(j<=high))
	{
		if(a[h]<=a[j])
		{
			b[i]=a[h];
			h++;
		}
		else
		{
			b[i]=a[j];
			j++;
		}
		i++;
	}
	if(h>pivot)
	{
		for(k=j; k<=high; k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	else
	{
		for(k=h; k<=pivot; k++)
		{
			b[i]=a[k];
			i++;
		}
	}
	for(k=low; k<=high; k++) a[k]=b[k];
}
