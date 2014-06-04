// Model.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "BucketSort.h"
#include "HeapSort.h"
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

	//BucketSort* buck = static_cast <BucketSort*> (algo);

	//printBuckets(buck->getFilledBuckets(), buck->getNumbOfValues());

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
	cout <<left<< setfill(' ') <<setw(7) << "No." << setw(7)<< "Oper." << "Explanation" << endl;
	int counter[7];
	for(int i = 0; i < 7; i++){
		counter[i] = 0;
	}
	do{
		cout << currStep->toString();
		switch (currStep->getOperation())
		{
		case SWAP:
			{
				counter[SWAP]++;
				break;
			}
		case COMP:
			{
				counter[COMP]++;
				break;
			}
		case MARK:
			{
				counter[MARK]++;
				break;
			}
		case PIVOT:
			{
				counter[PIVOT]++;
				break;
			}
		case CPY:
			{
				counter[CPY]++;
				break;
			}
		case R_CPY: 
			{
				counter[R_CPY]++;
				break;
			}
		case MIN:
			{
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
	const int width = 50;
	cout << setw(width) << setfill('#') << "" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#  Beginne Testreihe 1" << "#" << endl;
	cout << "#" << setw(width -1) << setfill(' ') << right << "#" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#  Testfaelle:" << "#" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#  1. Klasse: Algorithm" << "#" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#    a. Konstruktor mit vord. Tupel" << "#" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#    b. getNextStep() - Methode" << "#" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#  2. Klasse: Erben von Algorithm" << "#" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#    a. sort() - Methode" << "#" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#    b. Sortierung doppelter Werte" << "#" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#  3. Klasse: Step" << "#" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#    a. toString() - Methode" << "#" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#    b. Konstruktoren" << "#" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#    c. Attribute" << "#" << endl;
	cout << "#" << setw(width -1) << setfill(' ') << right << "#" << endl;
	cout << setw(width) << setfill('#')<<"" << endl;
	cout << "\nBitte beliebige Taste druecken zum fortfahren" << endl;
	getchar();
	testAlgorithm(new MergeSort(zahlen,ANZWERTE));
	testAlgorithm(new QuickSort(zahlen,ANZWERTE));
	cout << "\nBitte beliebige Taste druecken zum fortfahren" << endl;
	getchar();
	testAlgorithm(new SelectionSort(zahlen,ANZWERTE));
	testAlgorithm(new InsertionSort(zahlen,ANZWERTE));
	cout << "\nBitte beliebige Taste druecken zum fortfahren" << endl;
	getchar();
	testAlgorithm(new BubbleSort(zahlen,ANZWERTE));
	testAlgorithm(new BucketSort(zahlen,ANZWERTE));
	cout << "\nBitte beliebige Taste druecken zum fortfahren" << endl;
	getchar();
	testAlgorithm(new HeapSort(zahlen, ANZWERTE));
	
	
	cout << setw(width) << setfill('#') << "" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#  Ende von Testreihe 1" << "#" << endl;
	cout << setw(width) << setfill('#') << "" << endl;
	cout << "\nBitte beliebige Taste druecken zum fortfahren" << endl;
	getchar();
	cout << setw(width) << setfill('#') << "" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#  Beginne Testreihe 2" << "#" << endl;
	cout << "#" << setw(width -1) << setfill(' ') << right << "#" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#  Testfaelle:" << "#" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#  1. Klasse: Algorithm" << "#" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#    a. Konstruktor mit Zufallswerten" << "#" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#  2. Klasse: Erben von Algorithm (WIE ZUVOR)" << "#" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#  3. Klasse: Step (WIE ZUVOR)" << "#" << endl;
	cout << "#" << setw(width -1) << setfill(' ') << right << "#" << endl;
	cout << setw(width) << setfill('#')<<"" << endl;
		cout << "\nBitte beliebige Taste druecken zum fortfahren" << endl;
	getchar();
	testAlgorithm(new MergeSort(ANZWERTE));
	testAlgorithm(new QuickSort(ANZWERTE));
	cout << "\nBitte beliebige Taste druecken zum fortfahren" << endl;
	getchar();
	testAlgorithm(new SelectionSort(ANZWERTE));
	testAlgorithm(new InsertionSort(ANZWERTE));
	cout << "\nBitte beliebige Taste druecken zum fortfahren" << endl;
	getchar();
	testAlgorithm(new BubbleSort(ANZWERTE));
	testAlgorithm(new BucketSort(ANZWERTE));
	cout << "\nBitte beliebige Taste druecken zum fortfahren" << endl;
	getchar();
	testAlgorithm(new HeapSort(ANZWERTE));
	
		cout << setw(width) << setfill('#') << "" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#  Ende von Testreihe 2" << "#" << endl;
	cout << setw(width) << setfill('#') << "" <<"\n" << endl;

	cout << setw(width) << setfill('#') << "" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#  Alle Tests abgeschlossen" << "#" << endl;
	cout << "#" << setw(width -1) << setfill(' ') << right << "#" << endl;
	cout << left <<setfill(' ') << setw(width-1) <<"#  E N D E" << "#" << endl;
	cout << setw(width) << setfill('#') << "" << endl;

	getchar();
	return 0;
}