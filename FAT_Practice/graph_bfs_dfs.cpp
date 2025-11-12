#include <iostream>
using namespace std;

struct QNode{
    int data;
    QNode* next;
};

class Queue{
    private:
        QNode *front, *rear;

    public:
        Queue(){
            front = rear = nullptr;
        }

        ~Queue(){
            while(!isEmpty()){
                dequeue();
            }
        }

        bool isEmpty(){
            return front==nullptr;
        }

        int dequeue(){
            if(isEmpty()){
                cout<<"Queue is empty"<<endl;
                return -1;
            }

            QNode* t = front;
            int d = front->data;

            front = front->next;

            if(front==nullptr){
                rear=nullptr;
            }
            delete t;
            //cout<<"Dequeued: "<<d<<endl;
            return d;
        }

        void enqueue(int in){
            QNode* newn = new QNode();
            newn->data = in;
            newn->next = nullptr;

            if(rear==nullptr){
                front=rear=newn;
                //cout << "Enqueued: " << in << endl;
                return;
            }

            rear->next = newn;
            rear = newn;

            //cout << "Enqueued: " << in << endl;
        }
};

struct GNode{
    int dest;
    GNode* next;
};

class Graph{
    private:
        int V;
        GNode** adj;

    public:
        Graph(int v){
            V = v;
            adj = new GNode*[V];

            for(int i = 0; i<V; i++){
                adj[i] = nullptr;
            }
        }

        ~Graph(){
            for(int i = 0; i<V; i++){
                GNode* curr = adj[i];
                while(curr != nullptr){
                    GNode* del = curr;
                    curr = curr->next;
                    delete del;
                }
            }
            delete[] adj;
        }

        GNode* newNode(int d){
            GNode* newn = new GNode();
            newn->dest = d;
            newn->next = nullptr;
            return newn;
        }

        void addEdge(int src, int dest){
            GNode* newn = newNode(dest);
            newn->next = adj[src];
            adj[src] = newn;

            newn = newNode(src);
            newn->next = adj[dest];
            adj[dest] = newn;
        }

        void BFS(int start){
            cout << "BFS starting at " << start << endl;

            bool* visited = new bool[V];
            for(int i = 0; i<V; i++){
                visited[i] = false;
            }

            Queue q;

            visited[start] = true;
            q.enqueue(start);
            
            while(!q.isEmpty()){
                //cout << q.isEmpty() << " is empty" << endl;
                int currentv = q.dequeue();
                cout << currentv << " " ;

                GNode* temp = adj[currentv];
                while(temp!=nullptr){
                    int adjv = temp->dest;
                    if(!visited[adjv]){
                        visited[adjv] = true;
                        q.enqueue(adjv);
                    }
                    temp = temp->next;
                }
                //cout << q.isEmpty() << " is empty at end" << endl;
            }

            cout << endl;
            //delete[] visited;
        }

        void DFS(int start){
            cout << "Starting DFS from: " << start << endl;

            bool* visited = new bool[V];
            for(int i = 0; i<V; i++){
                visited[i] = false;
            }

            DFS_recur(start, visited);
            cout << endl;
        }

        void DFS_recur(int v, bool* visited){
            visited[v] = true;
            cout << v << " " ;

            GNode* temp = adj[v];
            while(temp!=nullptr){
                int adjn = temp->dest;
                if(!visited[adjn]){
                    DFS_recur(adjn,visited);
                }
                temp = temp->next;
            }
        }
};

int main(){
    Graph gr(6);
    gr.addEdge(0,1);
    gr.addEdge(0,2);
    gr.addEdge(1,2);
    gr.addEdge(1,3);
    gr.addEdge(2,3);
    gr.addEdge(3,5);
    gr.BFS(0);
    gr.DFS(0);
}