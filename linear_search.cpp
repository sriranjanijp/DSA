#include <iostream>
using namespace std;

int main()
{
    int arr[10] = {2,5,8,9,56,45,3,2,7,30};
    int find;
    cout << "Enter element to search" << endl;
    cin >> find;
    for(int i = 0; i<10; i++)
    {
        if(arr[i] == find)
        {
            cout << "Element found at index: " << i << endl;
            return 0;
        }
    }
    cout << "Element not found" << endl;
    return 0;
}

