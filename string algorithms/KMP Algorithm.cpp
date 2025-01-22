#include <iostream>
#include <vector>
#include <string>
using namespace std;

void computeLPSArray(const string &pat, int M, vector<int> &lps) {
    int len = 0; // Length of the previous longest prefix suffix
    int i = 1;
    lps[0] = 0; // lps[0] is always 0

    // Loop to calculate lps[i] for i = 1 to M - 1
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(const string &pat, const string &txt) {
    int M = pat.length();
    int N = txt.length();

    // Create lps[] that will hold the longest prefix suffix values for pattern
    vector<int> lps(M);
    computeLPSArray(pat, M, lps);

    int i = 0; // Index for txt[]
    int j = 0; // Index for pat[]
    bool found = false;

    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            found = true;
            cout << "Found at " << (i - j) << endl;
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    if (!found) {
        cout << "Not Found" << endl;
    }
}

int main() {
    string txt, pat;

    // Input the text and pattern
    cin >> txt >> pat;

    KMPSearch(pat, txt);

    return 0;
}
