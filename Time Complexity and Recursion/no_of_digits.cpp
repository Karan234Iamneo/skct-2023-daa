//Write a program to find the number of digits in a number using recursion.
#include <iostream>
using namespace std;

// Recursive function to count the number of digits
int add(int n) {
    if (n == 0)
        return 0;
    else
        return 1 + add(n / 10);
}

int main() {
    int n;

    // Input the number
    cin >> n;

    // Output the result
    cout << "The number of digits in " << n << " is " << add(n) << endl;

    return 0;
}
