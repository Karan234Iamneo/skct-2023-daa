#include <iostream>
#include <vector>
using namespace std;

int N;

void printSolution(vector<vector<int>>& sol) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

bool isSafe(vector<vector<int>>& maze, int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMazeUtil(vector<vector<int>>& maze, int x, int y, vector<vector<int>>& sol) {
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y)) {
        if (sol[x][y] == 1)
            return false;

        sol[x][y] = 1;

        if (solveMazeUtil(maze, x + 1, y, sol)) return true;
        if (solveMazeUtil(maze, x, y + 1, sol)) return true;
        if (solveMazeUtil(maze, x - 1, y, sol)) return true;
        if (solveMazeUtil(maze, x, y - 1, sol)) return true;

        sol[x][y] = 0;
        return false;
    }

    return false;
}

bool solveMaze(vector<vector<int>>& maze) {
    vector<vector<int>> sol(N, vector<int>(N, 0));

    if (!solveMazeUtil(maze, 0, 0, sol)) {
        cout << "Solution doesn't exist" << endl;
        return false;
    }

    printSolution(sol);
    return true;
}

int main() {
    cin >> N;
    vector<vector<int>> maze(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
        }
    }

    solveMaze(maze);
    return 0;
}
