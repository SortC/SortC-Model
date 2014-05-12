// Model.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "Algorithm.h"
#include "Step.h"
#include <iostream> 
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> values;
	values.push_back(1);
	values.push_back(4);
	values.push_back(21);
	cout << values[2];
	Algorithm a1(values);
	cin ;
	return 0;	
}

