#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

inline int partition( int *arr, int ini, int post )
{
    int pivot = arr[post];
    int i = ini-1;

    for( int j = ini; j<post; j++ )
    {
        if( arr[j] <= pivot )
        {
            i++;
            swap( arr[i], arr[j] );
        }
    }

    swap( arr[i + 1], arr[post] );

    return (i + 1);
}

void quick_sort( int *arr, int ini, int post )
{
    if( ini<post )
    {
        int p = partition( arr, ini, post );
        quick_sort( arr, ini, p-1 );
        quick_sort( arr, p+1, post );
    }
}

void display_array( int *arr, int num )
{
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
    
    quick_sort( arr, 0, n-1 );

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
