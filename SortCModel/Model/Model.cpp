// Model.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "BubbleSort.h"
#include "Step.h"
#include <iostream>
#include <ctime>
#include <typeinfo>
#include <iomanip>
#include <random>


#define ANZWERTE 5
#define LINEWIDTH 40
const char FILLCHAR = '-';

using namespace std;

void testAlgorithm(Algorithm* algo, bool isBackwardSorted) {
	cout << setw(LINEWIDTH) << setfill(FILLCHAR) << "" <<  endl;
	cout << typeid(*algo).name() << endl << endl;
	cout << "Ausgangstupel: " ;

	int zahlen [ANZWERTE];
	if (isBackwardSorted)
	{
		for(int i = 0; i < ANZWERTE; i++){
			zahlen[i] = ANZWERTE-i;
			cout << " | "<< zahlen[i] ;
		}
	}
	else
	{
		srand(time(nullptr));
		for (int i = 0; i < ANZWERTE; i++)
		{
			zahlen[i] = rand() % 100;
			cout << " | "<< zahlen[i] ;
		}
	}
	cout << " |" << endl;


	/* clock_t begin = clock(); */
	algo->sort();

	/*clock_t end = clock();

	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC / 1000;
	cout <<"Passed time: "<< elapsed_secs << " milliseconds" << endl<< endl;*/

	Step* currStep = algo->getNextStep(); 
	cout << "No.\t Explanation" << endl; 
	do{
		if(currStep->getOperation() == Operation::SWAP){

			cout << "[" <<currStep->getNumber() << "] \t " << currStep->toString();
		}
		currStep = algo->getNextStep();
	}while(currStep != NULL);
	cout << setw(LINEWIDTH) << setfill(FILLCHAR) << "" <<  endl << endl<< endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Testreihe mit " << ANZWERTE << " Werten" << endl;
	cout << setw(LINEWIDTH) << setfill(FILLCHAR) << endl;
	testAlgorithm(new BubbleSort(ANZWERTE),true);
	testAlgorithm(new BubbleSort(ANZWERTE),false);

	getchar();
	return 0;
}


