//Write a program to compute GCD of 2 numbers using recursion.
#include <iostream>
using namespace std;

// Recursive function to calculate GCD (HCF)
int hcf(int n1, int n2) {
    if (n2 != 0)
        return hcf(n2, n1 % n2);
    else
        return n1;
}

int main() {
    int n1, n2;

    // Input two numbers
    cin >> n1 >> n2;

    // Compute GCD
    int result = hcf(n1, n2);

    // Output the result
    cout << "G.C.D of " << n1 << " and " << n2 << " is " << result << endl;

    return 0;
}
