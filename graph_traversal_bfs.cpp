#include <iostream>
using namespace std;

struct AdjListNode {
    int dest;
    AdjListNode* next;
};

struct QueueNode {
    int data;
    QueueNode* next;
};

class Queue {
private:
    QueueNode *front, *rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int data) {
        QueueNode* temp = new QueueNode();
        temp->data = data;
        temp->next = nullptr;

        if (rear == nullptr) {
            front = rear = temp;
            return;
        }

        rear->next = temp;
        rear = temp;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "[Error] Queue is empty" << endl;
            return -1;
        }

        QueueNode* temp = front;
        int data = temp->data;

        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        return data;
    }
};

class Graph {
private:
    int V;
    AdjListNode** adj;

    AdjListNode* newAdjListNode(int dest) {
        AdjListNode* newNode = new AdjListNode();
        newNode->dest = dest;
        newNode->next = nullptr;
        return newNode;
    }

public:
    Graph(int V) {
        this->V = V;
        adj = new AdjListNode*[V];

        for (int i = 0; i < V; ++i) {
            adj[i] = nullptr;
        }
    }

    ~Graph() {
        for (int i = 0; i < V; ++i) {
            AdjListNode* current = adj[i];
            while (current != nullptr) {
                AdjListNode* toDelete = current;
                current = current->next;
                delete toDelete;
            }
        }
        delete[] adj;
    }

    void addEdge(int src, int dest) {
        AdjListNode* newNode = newAdjListNode(dest);
        newNode->next = adj[src];
        adj[src] = newNode;

        newNode = newAdjListNode(src);
        newNode->next = adj[dest];
        adj[dest] = newNode;
    }


    void BFS(int startVertex) {
        cout << "BFS traversal starting from vertex " << startVertex << ":" << endl;
        
        bool* visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }

        Queue queue;

        visited[startVertex] = true;
        queue.enqueue(startVertex);

        

        while (!queue.isEmpty()) {
            int currentVertex = queue.dequeue();
            cout << currentVertex << " ";

            AdjListNode* temp = adj[currentVertex];
            while (temp != nullptr) {
                int adjVertex = temp->dest;
                if (!visited[adjVertex]) {
                    visited[adjVertex] = true;
                    queue.enqueue(adjVertex);
                }
                temp = temp->next;
            }
        }
        cout << endl;

        delete[] visited;
    }
};

int main() {
    Graph g(6);
    
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);

    g.BFS(0);
    
    return 0;
}

