#include <iostream>
#include <vector>
using namespace std;

bool solveMaze(vector<vector<int>>& maze, vector<vector<int>>& solution, int row, int col) {
    int n = maze.size();

    if (row == n - 1 && col == n - 1 && maze[row][col] == 1) {
        solution[row][col] = 1;
        return true;
    }

    if (row >= 0 && row < n && col >= 0 && col < n &&
        maze[row][col] == 1 && solution[row][col] == 0) {

        solution[row][col] = 1;

        if (solveMaze(maze, solution, row + 1, col)) {
            return true;
        }

        if (solveMaze(maze, solution, row, col + 1)) {
            return true;
        }

        if (solveMaze(maze, solution, row - 1, col)) {
            return true;
        }

        if (solveMaze(maze, solution, row, col - 1)) {
            return true;
        }

        solution[row][col] = 0;
    }

    return false;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int n = maze.size();
    vector<vector<int>> solution(n, vector<int>(n, 0));

    if (solveMaze(maze, solution, 0, 0)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << solution[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution";
    }

    return 0;
}