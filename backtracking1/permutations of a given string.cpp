#include <iostream>
#include <string>
using namespace std;

void permute(string str, int l, int r);
string swap(string a, int i, int j);

int main() {
    string str;
    cin >> str;  // Taking input (exactly like Java's `sc.nextLine();`)
    int n = str.length();
    permute(str, 0, n - 1);
    return 0;
}

void permute(string str, int l, int r) {
    if (l == r)
        cout << str << endl;
    else {
        for (int i = l; i <= r; i++) {
            str = swap(str, l, i);
            permute(str, l + 1, r);
            str = swap(str, l, i); // Backtracking
        }
    }
}

string swap(string a, int i, int j) {
    char temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    return a;
}
