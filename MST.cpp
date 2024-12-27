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

    void primMST() {
        vector<int> key(vertices, INT_MAX);  
        vector<bool> inMST(vertices, false);  
        vector<int> parent(vertices, -1);  
        priority_queue<pii, vector<pii>, greater<pii>> pq;  

         
        key[0] = 0;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            inMST[u] = true; 

            for (auto &[weight, v] : adjList[u]) {
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.emplace(key[v], v);
                    parent[v] = u;
                }
            }
        }
        cout << "Edge \tWeight\n";
        for (int i = 1; i < vertices; ++i) {
            cout << parent[i] << " - " << i << "\t" << key[i] << "\n";
        }
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
 
    g.primMST();

    return 0;
}
