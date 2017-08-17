#include <iostream>

using namespace std;

void selection_sort( unsigned *ptr, unsigned num )
{
    unsigned i, j, aux1, aux2;
    for( i=0; i<num; i++ )
    {
        aux1 = i;
        for( j = i+1; j<num; j++ )
        {
            if( ptr[j] < ptr[aux1] )
                aux1 = j;
        }
        aux2 = ptr[i];
        ptr[i] = ptr[aux1];
        ptr[aux1] = aux2;
    }
}

void display_array( unsigned *ptr, unsigned num )
{
    for( int i=0; i<num; i++ )
    {
        cout << ptr[i]<<" ";
    }
    cout << endl;
}

int main()
{
    unsigned n, option, *arr;
    
    cout << "Digite o tamanho do array: ";
    cin >> n;

    arr = new unsigned [n];

    cout << "Digite os elementos do array separados por espaço" << endl;

    for( int i=0; i<n; i++ )
    {
        cin >> arr[i];
    }
    
    selection_sort( arr, n );

    display_array( arr, n );
}