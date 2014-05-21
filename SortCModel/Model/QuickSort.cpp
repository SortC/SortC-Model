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
	int pivotStelle = left;
steps.push_back(new Step(pivotStelle, 0, Operation::PIVOT, ++numbOfSteps));
	while (true)
	{

		while (a[left] < pivot){
			stringstream buffer;
			buffer << "Vergleiche Pivot an Stelle " << pivotStelle <<" mit LZ an Stelle " << left << endl;
			steps.push_back(new Step(pivotStelle, left,Operation::COMP, ++numbOfSteps, buffer.str() ));
			left++;
		}

		while (a[right] > pivot){
			stringstream buffer;
			buffer << "Vergleiche Pivot an Stelle " << pivotStelle <<" mit RZ an Stelle " << left << endl;
			steps.push_back(new Step(pivotStelle, left,Operation::COMP, ++numbOfSteps, buffer.str() ));
			right--;
		}


		stringstream buffer;
		buffer << "Prüfe ob Stelle von LZ (" << left << ") < als Stelle von RZ (" << right << ")" << endl;
		steps.push_back(new Step(pivotStelle, left,Operation::COMP, ++numbOfSteps, buffer.str() ));

		if (left < right)
		{
			steps.push_back(new Step(left, right,Operation::SWAP, ++numbOfSteps));
			int temp = a[right];
			a[right] = a[left];
			a[left] = temp;

		}
		else
		{
			steps.push_back(new Step(right, 0, Operation::PIVOT, ++numbOfSteps));
			return right;
		}
	}
}
