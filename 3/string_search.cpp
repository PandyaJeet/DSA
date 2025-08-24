#include <iostream>
using namespace std;
string key;
int n;
void bubble_sort(string arr[]);
void linear_search(string arr[])
{
    cout << "Enter value of key : ";
    cin >> key;
    bubble_sort(arr);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            //cout << "String i.e. " << arr[i] << " was found at index " << i;
            cout << "City is present" << endl;
            return;
        }
    }
    cout << "City is not present" << endl;
}
void binary_search(string arr[])
{
    cout << "Enter value of key : ";
    cin >> key;
    bubble_sort(arr);
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (right + left) / 2;
        if (arr[mid] > key)
            right = mid - 1;
        else if (arr[mid] < key)
            left = mid + 1;
        else if (arr[mid] == key)
        {
            cout << "City is present" << endl;
            return;
        }
    }
    cout << "City is not present" << endl;
}
void bubble_sort(string arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Sorted Data : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    cout << "Enter total number of cities : ";
    cin >> n;
    int ch;
    string arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter name of city in CAPS for index " << i << " : ";
        cin >> arr[i];
    }
    cout << "Press 1 for linear Search\nPress 2 for binary search\nEnter choice : ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        linear_search(arr);
        break;
    case 2:
        binary_search(arr);
        break;
    default:
        cout << "Invalid choice!!" << endl;
        main();
        break;
    }
}