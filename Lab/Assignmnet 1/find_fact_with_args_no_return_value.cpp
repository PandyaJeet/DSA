#include<iostream>
using namespace std;
void findFactorial(int num) {
    int factorial = 1;
    for(int i = 1; i <= num; i++)
        factorial *= i;
    cout << "Factorial of " << num << " is: " << factorial << endl;
}
int main() {
    int num;
    cout << "Enter a number to find its factorial: ";
    cin >> num;
    findFactorial(num);
    return 0;
}

