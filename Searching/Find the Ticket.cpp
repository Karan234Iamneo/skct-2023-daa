#include <iostream>
using namespace std;

int main() {
    int a[100], search, n;

    // Input the number of elements
    cin >> n;

    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Input the number to search
    cin >> search;

    // Search for the number in the array
    for (int i = 0; i < n; i++) {
        if (a[i] == search) {
            cout << "The ticket number " << search << " is found at position " << i + 1 << endl;
            cout << "Congratulations! You have won the lottery." << endl;
            return 0; // Exit the program
        }
    }

    // If the number is not found
    cout << "Sorry, the ticket number " << search << " is not there. Better luck next time!" << endl;

    return 0;
}
