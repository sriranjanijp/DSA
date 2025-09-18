#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[mid + 1 + i];

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
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int len = sizeof(arr) / sizeof(int);
    cout << "Original array:\n";
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;

    mergeSort(arr, 0, len - 1);

    cout << "Sorted array:\n";
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
