#include <iostream>
using namespace std;

void merge(int arr[], int p, int mid, int r)
{
    int nl = mid-p+1;
    int nr = r-mid;
    int left[nl], right[nr];
    for(int i = 0; i<nl; i++)
    {
        left[i] = arr[p+i];
    }
    for(int i = 0; i<nr; i++)
    {
        right[i] = arr[mid+1+i];
    }

    int i = 0;
    int j = 0;
    int k = p;
    while(i<nl && j<nr)
    {
        if(left[i]<=right[j]){
            arr[k] = left[i];
            k++;
            i++;
        }
        else{
            arr[k] = right[j];
            k++;
            j++;
        }
    }
    while(i<nl){
        arr[k++] = left[i++];
    }
    while(j<nr){
        arr[k++] = right[j++];
    }
    
}

void mergesort(int arr[], int p, int r)
{
    if(p>=r)
        return;
    int mid = (p+r)/2;
    mergesort(arr,p,mid);
    mergesort(arr,mid+1,r);
    merge(arr, p,mid,r);
}

int main()
{
    int arr[] = {10,9,8,7,6,5,4,3,2,1};
    mergesort(arr,0,9);
    for(int i = 0; i<10; i++)
    {
        cout << arr[i] << " " ;
    }
    cout << endl;
    return 0;
}