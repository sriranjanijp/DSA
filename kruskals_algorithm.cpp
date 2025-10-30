#include <iostream>
#include <algorithm> // For std::sort

using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

class Graph {
private:
    int V, E;
    Edge* edge;

    int find(int* parent, int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent, parent[i]);
    }

    void Union(int* parent, int x, int y) {
        int xroot = find(parent, x);
        int yroot = find(parent, y);
        parent[xroot] = yroot;
    }

public:
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
        this->edge = new Edge[E];
    }

    ~Graph() {
        delete[] edge;
    }

    void addEdge(int index, int src, int dest, int weight) {
        edge[index].src = src;
        edge[index].dest = dest;
        edge[index].weight = weight;
    }

    void KruskalMST() {
        Edge* result = new Edge[V];
        int e = 0;
        int i = 0;

        std::sort(edge, edge + E, compareEdges);

        int* parent = new int[V];

        for (int v = 0; v < V; ++v) {
            parent[v] = v;
        }

        while (e < V - 1 && i < E) {
            Edge next_edge = edge[i++];

            int x = find(parent, next_edge.src);
            int y = find(parent, next_edge.dest);

            if (x != y) {
                result[e++] = next_edge;
                Union(parent, x, y);
            }
        }

        cout << "Kruskal's MST:" << endl;
        cout << "Edge \tWeight" << endl;
        int totalWeight = 0;
        for (i = 0; i < e; ++i) {
            cout << result[i].src << " - " << result[i].dest << " \t" << result[i].weight << endl;
            totalWeight += result[i].weight;
        }
        cout << "Total MST Weight: " << totalWeight << endl;

        delete[] parent;
        delete[] result;
    }
};

int main() {
    int V = 5;
    int E = 7;
    Graph g(V, E);

    g.addEdge(0, 0, 1, 2);
    g.addEdge(1, 0, 3, 6);
    g.addEdge(2, 1, 2, 3);
    g.addEdge(3, 1, 3, 8);
    g.addEdge(4, 1, 4, 5);
    g.addEdge(5, 2, 4, 7);
    g.addEdge(6, 3, 4, 9);

    g.KruskalMST();

    return 0;
}
