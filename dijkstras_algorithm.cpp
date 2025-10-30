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

    int minDistance(int* dist, bool* sptSet) {
        int min = INF;
        int min_index = -1;

        for (int v = 0; v < V; v++) {
            if (sptSet[v] == false && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    void printSolution(int* dist, int src) {
        cout << "Dijkstra's Shortest Path:" << endl;
        cout << "Vertex \t Distance from Source " << src << endl;
        for (int i = 0; i < V; i++) {
            cout << i << " \t ";
            if (dist[i] == INF) {
                cout << "INF" << endl;
            } else {
                cout << dist[i] << endl;
            }
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

    void addEdge(int src, int dest, int weight) {
        AdjListNode* newNode = newAdjListNode(dest, weight);
        newNode->next = adj[src];
        adj[src] = newNode;

        newNode = newAdjListNode(src, weight);
        newNode->next = adj[dest];
        adj[dest] = newNode;
    }

    void dijkstra(int src) {
        int* dist = new int[V];
        bool* sptSet = new bool[V];

        for (int i = 0; i < V; i++) {
            dist[i] = INF;
            sptSet[i] = false;
        }

        dist[src] = 0;

        for (int count = 0; count < V; count++) {
            int u = minDistance(dist, sptSet);
            
            if (u == -1) break;

            sptSet[u] = true;

            AdjListNode* temp = adj[u];
            while (temp != nullptr) {
                int v = temp->dest;
                int weight = temp->weight;

                if (!sptSet[v] && dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
                temp = temp->next;
            }
        }

        printSolution(dist, src);

        delete[] dist;
        delete[] sptSet;
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.dijkstra(0);

    return 0;
}
