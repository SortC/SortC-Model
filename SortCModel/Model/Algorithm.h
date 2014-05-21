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
	* Konstruktor für voreingestellte Zahlenfolgen
	* @param startTuple vordefiniertes Zahlentupel
	*/
	Algorithm(int* values, int numbOfValues);

	/**
	* Konstruktor für zufällige Zahlenfolge
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
	virtual void sort();

	/** 
	* Gibt Pointer auf den nächsten Schritt aus der Sortierung zurück
	* Gibt NULL zurück, fall kein nächster Schritt existiert
	*/
	Step* getNextStep();

	/** 
	* Gibt Pointer auf den vorherigen Schritt aus der Sortierung zurück
	* Gibt NULL zurück, fall kein vorheriger Schritt existiert
	*/
	Step* getPrevStep();

	/**
	* Getter-Funktionen
	*/
	int* getCurrentTupel(){ return currentTupel; };
	int* getStartTupel(){ return startTuple; };
	int getNumbOfCurrentStep(){ return numbOfCurrentStep; };
	int getNumbOfSteps(){ return numbOfSteps; };
	int getNumbOfValues(){ return numbOfValues; };

protected:
	int* startTuple;
	int* currentTupel;
	vector<Step*> steps;
	int numbOfValues;
	int numbOfSteps;
	int numbOfCurrentStep;
};

