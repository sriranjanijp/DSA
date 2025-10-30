#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Node{
    char data;
    Node* right;
    Node* left;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

void inOrder(Node* root) {
    if (root == nullptr) return;

    char arr = root->data;
    if(arr=='+' || arr=='-' || arr=='*' || arr=='/' || arr=='%'){
        cout<<'(';
    }

    inOrder(root->left);
    cout << root->data;
    inOrder(root->right);

    if(arr=='+' || arr=='-' || arr=='*' || arr=='/' || arr=='%'){
        cout<<')';
    }
}

int main(){

    stack<Node*> st;
    char arr[100];
    cin >> arr ;

    for(int i = 0; i<100; i++){
        if(arr[i]=='\0')
            break;
        Node *newn = new Node(arr[i]);
        if(arr[i]=='+' || arr[i]=='-' || arr[i]=='*' || arr[i]=='/' || arr[i]=='%'){
            newn->right = st.top();
            st.pop();
            newn->left = st.top();
            st.pop();
            st.push(newn);
        }
        else{
            st.push(newn);
        }
    }

    Node* root = st.top();
    inOrder(root);
}