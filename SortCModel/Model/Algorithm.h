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
	Algorithm(int* values, int numberOfValues);

	/**
	 * Konstruktor für beliebige Zahlenfolge
	 * @param anzValues Anzahl zu sortierender Werte
	 */

	Algorithm(int numberOfValues);
	/**
	 * Destruktor
	 */
	
	~Algorithm(void);
	
	/** 
	 * Startet die Sortierung
	 */
	virtual void sort();

	/** 
	 * Gibt den nächsten Schritt aus der Sortierung
	 */
	virtual Step* getNextStep();

	/** 
	 * Gibt den vorherigen Schritt aus der Sortierung
	 */
	virtual Step* getPrevStep();

	int* get_startTupel();

	int* get_currentTupel();

protected:
	int* startTuple;
	int* currentTupel;
	vector<Step*> steps;
	int numberOfValues;
	int numbOfSteps;
	int numbOfcurrentStep;
};

