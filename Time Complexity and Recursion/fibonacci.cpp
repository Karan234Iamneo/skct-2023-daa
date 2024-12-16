//Write a program to generate nth Fibonacci term using recursion.
#include <iostream>
using namespace std;

// Recursive function to calculate Fibonacci numbers
unsigned long long fibo(int num) {
    if (num == 0)      
        return 0;
    else if (num == 1) 
        return 1;
    else 
        return fibo(num - 1) + fibo(num - 2);
}

int main() {
    int num;
    unsigned long long fibonacci;
    cin >> num;

    // Calculate Fibonacci
    fibonacci = fibo(num);

    // Output
    cout << fibonacci << endl;

    return 0;
}
