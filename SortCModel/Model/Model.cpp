// Model.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "BubbleSort.h"
#include "Step.h"
#include <iostream> 

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> values(2,5);
	vector<int>* v1 = &values;
	values.push_back(1);
	values.push_back(4);
	cout << values[2];

	Step *s1 = new Step(v1, Operation::COMP ,1);
	//BubbleSort *bs = new BubbleSort(values);
	getchar();
	return 0;	
}

