#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int p, int r)
{
    int x = arr[r];
    int i = p-1;
    for(int j = p; j<r; j++)
    {
        if(arr[j]<x)
        {
            i++;
            swap(&arr[j],&arr[i]);
        }
    }
    i++;
    swap(&arr[i],&arr[r]);
    return i;
}

void quicksort(int arr[], int p, int r)
{
    if(p<r)
    {
        int pivot = partition(arr,p,r);
        quicksort(arr,p,pivot-1);
        quicksort(arr,pivot+1,r);
    }
}

int main()
{
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    quicksort(arr,0,9);
    for(int i = 0; i<10; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
}