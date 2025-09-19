#include <iostream>
using namespace std;

//using array
class arrqueue
{
    private:
        int arr[100];
        int index;
    public:
        arrqueue()
        {
            index = 0;
        }
        void push(int in)
        {
            if (index>0 && index<99)
            {
                for(int i = index; i>=0; i--)
                {
                    arr[i+1] = arr[i];
                }
            }
            if(index>=99)
            {
                cout << "Queue overload" << endl;
                return;
            }
            else
            {
                arr[0] = in;
                index++;
            }
        }
        void pop()
        {
            if(index>0)
            {
                index--;
                cout << "Popped" << endl;
            }
            else
                cout << "Queue empty" << endl;
        }



        void display()
        {
            for(int i = 0;i<index;i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

class arrcirc
{
    private:
        int arr[100];
        int capacity, size, front;
    public:
        arrcirc()
        {
            capacity = 100;
            size = 0;
            front = 0;
        }
        void push(int in)
        {
            if(size == capacity)
                return;
            int rear = (front+size)%capacity;
            arr[rear] = in;
            size++;
        }
        void pop()
        {
            if(size==0)
                return;
            cout << "Popped " << arr[front] << endl;
            front = (front+1)%capacity;
            size--;
        }
        void display()
        {
            for(int i = front;i<size;i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};




struct Node
{
    int data;
    Node *next;
};

class llqueue
{
    private:
        Node *front, *rear;
    public:
        llqueue()
        {
            front = rear = NULL;
        }
        void push(int in)
        {
            Node *newn = new Node();
            newn->data = in;
            if(front==NULL)
            {
                front = rear = newn;
                newn->next = NULL;
                return;
            }
            rear->next = newn;
            rear = newn;
        }
        void pop()
        {
            if(front==NULL)
            {
                rear = NULL;
                cout << "Queue empty" << endl;
                return;
            }
            Node *temp = front;
            front = front -> next;
            delete temp;
        }
        void display()
        {
            if(front==NULL)
            {
                cout << "Queue empty" << endl;
                return;
            }
            Node *temp = front;
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main()
{
    cout << "Operations on linear queue using array "<<endl;
    arrqueue a;
    a.pop();
    for(int i= 1;i<100;i++)
    {
        a.push(i);
    }
    a.display();
    cout<<endl;

    cout << "Operations on circular queue using array "<<endl;
    arrcirc b;
    b.pop();
    for(int i= 1;i<11;i++)
    {
        b.push(i);
    }
    b.display();

    b.pop();
    b.pop();
    b.pop();
    b.display();
    cout<<endl;

    cout << "Operations on queue using linked-list "<<endl;
    llqueue p;
    p.push(1);
    p.push(2);
    p.push(3);
    p.display();

    p.pop();
    p.pop();
    p.display();
}
