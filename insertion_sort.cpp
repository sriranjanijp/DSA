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
