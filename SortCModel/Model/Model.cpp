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
	//cout << values[2];

	Step s1(v1, Operation::COMP, 1);
	//cout << "Unsortierte liste: " << endl;
	//for(int i = 0; i < values.size(); i++)
	//{
	//	cout<<values[i]<<endl;
	//}

	BubbleSort bs = (5);
	vector<int> value2 = bs.get_startTupel();
	bs.sort(value2);
	cout << "Sortierte liste: " << endl;

    for(int i = 0; i < value2.size(); i++)
	{
		cout<<value2[i]<<endl;
	}

	getchar();
	return 0;	
}

