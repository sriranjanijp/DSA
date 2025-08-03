#include <iostream>
using namespace std;

class Arr
{
    private:
        int arr[100] = {};
        int size = 0;
    
    public:
        void insert(int in, int index)
        {
            for(int i = size; i>=index;i--)
            {
                arr[i+1] = arr[i];
            }
            arr[index] = in;
            size++;
        }

        void delete_ele(int index)
        {
            for(int i = index; i<size;i++)
            {
                arr[i] = arr[i+1];
            }
            size--;
        }

        void display()
        {
            for(int i =  0;i<size;i++)
            {
                cout << arr[i] << " ";
            }
            cout<<endl;
        }
};

int main()
{
    Arr arr1;
    arr1.insert(5,0);
    arr1.insert(5,1);
    arr1.insert(5,2);
    arr1.display();
    arr1.insert(6,1);
    arr1.display();
    arr1.delete_ele(1);
    arr1.display();
}