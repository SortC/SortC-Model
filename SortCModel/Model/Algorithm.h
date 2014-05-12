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
	Algorithm(vector<int> startTuple);

	/**
	 * Konstruktor f�r beliebige Zahlenfolge
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
	 * Gibt den n�chsten Schritt aus der Sortierung
	 */
	virtual Step getNextStep();

	/** 
	 * Gibt den vorherigen Schritt aus der Sortierung
	 */
	virtual Step getPrevStep();

	vector<int> get_startTupel();

	vector<int> get_currentTupel();

private:
	vector<int> startTuple;
	vector<int> currentTupel;
	vector<Step> steps;
	int numbOfSteps;
	int numbOfcurrentStep;
};

