// Model.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BucketSort.h"
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



void printStepLine(int num, string operation, string explanation)
{
	cout << "[" <<num << "] \t " << operation << "\t " << explanation;
}

void printBuckets(queue<int> *buckets, int numbOfValues)
{
	cout << "print Buckets" << endl;
	cout << "| ";
	for ( int i = 0; i < numbOfValues; i++ )
	{
		if (buckets[i].size() == 0){
			cout << " | ";
		}
		if (buckets[i].size() == 1) 
		{
			//cout << "A" << endl;
			cout << buckets[i].front() << " | ";
			buckets[i].pop();
		}
		if (buckets[i].size() > 1)
		{
			//cout << "B" << endl;
			while (!buckets[i].empty())
			{
				cout << buckets[i].front() << " ";
				buckets[i].pop();
			}
			cout << "| ";
		}
	}
}

/**
* Testet einen Algorithmus
* @param algo Algorithmus
* @param isBackwardSorted gibt an, ob die Zahlen umgekehrt sortiert sein sollen
*/
void testAlgorithm(Algorithm* algo) {
	cout << setw(LINEWIDTH) << setfill(FILLCHAR) << "" <<  endl;
	cout << typeid(*algo).name() << endl << endl;

	clock_t begin = clock();

	algo->doSort();

	clock_t end = clock();

	cout << "Ausgangswerte: \t" ;
	int *startTuple = algo->getStartTuple();
	for (int i = 0; i < algo->getNumbOfValues(); i++)
	{
		cout << " | " << startTuple[i];
	}
	cout << " |" << endl;

	BucketSort* buck = static_cast <BucketSort*> (algo);

	printBuckets(buck->getFilledBuckets(), buck->getNumbOfValues());

	cout << "\nEndwerte: \t" ;
	int *endTupel = algo->getCurrentTuple();
	for (int i = 0; i < algo->getNumbOfValues(); i++)
	{
		cout << " | " << endTupel[i];
	}

	cout << " |" << endl << endl;

	double elapsed_secs = double(end - begin) ;
	cout <<"Passed time: "<< elapsed_secs << " milliseconds" << endl<< endl;

	// Ausgabe der Schritte
	Step* currStep = algo->getNextStep(); 
	cout << "No.\t Oper. \t Explanation" << endl;
	int counter[7];
	for(int i = 0; i < 7; i++){
		counter[i] = 0;
	}
	do{
		switch (currStep->getOperation())
		{
		case SWAP:
			{
				printStepLine(currStep->getNumber(), "SWAP" ,currStep->toString());
				counter[SWAP]++;
				break;
			}
		case COMP:
			{
				printStepLine(currStep->getNumber(), "COMP" ,currStep->toString());
				counter[COMP]++;
				break;
			}
		case MARK:
			{
				printStepLine(currStep->getNumber(), "MARK" ,currStep->toString());
				counter[MARK]++;
				break;
			}
		case PIVOT:
			{
				printStepLine(currStep->getNumber(), "PIVOT" ,currStep->toString());
				counter[PIVOT]++;
				break;
			}
		case CPY:
			{
				printStepLine(currStep->getNumber(), "CPY" ,currStep->toString());
				counter[CPY]++;
				break;
			}
		case R_CPY: 
			{
				printStepLine(currStep->getNumber(), "R_CPY" ,currStep->toString());
				counter[R_CPY]++;
				break;
			}
		case MIN:
			{
				printStepLine(currStep->getNumber(), "MIN", currStep->toString());
				counter[MIN]++;
				break;
			}
		default:
			break;
		}
		currStep = algo->getNextStep();
	}while(currStep != NULL);

	cout << "\nBenoetigte Schritte: " << algo->getNumbOfSteps()<<endl;
	cout << "Nach Typ: " << endl;
	cout << "MARK:\t" << counter[MARK] << endl;
	cout << "COMP:\t" << counter[COMP] << endl;
	cout << "SWAP:\t" << counter[SWAP] << endl;
	cout << "PIVOT:\t" << counter[PIVOT] << endl;
	cout << "CPY:\t" << counter[CPY] << endl;
	cout << "R_CPY:\t" << counter[R_CPY] << endl;
	cout << "MIN:\t" << counter[MIN] << endl;
	cout << setw(LINEWIDTH) << setfill(FILLCHAR) << "" <<  endl << endl<< endl;
	delete algo;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Testreihe mit " << ANZWERTE << " Werten" << endl;
	cout << setw(LINEWIDTH) << setfill(FILLCHAR) << endl;

	// Test des BubbleSort
	//testAlgorithm(new BubbleSort(ANZWERTE));
	int zahlen[ANZWERTE];

	for (int i = 0 ; i<ANZWERTE;i++){
		zahlen[i] = ANZWERTE - i;
	}
	zahlen[3]= zahlen[1];

	//testAlgorithm(new MergeSort(zahlen,ANZWERTE));
	//testAlgorithm(new QuickSort(zahlen,ANZWERTE));
	//testAlgorithm(new SelectionSort(zahlen,ANZWERTE));
	//testAlgorithm(new InsertionSort(zahlen,ANZWERTE));
	//testAlgorithm(new BubbleSort(zahlen,ANZWERTE));
	testAlgorithm(new BucketSort(ANZWERTE));//zahlen,ANZWERTE));
	getchar();
	return 0;
}