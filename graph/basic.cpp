#include<bits/stdc++.h>
using namespace std;

// for generic , you just need to explicitly tell the datatype
template <typename T>
class Graph {
public:

    unordered_map<T, list<T>> adj;

    void addEdge(int u, int v, bool direction) {
        // create an edge from u to v
        adj[u].push_back(v);

        // undirected graph
        if(direction == 0)
            adj[v].push_back(u);
    }

    void printAdjList() {
        for(auto i: adj) {
            cout << i.first << "->";
            for(auto j : i.second) 
                cout << j << ", ";

            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the no. of nodes: ";
    cin >> n;

    int m;
    cout << "Enter the no. of edges: ";
    cin >> m;
    
    Graph<int> g;

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;

        // create an undirected graph
        g.addEdge(u, v, 0);
    }

    // print graph
    g.printAdjList();

}