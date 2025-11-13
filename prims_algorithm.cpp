#include <iostream>
using namespace std;

#define INF 999999

struct AdjListNode {
    int dest;
    int weight;
    AdjListNode* next;
};

class Graph {
private:
    int V;
    AdjListNode** adj;

    AdjListNode* newAdjListNode(int dest, int weight) {
        AdjListNode* newNode = new AdjListNode();
        newNode->dest = dest;
        newNode->weight = weight;
        newNode->next = nullptr;
        return newNode;
    }

    int minKey(int* key, bool* mstSet) {
        int min = INF;
        int min_index = -1;

        for (int v = 0; v < V; v++) {
            if (mstSet[v] == false && key[v] < min) {
                min = key[v];
                min_index = v;
            }
        }
        return min_index;
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

    void addEdge(int src, int dest, int weight) {
        AdjListNode* newNode = newAdjListNode(dest, weight);
        newNode->next = adj[src];
        adj[src] = newNode;

        newNode = newAdjListNode(src, weight);
        newNode->next = adj[dest];
        adj[dest] = newNode;
    }

    void PrimMST() {
        int* parent = new int[V];
        int* key = new int[V];
        bool* mstSet = new bool[V];

        for (int i = 0; i < V; i++) {
            key[i] = INF;
            mstSet[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < V; count++) {
            int u = minKey(key, mstSet);
            
            if (u == -1) break;

            mstSet[u] = true;
            //cout << "u: " << u << endl;
            AdjListNode* temp = adj[u];
            while (temp != nullptr) {
                int v = temp->dest;
                int weight = temp->weight;

                if (mstSet[v] == false && weight < key[v]) {
                    parent[v] = u;
                    key[v] = weight;
                }
                temp = temp->next;
            }

            /*
            cout << "count: " << count << " : " ;
            for (int i = 0; i < V; i++) {
                cout << parent[i] << " " ;
            }
            cout << endl;
            */
        }

        cout << "Prim's MST (Adjacency List):" << endl;
        cout << "Edge \tWeight" << endl;
        int totalWeight = 0;
        for (int i = 1; i < V; i++) {
            if (parent[i] != -1 && key[i] != INF) {
                 cout << parent[i] << " - " << i << " \t" << key[i] << endl;
                 totalWeight += key[i];
            }
        }
        cout << "Total MST Weight: " << totalWeight << endl;

        delete[] parent;
        delete[] key;
        delete[] mstSet;
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.PrimMST();

    return 0;
}

