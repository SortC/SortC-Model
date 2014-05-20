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
<<<<<<< HEAD

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
=======
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
>>>>>>> a945ea1283e2dfecce030d18713e76e39254e43b
		}
		currStep = algo->getNextStep();
	}while(currStep != NULL);
<<<<<<< HEAD
	cout << setw(LINEWIDTH) << setfill(FILLCHAR) << "" <<  endl << endl<< endl;
}
=======

	getchar();
>>>>>>> a945ea1283e2dfecce030d18713e76e39254e43b

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Testreihe mit " << ANZWERTE << " Werten" << endl;
	cout << setw(LINEWIDTH) << setfill(FILLCHAR) << endl;
	testAlgorithm(new BubbleSort(ANZWERTE),true);
	testAlgorithm(new BubbleSort(ANZWERTE),false);

	getchar();
	return 0;
}


