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
    BubbleSort bs = (100);

    clock_t begin = clock();
	
    bs.sort();
	
    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout <<"Passed time: "<< elapsed_secs << " seconds" << endl;
	
    
    bs.ausgabe();

	getchar();
	return 0;	
}

