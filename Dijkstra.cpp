#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

typedef pair<int, int> pii;  
class Graph {
private:
    int vertices;  
    vector<vector<pii>> adjList;  

public:
    Graph(int v) : vertices(v) {
        adjList.resize(v);
    }
    void addEdge(int u, int v, int weight) {
        adjList[u].emplace_back(weight, v);
        adjList[v].emplace_back(weight, u);  
    }

    void dijkstra(int start) {
        vector<int> dist(vertices, INT_MAX);  
        priority_queue<pii, vector<pii>, greater<pii>> pq;  

        dist[start] = 0;
        pq.emplace(0, start);

        while (!pq.empty()) {
            int currentDist = pq.top().first;
            int currentNode = pq.top().second;
            pq.pop();

            if (currentDist > dist[currentNode])
                continue;

            for (auto &neighbor : adjList[currentNode]) {
                int weight = neighbor.first;
                int nextNode = neighbor.second;

                if (currentDist + weight < dist[nextNode]) {
                    dist[nextNode] = currentDist + weight;
                    pq.emplace(dist[nextNode], nextNode);
                }
            }
        }
 
        cout << "Vertex \tDistance from Source\n";
        for (int i = 0; i < vertices; ++i) {
            cout << i << "\t" << dist[i] << "\n";
        }
    }
};

int main() {
    Graph g(5);  
    g.addEdge(0, 1, 2);
    g.addEdge(0, 4, 9);
    g.addEdge(1, 2, 4);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 3);

    g.dijkstra(0);

    return 0;
}
