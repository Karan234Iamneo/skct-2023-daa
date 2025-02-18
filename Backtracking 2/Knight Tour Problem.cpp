#include <iostream>
using namespace std;

#define N 8  // Change this value to solve for different board sizes

// Check if the move is within the board and the cell is unvisited
bool isSafe(int x, int y, int sol[N][N]) {
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

// Print the solution board
void printSolution(int sol[N][N]) {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++)
            cout << sol[x][y] << " ";
        cout << endl;
    }
}

// Utility function to solve Knight's Tour
bool solveKTUtil(int x, int y, int movei, int sol[N][N], int xMove[], int yMove[]) {
    if (movei == N * N) // If all squares are covered, return true
        return true;

    for (int k = 0; k < 8; k++) { // Try all possible moves
        int next_x = x + xMove[k];
        int next_y = y + yMove[k];

        if (isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei; // Place the knight

            if (solveKTUtil(next_x, next_y, movei + 1, sol, xMove, yMove))
                return true; // If solution is found, return true
            
            sol[next_x][next_y] = -1; // Backtrack
        }
    }
    return false;
}

// Solves the Knight's Tour problem
bool solveKT() {
    int sol[N][N];

    // Initialize board with -1
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;

    // Knight's possible moves
    int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    // Start from (0, 0)
    sol[0][0] = 0;

    if (!solveKTUtil(0, 0, 1, sol, xMove, yMove)) {
        cout << "Solution does not exist" << endl;
        return false;
    } else {
        printSolution(sol);
    }
    return true;
}

int main() {
    solveKT();
    return 0;
}
