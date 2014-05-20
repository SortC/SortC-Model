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
    int zahlen [100];
    for(int i = 0; i < 100; i++){
        zahlen[i] = 100-i;
    }
    BubbleSort bs(zahlen,100);

    clock_t begin = clock();
	
    bs.sort();
	
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout <<"Passed time: "<< elapsed_secs << " seconds" << endl;
	
    
    bs.ausgabe();

	int testZahlen [2] = {1,3};
	Step testStep(testZahlen, Operation::COMP, 5);

	cout << testStep.toString();

	getchar();
	return 0;	
}

