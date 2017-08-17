#include <iostream>

using namespace std;

void insertion_sort( unsigned *ptr, unsigned num )
{
    unsigned j, aux;
    for( int i=0; i<num; i++ )
    {
        j = i;
        while( j > 0 && ( ptr[j] < ptr[j-1] ))
        {
            aux = ptr[j];
            ptr[j] = ptr[j-1];
            ptr[j-1] = aux;
            j = j-1;
        }
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
    
    insertion_sort( arr, n );

    display_array( arr, n );
}