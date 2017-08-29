#include <iostream>

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
    int length, *arr;
    
    cout << "Digite o tamanho do array: ";
    cin >> length;

    arr = new int [length];

    cout << "Digite os elementos do array separados por espaço" << endl;

    for( int i=0; i<length; i++ )
    {
        cin >> arr[i];
    }
    
    merge_sort( arr, 0, length );

    display_array( arr, length );
}
