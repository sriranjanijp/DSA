#include <iostream>
using namespace std;

class ArrStack
{
	private:
		int top;
		int arr[100];

	public:
		ArrStack()
		{
			top = -1;
		}

		void push (int x)
		{
			if (top>=99)
			{
				cout<<"Stack Overflow error"<<endl;
			}
			else
			{
				arr[++top] = x;
				cout << "Pushed" << endl;
			}
		}

		void pop()
		{
			if (top<0)
			{
				cout << "Stack Underflow error" << endl;
			}
			else
			{
				top--;
				cout << "Popped" << endl;
			}
		}

		void peep()
		{
			cout << arr[top] << endl;
		}

		void display()
		{
			int temp = top;
			while (temp>=0)
			{
				cout << arr[temp--] << " ";
			}
			if (top < 0)
			{
				cout << "Stack empty" << endl;
			}
			cout << endl;
		}
};

struct Node
{
	int data;
	Node *next;
};

class LLStack
{
	private:
		Node * top;

	public:
	LLStack()
	{
		top = NULL;
	}

	void push(int c)
	{
	Node *newnode = new Node();
	newnode->data = c;
	newnode->next = top;
	top = newnode;
	}
	void pop()
	{
	if(top == NULL)
	{
		cout << "Stack Underflow" << endl;
	}
	else{
		cout << "Popped: " << top->data << endl;
		top = top-> next;
	} 
	}

	void display()
	{
	Node *t = top;
	while (t != NULL)
	{
		cout << t->data << " ";
		t = t->next;
	}
	if (top == NULL)
	{
		cout << "Stack empty" << endl;
	}
	cout << endl;
	}
	void peep()
	{
		cout << top-> data << endl;
	}
};

int main()
{
	ArrStack s1;
	LLStack s2;
	int c = 0,in;
	while(c != 5)
	{
		cout<<"1. Push"<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"3. Peep"<<endl;
		cout<<"4. Display"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"Enter operation to perform: ";
		cin >> c;

		switch(c)
		{
			case 1:
			{
				cout << "Input number to push: " ;
				cin >> in;
				s1.push(in);
				s2.push(in);
				break;
			}

			case 2:
			{
				s1.pop();
				s2.pop();
				break;
			}

			case 3:
			{
				s1.peep();
				s2.peep();
				break;
			}

			case 4:
			{
				s1.display();
				s2.display();
				break;
			}
			case 5:
			{
				break;
			}

			default:
			{
				cout << "Wrong choice, try again" << endl;
			}
		}
	}
}


