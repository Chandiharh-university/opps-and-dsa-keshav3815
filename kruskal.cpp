 #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

class Graph {
private:
    int vertices;  
    vector<Edge> edges; 

   
    int find(vector<int> &parent, int i) {
        if (parent[i] != i)
            parent[i] = find(parent, parent[i]);
        return parent[i];
    }
 
    void unionSets(vector<int> &parent, vector<int> &rank, int x, int y) {
        int xRoot = find(parent, x);
        int yRoot = find(parent, y);

        if (rank[xRoot] < rank[yRoot])
            parent[xRoot] = yRoot;
        else if (rank[xRoot] > rank[yRoot])
            parent[yRoot] = xRoot;
        else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }

public:
    Graph(int v) : vertices(v) {}

    void addEdge(int u, int v, int w) {
        edges.emplace_back(u, v, w);
    }

    void kruskalMST() {
        vector<Edge> result;  
        int e = 0;  
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight < b.weight;
        });

        vector<int> parent(vertices);
        vector<int> rank(vertices, 0);
 
        for (int i = 0; i < vertices; ++i)
            parent[i] = i;
 
        for (auto &edge : edges) {
            if (e == vertices - 1)  
                break;

            int x = find(parent, edge.src);
            int y = find(parent, edge.dest);

            if (x != y) {  
                result.push_back(edge);
                unionSets(parent, rank, x, y);
                e++;
            }
        }
        cout << "Edge \tWeight\n";
        for (auto &edge : result) {
            cout << edge.src << " - " << edge.dest << "\t" << edge.weight << "\n";
        }
    }
};
int main() {
    Graph g(4);  

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.kruskalMST();

    return 0;
}
