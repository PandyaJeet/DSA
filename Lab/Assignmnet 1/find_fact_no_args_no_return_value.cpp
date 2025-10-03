#include<iostream>
using namespace std;
void findFactorial() {
    int num, factorial = 1;
    cout << "Enter a number to find its factorial: ";
    cin >> num;
    for(int i = 1; i <= num; i++)
        factorial *= i;
    cout << "Factorial of " << num << " is: " << factorial << endl;
}
int main() {
    findFactorial();
    return 0;
}

