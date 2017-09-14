#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

void counting_sort( vector<int> &A, int size, int k )
{
    int i;
    vector<int> B( size );
    vector<int> C( k+1 , 0 );    

    for ( i = 0; i < size; i++ )
    {
        C[A[i]] = C[A[i]] + 1; //Qnts vezes cada elemento aparece em A
    }

    for ( i = 2; i <= k; i++ )
    {
        C[i] = C[i] + C[i-1]; //Numero de elementos menores 
    }

    for ( i = size - 1; i >= 0; i-- )
    {
        B[C[A[i]]-1] = A[i];
        C[A[i]] = C[A[i]] - 1;
    }        
}

int main()
{    
    string filename;
    vector<int> A;
    int n;

    cout << "Digite o nome do arquivo: ";
    cin >> filename;

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

    int max = *max_element( A.begin(), A.end() );    
    
    const clock_t begin_time = clock();

    counting_sort( A, n, max);

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
