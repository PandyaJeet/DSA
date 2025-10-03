#include<iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int a[n];
    bool isDuplicate;

    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Array without duplicates: ";
    for(int i = 0; i < n; i++) {
        isDuplicate = false;
        for(int j = 0; j < i; j++) {
            if(a[i] == a[j]) {
                isDuplicate = true;
                break;
            }
        }

        if(!isDuplicate) {
            cout << a[i] << " ";
        }
    }
    return 0;
}

