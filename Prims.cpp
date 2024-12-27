 #include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

using namespace std;

class Graph {
private:
    int vertices;  
    vector<vector<pair<int, int>>> adjList;  

public:
    Graph(int v) {
        vertices = v;
        adjList.resize(v);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight}); 
    }

    void primMST() {
        vector<int> key(vertices, INT_MAX);   
        vector<int> parent(vertices, -1);    
        vector<bool> inMST(vertices, false);  
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
 
        key[0] = 0;
        pq.push({0, 0});  

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u])
                continue;

            inMST[u] = true;

            for (auto &[v, weight] : adjList[u]) {
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }
 
        cout << "Edges in the MST:\n";
        for (int i = 1; i < vertices; ++i) {
            cout << parent[i] << " - " << i << "\n";
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
