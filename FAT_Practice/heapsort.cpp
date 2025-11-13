#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left<n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest = right;
    }

    if(largest!= i){
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n){
    for(int i = n/2 - 1; i>=0; i--){
        heapify(arr,n,i);
    }

    for(int i = n - 1; i>=0; i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}

int main(){
    int arr[] = {3,2,5,4,1,0,9,8,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Array before sort: " ;
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    heapSort(arr,n);
    cout << "Array after sort: " ;
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}