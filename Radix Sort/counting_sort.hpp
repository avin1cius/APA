#ifndef COUNTING_SORT_H_
#define COUNTING_SORT_H_

#include <vector>
#include <algorithm>

using namespace std;

void counting_sort( vector<int> &A, int size, int k )
{
    int i;
    vector<int> B( size );
    vector<int> C( 10 , 0 );

    for ( i = 0; i < size; i++ )
    {
        C[ (A[i]/k)%10 ] = C[ (A[i]/k)%10 ] + 1; //Qnts vezes cada elemento aparece em A
    }

    for ( i = 1; i < 10; i++ )
    {
        C[i] = C[i] + C[i-1]; //Numero de elementos menores 
    }

    for ( i = size - 1; i >= 0; i-- )
    {
        B[C[ (A[i]/k)%10 ]-1] = A[i];
        C[ (A[i]/k)%10 ] = C[ (A[i]/k)%10 ] - 1;
    }

    for (i = 0; i < size; i++)
    {
        A[i] = B[i];
    }
}

#endif // COUNTING_SORT_H_ 