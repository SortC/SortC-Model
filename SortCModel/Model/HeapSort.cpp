#include "HeapSort.h"


HeapSort::HeapSort(int* values, int numbOfValues) : Algorithm(values,numbOfValues)
{
}

HeapSort::HeapSort(int numberOfValues) : Algorithm(numberOfValues)
{
}


HeapSort::~HeapSort(void)
{
}


void HeapSort::shiftRight(int low, int high)
{
    int root = low;
    while ((root*2)+1 <= high)
    {
        int leftChild = (root * 2) + 1;
        int rightChild = leftChild + 1;
        int swapIdx = root;
        /*Check if root is less than left child*/
		steps.push_back(new Step(swapIdx, leftChild, Operation::COMP, ++numbOfSteps));
        if (this->currentTuple[swapIdx] < this->currentTuple[leftChild])
        {
            swapIdx = leftChild;
        }
        /*If right child exists check if it is less than current root*/
		steps.push_back(new Step(swapIdx, high, Operation::COMP, ++numbOfSteps));
        if ((rightChild <= high) && (this->currentTuple[swapIdx] < this->currentTuple[rightChild]))
        {
            swapIdx = rightChild;
        }
        /*Make the biggest element of root, left and right child the root*/
        if (swapIdx != root)
        {
			steps.push_back(new Step(root, swapIdx, Operation::SWAP, ++numbOfSteps));
            int tmp = this->currentTuple[root];
            this->currentTuple[root] = this->currentTuple[swapIdx];
            this->currentTuple[swapIdx] = tmp;
            /*Keep shifting right and ensure that swapIdx satisfies
            heap property aka left and right child of it is smaller than
            itself*/
            root = swapIdx;
        }
        else
        {
            break;
        }
    }
    return;
}
void HeapSort::heapify(int low)
{
    /*Start with middle element. Middle element is chosen in
    such a way that the last element of array is either its
    left child or right child*/
    int midIdx = (this->numbOfValues - low -1)/2;
    while (midIdx >= 0)
    {
        shiftRight(midIdx, this->numbOfValues);
        --midIdx;
    }
    return;
}
void HeapSort::sort()
{
   /* assert(arr);
    assert(size > 0);*/
    /*This will put max element in the index 0*/	
    heapify(0);
    int high = this->numbOfValues - 1;
    while (high > 0)
    {
        /*Swap max element with high index in the array*/
        int tmp = this->currentTuple[high];
        this->currentTuple[high] = this->currentTuple[0];
        this->currentTuple[0] = tmp;
        steps.push_back(new Step(high, 0, Operation::SWAP, ++numbOfSteps));
		--high;
        /*Ensure heap property on remaining elements*/
        shiftRight(0, high);
    }
    return;
}