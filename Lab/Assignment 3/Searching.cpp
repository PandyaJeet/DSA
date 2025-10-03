
#include <bits/stdc++.h>
using namespace std;
void bubble_sort(int a[],int n){
    bool swapped;
    for (int i = 0 ; i < n-1 ; i++){
        swapped = false;
        for (int j = 0 ; j < n-i-1 ; j++){
            if (a[j] > a[j+1]){
                swap(a[j], a[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
void linearsearch(int a[], int n)
{
    bubble_sort(a, n);
    cout << "Enter element to search : ";
    int key;
    cin >> key;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            cout << "Element is present "  << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
}

void binarysearch(int a[], int n)
{
    bubble_sort(a, n);
    int low, high, key;
    cout << "Enter element to search : ";
    cin >> key;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (a[mid] == key)
        {
            cout << "Element is present " << endl;
            return;
        }
        else if (a[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "Element not found" << endl;
}
int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    int a[n];
    cout << "Enter " << n << " elements for the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Press 1 for linear search\nPress 2 for binary search\nChoice:";
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
        linearsearch(a, n);
        break;
    case 2:
        binarysearch(a, n);
        break;
    default:
        break;
    }
}