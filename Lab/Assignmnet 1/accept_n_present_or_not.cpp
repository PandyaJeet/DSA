#include<iostream>
using namespace std;
int main() {
    int n, search, found = 0;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter the element to search: ";
    cin >> search;
    for(int i = 0; i < n; i++) {
        if(a[i] == search) {
            found = 1;
            break;
        }
    }
    if(found)
        cout << "Element " << search << " is present in the array." << endl;
    else 
        cout << "Element " << search << " is not present in the array." << endl;
    return 0;
}

