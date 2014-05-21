// Model.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

#include "stdafx.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
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



void printStepLine(int num, string operation, string explanation){
	cout << "[" <<num << "] \t " << operation << "\t " << explanation;
}

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
	clock_t begin = clock();
	
	algo->sort();

	clock_t end = clock();
	double elapsed_secs = double(end - begin) ;
	cout <<"Passed time: "<< elapsed_secs << " milliseconds" << endl<< endl;

	// Ausgabe der Schritte
	Step* currStep = algo->getNextStep(); 
	cout << "No.\t Oper. \t Explanation" << endl;
	int counter[6];
	for(int i = 0; i < 6; i++){
		counter[i] = 0;
	}
	do{
		switch (currStep->getOperation())
		{
		case SWAP: {
			printStepLine(currStep->getNumber(), "SWAP" ,currStep->toString());
			counter[SWAP]++;
			break;
			}
		case COMP:{
			printStepLine(currStep->getNumber(), "COMP" ,currStep->toString());
			counter[COMP]++;
			break;
			}
		case MARK:{
			printStepLine(currStep->getNumber(), "MARK" ,currStep->toString());
			counter[MARK]++;
			break;
			}
		case PIVOT:{
			printStepLine(currStep->getNumber(), "PIVOT" ,currStep->toString());
			counter[PIVOT]++;
			break;
			}
		case CPY:{
			printStepLine(currStep->getNumber(), "CPY" ,currStep->toString());
			counter[CPY]++;
			break;
			}
		case R_CPY: {
			printStepLine(currStep->getNumber(), "R_CPY" ,currStep->toString());
			counter[R_CPY]++;
			break;
			}
		default:
			break;
		}
		currStep = algo->getNextStep();
	}while(currStep != NULL);

	cout << "\nEndwerte: " ;
	int *endTupel = algo->getCurrentTupel();
	for (int i = 0; i < algo->getNumbOfValues(); i++)
	{
		cout << " | " << endTupel[i];
	}

	cout << " |" << endl;
	cout << "\nBenoetigte Schritte: " << algo->getNumbOfSteps()<<endl;
	cout << "Nach Typ: " << endl;
	cout << "MARK:\t" << counter[MARK] << endl;
	cout << "COMP:\t" << counter[COMP] << endl;
	cout << "SWAP:\t" << counter[SWAP] << endl;
	cout << "PIVOT:\t" << counter[PIVOT] << endl;
	cout << "CPY:\t" << counter[CPY] << endl;
	cout << "R_CPY:\t" << counter[R_CPY] << endl;
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
	testAlgorithm(new QuickSort(ANZWERTE));
	getchar();
	return 0;
}


