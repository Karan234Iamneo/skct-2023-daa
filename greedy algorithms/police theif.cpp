#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

// Function to calculate the maximum number of thieves caught
int policeThief(vector<char> &arr, int n, int k) {
    int res = 0;
    vector<int> thi; // Stores indices of thieves
    vector<int> pol; // Stores indices of police

    // Separate indices of police and thieves
    for (int i = 0; i < n; i++) {
        if (arr[i] == 'P')
            pol.push_back(i);
        else if (arr[i] == 'T')
            thi.push_back(i);
    }

    int l = 0, r = 0;

    // Use two pointers to find matching police and thief pairs
    while (l < thi.size() && r < pol.size()) {
        if (abs(thi[l] - pol[r]) <= k) {
            res++;
            l++;
            r++;
        } else if (thi[l] < pol[r]) {
            l++;
        } else {
            r++;
        }
    }

    return res;
}

int main() {
    string s;
    int k;

    // Input string of police (P) and thieves (T)
    getline(cin, s);

    // Convert string to vector<char>
    vector<char> arr(s.begin(), s.end());

    // Input maximum distance k
    cin >> k;

    // Find and print the result
    cout << policeThief(arr, arr.size(), k) << endl;

    return 0;
}
