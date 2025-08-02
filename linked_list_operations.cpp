#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LL
{
    private:
        Node *rear;
        Node *front;

    public:
        LL()
        {
            rear = front = NULL;
        }

        void end_insert(int in)
        {
            Node *newn = new Node();
            newn->data = in;
            newn->next = NULL;
            if (rear == NULL)
            {
                front = rear = newn;
                return;
            }
            rear->next = newn;
            rear = newn;
        }

        void front_insert(int in)
        {
            Node *newn = new Node();
            newn->data = in;
            newn->next = front;
            front = newn;
        }

        void specfic_insert(int in)
        {
            int index,count=0;
            cout << "Enter index to insert at" << endl;
            Node *newn = new Node();
            Node *temp = front;
            while(temp!=NULL)
            {
                if(index == count)
                {
                    newn->next = temp-> next;
                    newn->data = in;
                    temp->next = newn;
                }
                temp = temp->next;
                count++;
            }
        }

        void display()
        {
            Node *temp = front;
            while(temp!=NULL)
            {
                cout << temp-> data << " " ;
                temp = temp->next;
            }
        }
};

int main()
{
    LL list;
    list.end_insert(1);
    list.end_insert(2);
    list.end_insert(3);
    list.end_insert(4);
    list.display();
}