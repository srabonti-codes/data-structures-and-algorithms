#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int source;
    int destination;
    int weight;
};

int main() {
    int vertices = 5;

    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    vector<int> dist(vertices, INT_MAX);
    dist[0] = 0;

    for (int i = 1; i < vertices; i++) {
        for (Edge edge : edges) {
            if (dist[edge.source] != INT_MAX &&
                dist[edge.source] + edge.weight < dist[edge.destination]) {
                dist[edge.destination] =
                    dist[edge.source] + edge.weight;
            }
        }
    }

    bool negativeCycle = false;

    for (Edge edge : edges) {
        if (dist[edge.source] != INT_MAX &&
            dist[edge.source] + edge.weight < dist[edge.destination]) {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle) {
        cout << "Negative cycle detected";
    } else {
        for (int i = 0; i < vertices; i++)
            cout << i << ": " << dist[i] << endl;
    }

    return 0;
}