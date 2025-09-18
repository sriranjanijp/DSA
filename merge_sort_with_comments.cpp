#include <iostream>
using namespace std;

// Merge function to merge two sorted subarrays
void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1], right[n2];
    cout << "n1: " << n1 << " n2: " << n2 << endl;

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[mid + 1 + i];

    cout << "Left arr: " ;
    for (int i = 0; i < n1; i++)
        cout << left[i] << " ";
    cout << endl << "Right arr: " ;
    for (int i = 0; i < n2; i++)
        cout << right[i] << " ";
    cout << endl;

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    cout << "Inside merge array: ";
    for (int i = 0; i < 7; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Recursive Merge Sort function
void mergeSort(int arr[], int low, int high) {
    cout << "Low is: " << low << endl;
    cout << "High is: " << high << endl;
    if (low < high) {
        int mid = (low + high) / 2;
        cout << "Mid is: " << mid << endl;

        cout << "Called mergesort1 with " << low << " and " << mid << endl;
        mergeSort(arr, low, mid);

        cout << "Called mergesort2 with " << mid+1 << " and " << high << endl;
        mergeSort(arr, mid + 1, high);

        cout << "Called merge with " << low << " and " << mid << " and " << high << endl;
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(int);
    cout << "Original array:\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, size - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
