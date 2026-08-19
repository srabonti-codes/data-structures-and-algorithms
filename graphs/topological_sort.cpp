#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int vertices = 6;

    vector<vector<int>> graph(vertices);
    vector<int> indegree(vertices, 0);

    graph[5].push_back(2);
    graph[5].push_back(0);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(1);

    for (int i = 0; i < vertices; i++) {
        for (int neighbor : graph[i]) {
            indegree[neighbor]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < vertices; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        cout << current << " ";

        for (int neighbor : graph[current]) {
            indegree[neighbor]--;

            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return 0;
}