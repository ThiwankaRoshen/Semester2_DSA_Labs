#include <iostream>
#include<list>
using namespace std;

struct Node{
    int label;
    list<int> nbs;
};

struct Graph{
    int n=8;
    Node * nodes = new Node[n+1];

    void intializeNodes(){
        for(int i=0;i<n;i++){
            nodes[i].label=i;
        }
    }

    void addEdge(int u, int v){
        nodes[u].nbs.push_back(v);
        nodes[v].nbs.push_back(u);
    }

    void print(){
        for(int i=1;i<n+1;i++){
            cout<<i<<"-->";
            for(int j:nodes[i].nbs){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
};

int main() {
    Graph * Graph1 = new Graph;
    (*Graph1).intializeNodes();
    (*Graph1).addEdge(1,2);
    (*Graph1).addEdge(1,3);
    (*Graph1).addEdge(1,4);
    (*Graph1).addEdge(1,5);
    (*Graph1).addEdge(2,3);
    (*Graph1).addEdge(2,6);
    (*Graph1).addEdge(4,6);
    (*Graph1).addEdge(4,7);
    (*Graph1).addEdge(4,8);
    (*Graph1).addEdge(5,6);
    (*Graph1).addEdge(5,7);
    (*Graph1).addEdge(5,8);
    (*Graph1).print();
}
