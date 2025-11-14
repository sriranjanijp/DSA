#include <iostream>
using namespace std;

int partition (int arr[], int low, int high){
    int p = high;
    int i = low-1;

    for(int j = low; j < high ; j++){
        if(arr[j]<arr[p]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[p],arr[i+1]);
    return i+1;
}

void quicksort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr,low,high);

        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main() 
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(int);
    cout << "Original array:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    quicksort(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}