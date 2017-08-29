#include <iostream>

using namespace std;

inline void swap( int *a, int *b )
{            
    int temp = *a;
    *a = *b;
    *b = temp;
}

inline int partition( int *arr, int ini, int post )
{
    int pivot = arr[post];
    int i = ini-1;

    for( int j = ini; j<post; j++ )
    {
        if( arr[j] <= pivot )
        {
            i++;
            swap( &arr[i], &arr[j] );
        }
    }

    swap( &arr[i + 1], &arr[post] );

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
    int length, *arr;
    
    cout << "Digite o tamanho do array: ";
    cin >> length;

    arr = new int [length];

    cout << "Digite os elementos do array separados por espaço" << endl;

    for( int i=0; i<length; i++ )
    {
        cin >> arr[i];
    }
    
    quick_sort( arr, 0, length-1 );

    display_array( arr, length );
}
