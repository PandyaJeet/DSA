#include<iostream>
using namespace std;
int main() {
    int n, sum = 0;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
	cout << "Sum: " << sum << endl;
    cout << "Average: " << sum / n << endl; 
    return 0;
}

