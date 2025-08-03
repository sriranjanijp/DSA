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
            cout<<"Inserted at end" << endl;
        }

        void front_insert(int in)
        {
            Node *newn = new Node();
            newn->data = in;
            newn->next = front;
            front = newn;
            cout<<"Inserted at start" << endl;
        }

        void specfic_insert(int in)
        {
            int index,count=0;
            cout << "Enter index to insert at" << endl;
            cin >> index;
            Node *newn = new Node();
            Node *temp = front;
            --index;
            while(temp!=NULL)
            {
                if(index == count)
                {
                    newn->next = temp-> next;
                    newn->data = in;
                    temp->next = newn;
                    cout<<"Inserted at " <<index<< endl;
                    return;
                }
                temp = temp->next;
                count++;
            }
            cout<< "Index out of bounds" << endl;
        }

        void end_delete()
        {
            Node *current = front->next;
            Node *prev = front;
            while(current!=NULL)
            {
                if(current==rear)
                {
                    prev->next = NULL;
                    rear = prev;
                }
                prev = current;
                current = current->next;
            }
            cout<<"Deleted at end" << endl;
        }

        void front_delete()
        {
            Node *temp = front;
            front = front->next;
            delete temp;
            cout<<"Deleted at front" << endl;
        }

        void specfic_delete()
        {
            int index,count=0;
            cout << "Enter index to delete at" << endl;
            cin >> index;
            Node *prev = front;
            Node *current = front->next;
            --index;
            while(current!=NULL)
            {
                if(index == count)
                {
                    prev->next = current->next;
                    delete current;
                    cout<<"Deleted at " << index << endl;
                    return;
                }
                prev = current;
                current = current->next;
                count++;
            }
            cout<< "Index out of bounds" << endl;
        }

        void display()
        {
            Node *temp = front;
            while(temp!=NULL)
            {
                cout << temp-> data << " " ;
                temp = temp->next;
            }
            cout<<endl;
        }
};

int main()
{
    LL list;
    list.end_insert(1);
    list.end_insert(2);
    list.end_insert(3);
    list.end_insert(4);
    list.front_insert(0);
    list.display();
    list.specfic_insert(5);
    list.display();
    list.specfic_delete();
    list.display();
    list.end_delete();
    list.display();
    list.front_delete();
    list.display();
}