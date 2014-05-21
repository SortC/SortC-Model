#include "QuickSort.h"


QuickSort::QuickSort(int* values, int numberOfValues) : Algorithm(values, numberOfValues)
{
}


QuickSort::QuickSort(int numberOfValues) : Algorithm(numberOfValues)
{
}

void QuickSort::sort(){
	int left = 0;
	int right = numbOfValues-1;

	if(left >= right)
		return; // Invalid index range

	std::vector<std::pair<int, int> > list;

	Step *newStep;
	newStep = new Step(left,right, Operation::COMP, ++numbOfSteps);
	steps.push_back(newStep);  
	
	list.push_back(std::pair<int, int>(left, right));

	while(list.size() != 0)
	{
		left = list.back().first;
		right = list.back().second;
		list.pop_back();

		int pivot = partition(currentTupel, left, right);   

		std::pair<int,int> p;
		if(pivot > 1)
			list.push_back(std::pair<int, int>(left, pivot - 1));

		if(pivot + 1 < right)
			list.push_back(std::pair<int, int>(pivot + 1, right));
	}
}

int QuickSort::partition(int a[], int left, int right)
{
	int pivot = a[left];
	while (true)
	{
		
		while (a[left] < pivot)
			left++;

		while (a[right] > pivot)
			right--;

		// Wenn linker Zeiger rechten Zeiger noch nicht erreicht hat tausche Werte
		if (left < right)
		{
			//steps.push_back(new Step(
			int temp = a[right];
			a[right] = a[left];
			a[left] = temp;
			
		}
		else
		{
			return right;
		}
	}
}
