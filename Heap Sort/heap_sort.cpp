#include <iostream>

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
    int length, *arr;
    
    cout << "Digite o tamanho do array: ";
    cin >> length;

    arr = new int [length];

    cout << "Digite os elementos do array separados por espaço" << endl;

    for( int i=0; i<length; i++ )
    {
        cin >> arr[i];
    }
    
    heap_sort( arr, length );

    display_array( arr, length );
}