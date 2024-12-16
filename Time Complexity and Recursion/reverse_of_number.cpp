//Write a program to find the reverse of a number using recursion.
#include <iostream>
using namespace std;

// Recursive function to find the reverse of a number
int reverse(int n, int rev = 0) {
    // Base case: if the number becomes 0, return the reversed number
    if (n == 0)
        return rev;
    else
        return reverse(n / 10, rev * 10 + n % 10);
}

int main() {
    int n;

    // Input the number
    cin >> n;

    // Output the reversed number
    cout << reverse(n) << endl;

    return 0;
}
