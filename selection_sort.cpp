#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {46,29,68,245,90,25,5,89,1,34};
    int mindex, temp;

    cout << "Original array: " ;
    for(int i = 0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    for(int i = 0; i<10; i++)
    {
        mindex = i;
        for(int j = i+1; j<10; j++)
        {
            if(arr[j] < arr[mindex])
            {
                mindex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[mindex];
        arr[mindex] = temp;
    }

    cout << "Sorted array: " ;
    for(int i = 0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
