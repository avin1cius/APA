#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void selection_sort( int *ptr, int num )
{
    int i, j, k, aux;
    for( i=0; i<num; i++ )
    {
        k = i;
        for( j = i+1; j<num; j++ )
        {
            if( ptr[j] < ptr[k] )
                k = j;
        }
        aux = ptr[i];
        ptr[i] = ptr[k];
        ptr[k] = aux;
    }
}

void display_array( int *ptr, int num )
{
    for( int i=0; i<num; i++ )
    {
        cout << ptr[i]<<" ";
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
    
    selection_sort( arr, n );

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
