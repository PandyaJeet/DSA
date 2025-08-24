#include <bits/stdc++.h>
using namespace std;
int size = 0;
bool swapped;
void assing_value(int arr[], int n);
void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}
void merge_sort(int arr1[], int arr2[], int arr[], int n1, int n2)
{
    bubble_sort(arr1, n1);
    bubble_sort(arr2, n2);
    int j = 0, i = 0;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
            arr[size++] = arr1[i++];
        else if (arr2[j] < arr1[i])
            arr[size++] = arr2[j++];
        else if (arr1[i] == arr2[j])
        {
            arr[size++] = arr1[i++];
            j++;
        }
    }
    while (i < n1)
        arr[size++] = arr1[i++];
    while (j < n2)
        arr[size++] = arr2[j++];
}

void assign_value(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}
void display(int arr[])
{
    int i = 0;
    cout << "Final Array : ";
    while (i < size)
        cout << arr[i++] << " ";
}
int main()
{
    int n1, n2;
    cout << "Enter size of first array : ";
    cin >> n1;
    cout << "Enter size of second array : ";
    cin >> n2;
    int arr1[n1], arr2[n2], arr[n1 + n2];
    cout << "Enter values for first array" << endl;
    assign_value(arr1, n1);
    cout << "Enter value for second array " << endl;
    assign_value(arr2, n2);
    merge_sort(arr1, arr2, arr, n1, n2);
    display(arr);
    return 0;
}
