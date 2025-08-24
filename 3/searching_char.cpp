#include <iostream>
using namespace std;
int n;
void bubble_sort(char arr[])
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
void linear_search(char arr[], int n, char key)
{
    bubble_sort(arr);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at index " << i;
            return;
        }
    }
    cout << "Element wasn't found at any index";
}
void binary_search(char arr[], int n, char key)
{
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
            cout << "Data found at index " << mid;
            return;
        }
    }
    cout << "Data not found\n";
}
void size(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value for index " << i << " : ";
        cin >> arr[i];
    }
}
int length(char arr[])
{
    int count = 0;
    while (arr[count] != '\0')
    {
        count++;
    }
    return count;
}

int main()
{
    int ch;
    char arr[100], key;
    cout << "Enter value in character : ";
    cin >> arr;
    n = length(arr);
    cout << "Enter value of key : ";
    cin >> key;
    cout << "Press 1 for Linear Search \nPress 2 for Binary Search\n";
    cin >> ch;
    switch (ch)
    {
    case 1:
        linear_search(arr, n, key);
        break;
    case 2:
        binary_search(arr, n, key);
        break;
    }
}