#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool insert(Node* &root, int val) {
    if (root == nullptr) {
        root = new Node(val);
        return true;
    }
    // Try to fill left subtree first
    if (root->left == nullptr) return insert(root->left, val);
    else if (root->right == nullptr) return insert(root->right, val);
    if (insert(root->left, val)) return true;
    return insert(root->right, val);
}

bool deleteLeaf(Node* &root, int val) {
    if (root == nullptr) return false;
    if (root->left && root->left->data == val && !root->left->left && !root->left->right) {
        delete root->left;
        root->left = nullptr;
        return true;
    }
    if (root->right && root->right->data == val && !root->right->left && !root->right->right) {
        delete root->right;
        root->right = nullptr;
        return true;
    }
    return deleteLeaf(root->left, val) || deleteLeaf(root->right, val);
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
        cout << "Enter choice: " << endl;
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter value: "; 
                cin >> val;
                insert(root, val);
                break;
            case 2:
                cout << "Delete leaf with value: "; 
                cin >> val;
                if (!deleteLeaf(root, val)) 
                    cout << "Node not found or not a leaf." << endl;
                break;
            case 3:
                inorder(root); cout << endl;
                break;
            case 4:
                preorder(root); cout << endl;
                break;
            case 5:
                postorder(root); cout << endl;
                break;
            case 0:
                cout << "Exiting...\n"; break;
            default:
                cout << "Invalid option.\n";
        }
    } while(choice != 0);
    return 0;
}