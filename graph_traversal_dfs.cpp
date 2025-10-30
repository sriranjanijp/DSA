#include <iostream>

using namespace std;

struct AdjListNode {
    int dest;
    AdjListNode* next;
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

    void DFSRecursive(int v, bool* visited) {
        visited[v] = true;
        cout << v << " ";

        AdjListNode* temp = adj[v];
        while (temp != nullptr) {
            int adjVertex = temp->dest;
            if (!visited[adjVertex]) {
                DFSRecursive(adjVertex, visited);
            }
            temp = temp->next;
        }
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

    void DFS(int startVertex) {
        cout << "DFS traversal starting from vertex " << startVertex << ":" << endl;
        
        bool* visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }

        DFSRecursive(startVertex, visited);

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

    g.DFS(0);
    
    return 0;
}
