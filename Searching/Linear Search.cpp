#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int x;
    cin >> x;

    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            cout << x << " is present" << endl;
            return 0; // Exit the program
        }
    }

    cout << x << " is not present" << endl;
    return 0;
}
