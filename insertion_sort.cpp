#include <iostream>
using namespace std;

int main()
{
    int *s = nullptr;
    if(s == NULL)
        cout << "test 1" << endl;
    if(s == nullptr)
        cout << "test 2" << endl;
}