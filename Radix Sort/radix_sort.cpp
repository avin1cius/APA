#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "counting_sort.hpp"

using namespace std;

void radix_sort( vector<int> &A, int n ) 
{
    int max = *max_element( A.begin(), A.end() );

    for ( int i = 1; (max / i) > 0; i *= 10 )
    {
        counting_sort( A, n, i );
    }
}

int main()
{
    int n;
    string filename;
    vector<int> A;

    ifstream ifs( filename );

    if ( ifs.is_open() )
    {
        ifs >> n;
        A.resize( n );

        for ( int i = 0; i < n; i++ )
        {
            ifs >> A[i];
        }

        ifs.close();
    }
    else
    {
        cout << "Arquivo de entrada não encontrado" << endl;
        return 0;
    }

    const clock_t begin_time = clock();

    radix_sort( A, n );

    double end_time = ( clock () - begin_time ) /  (double)CLOCKS_PER_SEC;
    cout << "Tempo necessário para ordenação: " << end_time * 1000 << "ms" << endl;

    ofstream ofs( "output.txt" );

    if ( !ofs.is_open() )
    {
        cout << "Erro ao criar o arquivo de saída" << endl;
        return 0;
    }

    for ( int i = 0; i < n; i++ )
    {
        ofs << A[i] << endl;
    }

    ofs.close();

    cout << "Verificar resultado em output.txt" << endl;

    return 0;
}
