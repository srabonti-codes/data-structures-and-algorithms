#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;
};

int findParent(vector<int>& parent, int node) {
    if (parent[node] == node)
        return node;

    return parent[node] = findParent(parent, parent[node]);
}

void unionSets(vector<int>& parent, vector<int>& rank, int a, int b) {
    a = findParent(parent, a);
    b = findParent(parent, b);

    if (a == b)
        return;

    if (rank[a] < rank[b])
        parent[a] = b;
    else if (rank[a] > rank[b])
        parent[b] = a;
    else {
        parent[b] = a;
        rank[a]++;
    }
}

int main() {
    int vertices = 4;

    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    vector<int> parent(vertices);
    vector<int> rank(vertices, 0);

    for (int i = 0; i < vertices; i++)
        parent[i] = i;

    int totalWeight = 0;

    for (Edge edge : edges) {
        int a = findParent(parent, edge.source);
        int b = findParent(parent, edge.destination);

        if (a != b) {
            cout << edge.source << " - "
                 << edge.destination << " : "
                 << edge.weight << endl;

            totalWeight += edge.weight;
            unionSets(parent, rank, a, b);
        }
    }

    cout << "Total weight: " << totalWeight;

    return 0;
}