// Model.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "BubbleSort.h"
#include "Step.h"
#include <iostream>

#include <time.h>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	

clock_t init, final;

init=clock();

time_t timer;
time(&timer);
	//vector<int> values(2,5);
	//vector<int>* v1 = &values;
	//values.push_back(1);
	//values.push_back(4);
	//cout << values[2];

	//Step s1(v1, Operation::COMP, 1);
	//cout << "Unsortierte liste: " << endl;
	//for(int i = 0; i < values.size(); i++)
	//{
	//	cout<<values[i]<<endl;
	//}

	BubbleSort bs = (100);
	bs.sort();
	
time_t timer1;
time(&timer1);
cout <<"akjdsfadjkshfashlud"<< timer1 - timer << endl;
	bs.ausgabe();

	getchar();
	return 0;	
}

