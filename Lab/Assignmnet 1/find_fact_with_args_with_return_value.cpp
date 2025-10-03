#include<iostream>
using namespace std;
int findFactorial(int num) {
    int factorial = 1;
    for(int i = 1; i <= num; i++)
        factorial *= i;
    return factorial;
}
int main() {
    int num;
    cout << "Enter a number to find its factorial: ";
    cin >> num;
    cout << "Factorial of " << num << " is: " << findFactorial(num) << endl;
    return 0;
}

