#pragma once

#include <string>
#include <vector>
#include <random>
#include "Step.h"

using namespace std;
class Algorithm
{
public:

	/**
	* Konstruktor f�r voreingestellte Zahlenfolgen
	* @param startTuple vordefiniertes Zahlentupel
	*/
	Algorithm(int* values, int numbOfValues);

	/**
	* Konstruktor f�r zuf�llige Zahlenfolge
	* @param anzValues Anzahl zu sortierender Werte
	*/
	Algorithm(int numbOfValues);

	/**
	* Destruktor
	*/
	~Algorithm();

	/** 
	* Startet die Sortierung
	*/
	void doSort();

	/** 
	* Gibt Pointer auf den n�chsten Schritt aus der Sortierung zur�ck
	* Gibt NULL zur�ck, fall kein n�chster Schritt existiert
	*/
	Step* getNextStep();

	/** 
	* Gibt Pointer auf den vorherigen Schritt aus der Sortierung zur�ck
	* Gibt NULL zur�ck, fall kein vorheriger Schritt existiert
	*/
	Step* getPrevStep();

	/**
	* Getter-Funktionen
	*/
	int* getCurrentTuple(){ return currentTuple; };
	int* getStartTuple(){ return startTuple; };
	int getNumbOfCurrentStep(){ return numbOfCurrentStep; };
	int getNumbOfSteps(){ return numbOfSteps; };
	int getNumbOfValues(){ return numbOfValues; };

protected:
	virtual void sort();
	int maxValue;
	bool isSorted;
	int* startTuple;
	int* currentTuple;
	vector<Step*> steps;
	int numbOfValues;
	int numbOfSteps;
	int numbOfCurrentStep;
};

