#include <iostream>
#include <queue>
#include <limits>
#include <vector>


using namespace std;

#define INF numeric_limits<int>::max()

class Graph {
private:
    vector<vector<int>> adjecencyMatrix;
    int numV;

public:
    Graph(int ver) {
        numV = ver;
        adjecencyMatrix.resize(numV, vector<int>(numV, 0));
    }

    void addEdge(int start, int end, int weight) {
        adjecencyMatrix[start][end] = adjecencyMatrix[end][start] = weight;

    }

    vector<int> dijkstra(int source) {
        vector<int> dist(numV, INF);
        dist[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pr_q;
        pr_q.push({0, source});
        while (!pr_q.empty()) {
            int x = pr_q.top().second;
            pr_q.pop();
            for (int i = 0; i < numV; ++i) {
                if (adjecencyMatrix[x][i] != 0 && dist[x] + adjecencyMatrix[x][i] < dist[i]) {
                    dist[i] = dist[x] + adjecencyMatrix[x][i];
                    pr_q.push({dist[i], i});
                }
            }
        }

        return dist;
    }
};

int main() {
    Graph graph(6);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 4, 15);
    graph.addEdge(0, 5, 5);
    graph.addEdge(1, 2, 10);
    graph.addEdge(1, 3, 30);
    graph.addEdge(2, 3, 12);
    graph.addEdge(2, 4, 5);
    graph.addEdge(3, 5, 20);


    int sourceVertex = 5;
    vector<int> shortestDistances = graph.dijkstra(sourceVertex);
    int n = shortestDistances.size();
    cout << "Shortest distances from "<<sourceVertex<<endl;
    for (int i = 0; i < n; ++i) {
        cout << "To vertex " << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
