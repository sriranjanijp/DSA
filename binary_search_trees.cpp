#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (!root) 
        return new Node(val);
    if (val < root->data) 
        root->left = insert(root->left, val);
    else if (val > root->data) 
        root->right = insert(root->right, val);
    return root;
}

Node* findMin(Node* root) {
    while (root !=nullptr && root->left != nullptr)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int val) {
    if (root == nullptr) 
        return nullptr;
    if (val < root->data) 
        root->left = deleteNode(root->left, val);
    else if (val > root->data) 
        root->right = deleteNode(root->right, val);
    else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << ' ';
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root) {
        cout << root->data << ' ';
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << ' ';
    }
}

int main() {
    Node* root = nullptr;
    int choice, val;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Inorder Traversal" << endl;
        cout << "4. Preorder Traversal" << endl;
        cout << "5. Postorder Traversal" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                root = insert(root, val);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> val;
                root = deleteNode(root, val);
                break;
            case 3:
                inorder(root);
                cout << endl;
                break;
            case 4:
                preorder(root);
                cout << endl;
                break;
            case 5:
                postorder(root);
                cout << endl;
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option." << endl;
        }
    } while (choice != 0);
    return 0;
}
