// Model.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "BubbleSort.h"
#include "Step.h"
#include <iostream>

#include <ctime>

using namespace std;
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
	
    
    bs.ausgabe();

	//Step testStep(1,5, Operation::COMP, 5);

	//cout << testStep.toString();
	
	Step* currStep = bs.getNextStep(); 
	int i = 1;
	do{
		if(currStep->getOperation() == Operation::SWAP){
			cout <<currStep->getNumber() << ".Schritt: --> " << currStep->toString();
			cout << endl;
			i++;
		}
		currStep = bs.getNextStep();
	}while(currStep != NULL);
	
	getchar();
	

	return 0;
}

