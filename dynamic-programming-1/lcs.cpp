#include <iostream>
#include <vector>
using namespace std;

/* Returns length of LCS for X, Y */
int lcs(string X, string Y, int m, int n) {
    vector<vector<int>> L(m + 1, vector<int>(n + 1, 0));

    /* Building L[m+1][n+1] in bottom-up fashion */
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int m = s1.length();
    int n = s2.length();

    cout << lcs(s1, s2, m, n) << endl;
    return 0;
}
