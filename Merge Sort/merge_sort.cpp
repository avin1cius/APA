#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

void merge( int *arr, int ini, int mid, int post )
{
    int *temp = new int [post-ini];
    int i = ini;
    int j = mid;
    int k = 0;

    while( i<mid && j<post )
    {
        if( arr[i]<=arr[j] )
        {
            temp[k]=arr[i]; k++; i++;
        }
        else
        {
            temp[k]=arr[j]; k++; j++;
        }
    }

    while( i<mid )
    {
        temp[k]=arr[i]; k++; i++;
    }

    while( j<post )
    {
        temp[k]=arr[j]; k++; j++;
    }

    for( i = ini; i<post; i++ )
    {
        arr[i]=temp[i-ini];
    }

}

void merge_sort( int *arr, int ini,  int post )
{
    if( ini<post-1 )
    {
        int mid = ( ini+post )/2;
        merge_sort( arr, ini, mid );
        merge_sort( arr, mid, post );
        merge( arr, ini, mid, post );
    }
}

void display_array( int *arr, int l )
{
    for( int i=0; i<l; i++ )
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
    
    merge_sort( arr, 0, n );

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
