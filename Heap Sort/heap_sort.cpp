#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void heapify( int *arr, int size, int i )
{
    int greater = i;
    int left = 2*i+1;
    int right = 2*i+2;

    if( left<size && arr[left]>arr[greater] )
        greater = left;

    if( right<size && arr[right]>arr[greater] )
        greater = right;

    if( greater!=i )
    {
        swap( arr[i], arr[greater] );

        heapify( arr, size, greater);
    }

}

void heap_sort( int *arr, int n )
{
    for( int i=n/2-1; i>=0; i-- )
        heapify( arr, n, i );

    for( int i=n-1; i>=0; i-- )
    {
        swap( arr[0], arr[i] );

        heapify( arr, i, 0 );
    }
}

void display_array( int *arr, int num )
{
    cout << endl;
    for( int i=0; i<num; i++ )
    {
        cout << arr[i]<<" ";
    }
    cout << endl;
}

int main()
{
    int n, *arr;
    
    string filename;
    
    cout << "Digite o nome do arquivo: ";
    cin >> filename;
    
    ifstream ifs( filename );
    
    if ( ifs.is_open() )
    {
        ifs >> n;
        arr = new int [n];
    
        for ( int i = 0; i < n; i++ )
        {
            ifs >> arr[i];
        }
    
        ifs.close();
    }
    else
    {
        cout << "Arquivo de entrada não encontrado" << endl;
        return 0;
    }
        
    const clock_t begin_time = clock();
        
    heap_sort( arr, n );
    
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
        ofs << arr[i] << endl;
    }
    
    ofs.close();

    cout << "Verificar resultado em output.txt" << endl;

    return 0;
}
