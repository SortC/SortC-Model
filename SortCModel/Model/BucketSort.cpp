#include "BucketSort.h"
#include <iostream>


using namespace std;

BucketSort::BucketSort(int* values, int numbOfValues) : Algorithm(values,numbOfValues)
{
	buckets = new queue<int>[numbOfValues];
}

BucketSort::BucketSort(int numbOfValues) : Algorithm(numbOfValues)
{
	buckets = new queue<int>[numbOfValues];
}

BucketSort::~BucketSort(void)
{
	delete(buckets);
}

int BucketSort::hash(int n)
{
    return n/5;
}

void BucketSort::doinsertionsortforbucket(int* input, int len)
{
    while( len-- > 0) {
        if (input[len] > input[len+1]) {
            int tmp = input[len];
            input[len] = input[len+1];
            input[len+1] = tmp;
        } else
            return;
    }
}

void BucketSort::sort()
{
	steps.push_back(new Step(0,0, Operation::SWAP, ++numbOfSteps));
    //for ( int i = 0; i < numbOfValues; i++ )
    //    buckets[i] = new queue<int>;

    // Hash the input and insert the content into appropriate bucket based on hash.
    for (int i=0;i<numbOfValues;i++)
    {
        int hashValue = hash(currentTuple[i]);
        if (hashValue >= numbOfValues)
            hashValue = numbOfValues-1;

        buckets[hashValue].push(currentTuple[i]);
    }

    // extract the content from each of the buckets in order.
    // using insertion sort
    int outputidx = 0;
    for ( int i = 0; i < numbOfValues; i++ )
    {
        if (buckets[i].size() == 1) {
            currentTuple[outputidx++] = buckets[i].front();
            //cout << buckets[i]->front() << " | ";
            buckets[i].pop();
        }
        if (buckets[i].size() > 1)
        {
            while (!buckets[i].empty())
            {
                currentTuple[outputidx] = buckets[i].front();
                doinsertionsortforbucket(currentTuple, outputidx);
                //cout << buckets[i]->front() << " ";
                buckets[i].pop();
                outputidx++;
            }
            //cout << "| ";
        }
    }
    // clear buckets.
    /*for ( int i = 0; i < numbOfValues; i++ )
        delete buckets[i];
*/

}
