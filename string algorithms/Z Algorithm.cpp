#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to fill Z array for the given string
void getZarr(const string &str, vector<int> &Z) {
    int n = str.length();
    int L = 0, R = 0;

    for (int i = 1; i < n; ++i) {
        if (i > R) {
            L = R = i;
            while (R < n && str[R - L] == str[R])
                R++;
            Z[i] = R - L;
            R--;
        } else {
            int k = i - L;
            if (Z[k] < R - i + 1) {
                Z[i] = Z[k];
            } else {
                L = i;
                while (R < n && str[R - L] == str[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
}

// Function to search for the pattern in the text using the Z algorithm
void zAlgo(const string &text, const string &pattern) {
    // Create concatenated string "P$T"
    string concat = pattern + "$" + text;
    int l = concat.length();

    // Create Z array and compute it
    vector<int> Z(l);
    getZarr(concat, Z);

    bool found = false;

    // Loop through the Z array for matching conditions
    for (int i = 0; i < l; ++i) {
        if (Z[i] == pattern.length()) {
            cout << "Found at " << (i - pattern.length() - 1) << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Not Found" << endl;
}

// Driver program
int main() {
    string text, pattern;

    // Input text and pattern
    cin >> text >> pattern;

    // Perform Z algorithm search
    zAlgo(text, pattern);

    return 0;
}
