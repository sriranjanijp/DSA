#include <iostream>
using namespace std;

struct Bnode{
    int val;
    Bnode* left;
    Bnode* right;
    Bnode(int data): val(data), left(nullptr), right(nullptr){} 
};

Bnode* insert(Bnode* root, int val){
    if(root == nullptr){
        return new Bnode(val);
    }
    if(val<root->val){
        root-> left =  insert(root->left, val);
    }
    else if(val>root->val){
        root-> right = insert(root->right, val);
    }
    return root;
}

Bnode* findmin(Bnode* root){
    while(root!=nullptr && root->left != nullptr){
        root = root->left;
    }
    return root;
}

Bnode* remove(Bnode* root, int val){
    if(root==nullptr){
        return nullptr;
    }
    if(val<root->val){
        root->left = remove(root->left,val);
    }
    else if(val>root->val){
        root->right = remove(root->right,val);
    }
    else{
        if(root->left == nullptr){
            Bnode* temp = root->right;
            return temp;
        }
        else if(root->right == nullptr){
            Bnode* temp = root->left;
            return temp;
        }
        
        Bnode* temp = findmin(root->right);
        root->val = temp->val;
        root->right = remove(root->right, temp->val);
    }
    return root;
}

void inorder(Bnode* root){
    if(root){
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

void preorder(Bnode* root){
    if(root){
        preorder(root->left);
        preorder(root->right);
        cout << root->val << " ";
    }
}

void postorder(Bnode* root){
    if(root){
        cout << root->val << " ";
        postorder(root->left);
        postorder(root->right);
    }
}

int main(){
    Bnode* root = nullptr;
    root = insert(root, 1);
    inorder(root);
    cout << endl;
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 9);
    inorder(root);
    cout << endl;
    root = remove(root, 5);
    inorder(root);
    cout << endl;
}