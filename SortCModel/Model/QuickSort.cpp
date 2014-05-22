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

	vector<std::pair<int, int> > list;

	//Step *newStep;

	list.push_back(pair<int, int>(left, right));

	while(list.size() != 0)
	{
		left = list.back().first;
		right = list.back().second;
		list.pop_back();

		int pivot = partition(currentTuple, left, right);   

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

	stringstream buffer;
	buffer << "Betrachte Bereich   [" << left <<"] bis  [" << right << "]" << endl;
	steps.push_back(new Step(left, right, Operation::MARK, ++numbOfSteps, buffer.str()));
	stringstream buffer2;
	buffer2 << "Setze Pivot auf\t      [" << right << "]" << endl;
	steps.push_back(new Step(pivotStelle, 0, Operation::PIVOT, ++numbOfSteps, buffer2.str() ));
	while (true)
	{

		while (a[left] < pivot){
			stringstream buffer;
			buffer << "Pruefe ob \tPivot[" << pivotStelle <<"]  < LZ[" << left << "]" << endl;
			steps.push_back(new Step(pivotStelle, left,Operation::COMP, ++numbOfSteps, buffer.str() ));
			left++;
		}

		while (a[right] > pivot){
			stringstream buffer;
			buffer << "Pruefe ob \tPivot[" << pivotStelle <<"]  > RZ[" << right <<"]" << endl;
			steps.push_back(new Step(pivotStelle, left,Operation::COMP, ++numbOfSteps, buffer.str() ));
			right--;
		}


		stringstream buffer;
		buffer << "Pruefe ob \tLZ   [" << left << "]  < RZ[" << right << "]" << endl;
		steps.push_back(new Step(pivotStelle, left,Operation::COMP, ++numbOfSteps, buffer.str() ));

		if (left < right)
		{
			stringstream buffer;
			buffer << "Tausche \t     [" << left << "] mit  [" << right << "]" << endl;
			steps.push_back(new Step(left, right,Operation::SWAP, ++numbOfSteps, buffer.str() ));
			int temp = a[right];
			a[right] = a[left];
			a[left] = temp;
			left++;

		}
		else 
		{
			stringstream buffer;
			buffer << "Setze Pivot auf\t      [" << right << "]" << endl;
			//steps.push_back(new Step(right, 0, Operation::PIVOT, ++numbOfSteps, buffer.str() ));
			return right;
		}
	}
}