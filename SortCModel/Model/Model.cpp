// Model.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "BubbleSort.h"
#include "MergeSort.h"
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



/**
 * Testet einen Algorithmus
 * @param algo Algorithmus
 * @param isBackwardSorted gibt an, ob die Zahlen umgekehrt sortiert sein sollen
 */
void testAlgorithm(Algorithm* algo) {
	cout << setw(LINEWIDTH) << setfill(FILLCHAR) << "" <<  endl;
	cout << typeid(*algo).name() << endl << endl;
	cout << "Ausgangswerte: " ;
	int *startTuple = algo->getCurrentTupel();
	for (int i = 0; i < algo->getNumbOfValues(); i++)
	{
		cout << " | " << startTuple[i];
	}
	cout << " |" << endl;
	/* clock_t begin = clock(); */
	
	algo->sort();

	/*clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC / 1000;
	cout <<"Passed time: "<< elapsed_secs << " milliseconds" << endl<< endl;*/

	// Ausgabe der Schritte
	Step* currStep = algo->getNextStep(); 
	cout << "No.\t Explanation" << endl;
	int swap = 0;
	int comp = 0;
	int mark = 0;
	do{
		switch (currStep->getOperation())
		{
		case SWAP: {
			cout << "[" <<currStep->getNumber() << "] \t " << currStep->toString();
			swap++;
			break;
			}
		case COMP:{
			cout << "[" <<currStep->getNumber() << "] \t " << currStep->toString();
			comp++;
			break;
			}
		case MARK:{
			cout << "[" <<currStep->getNumber() << "] \t " << currStep->toString();
			mark++;
			break;
			}
		default:
			break;
		}
		currStep = algo->getNextStep();
	}while(currStep != NULL);

	cout << "Endwerte: " ;
	int *endTupel = algo->getCurrentTupel();
	for (int i = 0; i < algo->getNumbOfValues(); i++)
	{
		cout << " | " << endTupel[i];
	}

	cout << " |" << endl;
	cout << "\nBenoetigte Schritte: " << algo->getNumbOfSteps()<<endl;
	cout << "Nach Typ: " << endl;
	cout << "MARK:\t" << mark << endl;
	cout << "COMP:\t" << comp << endl;
	cout << "SWAP:\t" << swap << endl;
	cout << setw(LINEWIDTH) << setfill(FILLCHAR) << "" <<  endl << endl<< endl;
	delete algo;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Testreihe mit " << ANZWERTE << " Werten" << endl;
	cout << setw(LINEWIDTH) << setfill(FILLCHAR) << endl;

	// Test des BubbleSort
	testAlgorithm(new BubbleSort(ANZWERTE));
	testAlgorithm(new MergeSort(ANZWERTE));
	getchar();
	return 0;
}


