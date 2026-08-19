#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertices = 5;

    vector<vector<int>> graph(vertices);

    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(4);

    for (int i = 0; i < vertices; i++) {
        cout << i << ": ";

        for (int neighbor : graph[i]) {
            cout << neighbor << " ";
        }

        cout << endl;
    }

    return 0;
}