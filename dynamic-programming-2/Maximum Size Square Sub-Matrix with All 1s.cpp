#include <iostream>
#include <vector>
using namespace std;

int R, C;

void printMaxSubSquare(vector<vector<int>>& M) {
    vector<vector<int>> S(2, vector<int>(C, 0));
    int Max = 0;

    // Construct the entries
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {

            // Compute the entry at the current position
            int Entry = M[i][j];
            if (Entry != 0) {
                if (j != 0) {
                    Entry = 1 + min(S[1][j - 1], min(S[0][j - 1], S[1][j]));
                }
            }

            // Save the last entry and add the new one
            S[0][j] = S[1][j];
            S[1][j] = Entry;

            // Keep track of the max square length
            Max = max(Max, Entry);
        }
    }

    // Print the maximum square of 1s
    for (int i = 0; i < Max; i++) {
        for (int j = 0; j < Max; j++) {
            cout << "1 ";
        }
        cout << endl;
    }
}

// Driver Code
int main() {
    cin >> R >> C;

    vector<vector<int>> M(R, vector<int>(C));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> M[i][j];
        }
    }

    printMaxSubSquare(M);

    return 0;
}
