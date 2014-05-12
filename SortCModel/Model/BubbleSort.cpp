#include "BubbleSort.h"

BubbleSort::BubbleSort(vector<int> startTuple) : Algorithm(startTuple){

}
BubbleSort::BubbleSort(int anzValues) : Algorithm(anzValues) {
}


BubbleSort::~BubbleSort(void)
{
}

void BubbleSort::sort(){

}

Step BubbleSort::getNextStep() {
	vector<int> *v1 = new vector<int>();

	return Step(v1, Operation::COMP, 1);
}
Step BubbleSort::getPrevStep(){
	vector<int> *v1 = new vector<int>();

	return Step(v1, Operation::COMP, 1);
} 