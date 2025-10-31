#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2,6,45,1,8,3,7,41,5,4};
    cout << "Unsorted Array: ";
    for(int i = 0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    //Insertion sort
    int temp,j,insert = 0;
    for(int i = 1; i<10; i++)
    {
        insert = -1;
        temp = arr[i];
        for(j = i; j>=0; j--)
        {
            if(arr[j]>arr[i])
                insert = j;
        }
        if(insert > -1)
        {
            for(j = i; j>insert; j--)
            {
                arr[j] = arr[j-1];
            }
            arr[insert] = temp;
        }
    }

    cout << "Sorted Array: ";
    for(int i = 0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

/*
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    
    // Start from the second element (index 1)
    for (int i = 1; i < n; i++) {
        
        // 1. Store the element we want to insert
        int temp = arr[i];
        
        // 2. Start checking elements to its left
        int j = i - 1;

        // 3. Find the spot AND shift elements at the same time
        //    Move elements of arr[0..i-1] that are greater than temp
        //    to one position ahead of their current position

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        
        // 4. We found the spot. 'j+1' is the correct position for 'temp'.
        arr[j + 1] = temp;
    }
}
*/