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
	Algorithm(vector<int> startTuple);

	/**
	 * Konstruktor für beliebige Zahlenfolge
	 * @param anzValues Anzahl zu sortierender Werte
	 */

	Algorithm(int anzValues);
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
	virtual Step getNextStep();

	/** 
	 * Gibt den vorherigen Schritt aus der Sortierung
	 */
	virtual Step getPrevStep();

private:
	vector<int> startTuple;
	vector<Step> steps;
	int numbOfSteps;
	int numbOfactualStep;
};

