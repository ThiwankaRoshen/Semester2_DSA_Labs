#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> p;
void add_edge(vector<vector<p>>& graph, int u, int v, int w) {
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}
void prim(const vector<vector<p>>& graph, int startVertex) {
    int V = graph.size();
    priority_queue<p, vector<p>, greater<p>> pr_qu;
    vector<bool> inMST(V, false);
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    pr_qu.push(make_pair(0, startVertex));
    key[startVertex] = 0;

    while (pr_qu.empty()==false) {
        int u = pr_qu.top().second;
        pr_qu.pop();
        inMST[u] = true;
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!inMST[v] && (weight < key[v])) {
                key[v] = weight;
                parent[v] = u;
                pr_qu.push(make_pair(key[v], v));
            }
        }
    }
    for (int i = 1; i < V; ++i) {
        cout << parent[i] << " - " << i << endl;
    }
}

int main() {
    vector<vector<int>> g = {{0, 3, 0, 0, 0, 1},{3, 0, 2, 1, 10, 0},{0, 2, 0, 3, 0, 5},{0, 1, 3, 0, 5, 0},{0, 10, 0, 5, 0, 4},{1, 0, 5, 0, 4, 0}};
    int length = g.size();
    vector<vector<p>> graphVector(length);
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            if (g[i][j]) {
                add_edge(graphVector, i, j, g[i][j]);
            }
        }
    }
    prim(graphVector, 0);

}
