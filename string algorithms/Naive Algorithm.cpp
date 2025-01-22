#include <iostream>
#include <string>
using namespace std;

void search(const string &pat, const string &txt) {
    int l1 = pat.length();
    int l2 = txt.length();
    int i = 0, j = l2 - 1;

    // Sliding window approach to search for the pattern
    for (i = 0, j = l2 - 1; j < l1;) {
        if (txt == pat.substr(i, l2)) {
            cout << "Found at " << i << endl;
            exit(0); // Exit the program upon finding the match
        }
        i++;
        j++;
    }
    cout << "Not Found" << endl;
}

int main() {
    string pat, txt;

    // Input the pattern and the text to search for
    cin >> pat >> txt;

    search(pat, txt);

    return 0;
}
