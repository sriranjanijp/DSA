#include <iostream>
using namespace std;

#define INF 99999

struct Gnode{
    int dest;
    int wt;
    Gnode* next;
};

class Graph{
    private:

    int V;
    Gnode** adj;

    public:

    Graph(int v){
        V = v;
        adj = new Gnode*[V];

        for(int i = 0; i<V; i++){
            adj[i] = nullptr;
        }
    }

    ~Graph(){
        for(int i = 0; i<V; i++){
            Gnode* temp = adj[i];
            while(temp!=nullptr){
                Gnode* del = temp;
                temp = temp->next;
                delete del;
            }
        }
        delete [] adj;
    }

    int minkey(bool* mstset, int* key){
        int min = INF;
        int min_index = -1;

        for(int i = 0; i<V; i++){
            if(mstset[i]==false && key[i]<min){
                min = key[i];
                min_index = i;
            }
        }

        return min_index;
    }

    Gnode* newn(int dest, int weight){
        Gnode* newG = new Gnode();
        newG->dest = dest;
        newG-> wt = weight;
        newG->next= nullptr;
        return newG;
    }

    void addEdge(int src, int dest, int weight){
        Gnode* newnode = newn(dest,weight);
        newnode->next = adj[src];
        adj[src] = newnode;

        newnode = newn(src,weight);
        newnode->next = adj[dest];
        adj[dest] = newnode;
    }

    void Prims(){
        bool* mstset = new bool[V];
        int* key = new int[V];
        int* parent = new int[V];

        for(int i = 0; i<V; i++){
            key[i] = INF;
            mstset[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;

        for(int i = 0; i<V; i++){
            int u = minkey(mstset,key);

            if(u==-1)
                return;

            mstset[u] = true;

            Gnode* temp = adj[u];
            while(temp!=nullptr){
                int weight = temp->wt;
                int v = temp->dest;

                if(mstset[v]==false && weight<key[v]){
                    parent[v] = u;
                    key[v] = weight;
                }
                temp = temp->next;
            }
        }

        cout << "Prims Algorithm" << endl;
        cout << " Edge  \t Weight" << endl;
        int total = 0;
        for(int i = 0; i<V; i++){
            if(parent[i]!= -1 && key[i]< INF){
                cout<<parent[i] << " - " << i << " \t    " << key[i] << endl;
                total += key[i];
            }
        }
        cout << "Total Weight: " << total << endl;
    }

};

int main(){
    Graph g(5);

    g.addEdge(0,1,2);
    g.addEdge(0,3,6);
    g.addEdge(1,4,5);
    g.addEdge(1,2,3);
    g.addEdge(1,3,8);
    g.addEdge(2,4,7);
    g.addEdge(3,4,9);

    g.Prims();
}