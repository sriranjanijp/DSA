#include <iostream>
using namespace std;

struct Node{
    int key;
    string value;
    Node* next;
};

class HashMap{
    private:

    Node** table;
    int size;
    int hashkey(int key){
        return(key%size);
    }

    public:

    HashMap(int s){
        size = s;
        table = new Node*[size];
        
        for(int i = 0; i< size; i++){
            table[i] = nullptr;
        }
    }

    void insert(int key, string value){
        int index = hashkey(key);
        Node* current = table[index];

        while(current!=nullptr){
            if(current->key == key){
                current->value = value;
                cout << "Updated key: " << key << endl;
                return;
            }
            current = current->next;
        }

        Node* newn = new Node();
        newn->key = key;
        newn->value = value;
        newn->next = table[index];
        table[index] = newn;
        cout << "Inserted key: " << key << " at index " << index << endl;
    }

    void search(int key){
        int index = hashkey(key);
        Node* curr = table[index];

        while(curr!=nullptr){
            if(curr->key==key){
                cout << "key found: " << key << " of value " << curr->value << endl;
                return;
            }
            curr = curr->next;
        }

        cout << "Key not found" << endl;
    }

    void deletekey(int key){
        int index = hashkey(key);
        Node* curr = table[index];
        Node* prev = nullptr;

        while(curr!= nullptr && curr->key != key){
            prev = curr;
            curr = curr->next;
        }

        if(curr==nullptr){
            cout << "Key not found" << endl;
        }
        else if(prev==nullptr){
            table[index] = curr->next;
        }
        else{
            prev->next = curr-> next;
        }
    }

    void display(){
        cout << "-----------------------------" << endl;
        cout << "HashMap: " << endl;
        for(int i = 0; i<size; i++){
            Node* curr = table[i];
            cout << "Bucket " << i << ": ";
            while(curr!=nullptr){
                cout << "[" << curr-> key << " : " << curr-> value << "] -> ";
                curr = curr->next;
            }
            cout << "NULL" << endl;
        }
        cout << "-----------------------------" << endl;
    }
};

int main(){
    HashMap h (6);
    h.insert(2,"two");
    h.insert(8,"eight");
    h.display();

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
    h.deletekey(8);
    h.deletekey(15);
    h.deletekey(99);   

    h.display();
}