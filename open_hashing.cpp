#include <iostream>
#include <string>
using namespace std;

struct Node {
    int key;
    string value;
    Node* next;

    Node(int k, string v) : key(k), value(v), next(nullptr) {}
};

class HashMap {
private:
    Node** table;
    
    int table_size;

    int hashFunction(int key) {
        return (key % table_size);
    }

public:
    HashMap(int size) : table_size(size) {
        table = new Node*[table_size];
        
        for (int i = 0; i < table_size; ++i) {
            table[i] = nullptr;
        }
    }

    ~HashMap() {
        for (int i = 0; i < table_size; ++i) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* nodeToDelete = current;
                current = current->next;
                delete nodeToDelete;
            }
        }
        
        delete[] table;
    }

    void insert(int key, string value) {
        int index = hashFunction(key);
        Node* current = table[index];

        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                cout << "Updated key: " << key << endl;
                return;
            }
            current = current->next;
        }

        Node* newNode = new Node(key, value);
        
        newNode->next = table[index];
        table[index] = newNode;
        cout << "Inserted key: " << key << " at index " << index << endl;
    }

    void search(int key) {
        int index = hashFunction(key);
        Node* current = table[index];

        while (current != nullptr) {
            if (current->key == key) {
                cout << "Found key: " << key << ", Value: " << current->value << endl;
                return;
            }
            current = current->next;
        }

        cout << "Error: Key not found: " << key << endl;
    }

    void remove(int key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current != nullptr && current->key != key) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Error: Key not found for removal: " << key << endl;
            return;
        }

        if (prev == nullptr) {
            table[index] = current->next;
        }
        else {
            prev->next = current->next;
        }

        delete current;
        cout << "Removed key: " << key << endl;
    }

    void display() {
        for (int i = 0; i < table_size; ++i) {
            cout << "Bucket " << i << ": ";
            Node* current = table[i];
            if (current == nullptr) {
                cout << "[]";
            } else {
                while (current != nullptr) {
                    cout << "[K:" << current->key << ", V:" << current->value << "] -> ";
                    current = current->next;
                }
                cout << "NULL";
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap h(7);

    h.insert(1, "one");
    h.insert(8, "eight");
    h.insert(15, "fifteen");
    h.insert(3, "three");
    h.insert(10, "ten");
    h.insert(5, "five");
    h.insert(12, "twelve");

    h.display();

    
    h.search(10);
    h.search(15);
    h.search(99);

    h.insert(1, "one_updated");
    h.display();
    
    h.search(1);
    h.remove(8);
    h.remove(15);
    h.remove(99); 
    h.remove(3);   

    h.display();

    return 0;
}