// Model.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "BubbleSort.h"
#include "Step.h"
#include <iostream>

#include <ctime>

using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	int zahlen [5];
	for(int i = 0; i < 5; i++){
		zahlen[i] = 5-i;
	}
	BubbleSort bs(zahlen,5);

	clock_t begin = clock();

	bs.sort();

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout <<"Passed time: "<< elapsed_secs << " seconds" << endl;

	Step* currStep = bs.getNextStep(); 
	do{
		if(currStep->getOperation() == Operation::SWAP){
			cout <<currStep->getNumber() << ".Schritt: --> " << currStep->toString();
			cout << endl;
		}
		currStep = bs.getNextStep();
	}while(currStep != NULL);

	getchar();

	return 0;
}

