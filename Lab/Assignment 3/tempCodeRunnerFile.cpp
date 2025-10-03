#include <bits/stdc++.h>
using namespace std;
int n;
void bubble_sort(char arr[])
{
    bool swapped;
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
void selection_search(char arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i; j < n ; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}
void arraysize(char arr[])
{
    int i = 0;
    while (arr[i++] != '\0')
        n++;
}
void display(char arr[])
{
    cout << "Sorted Array : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    int ch;
    char arr[100];
    cout << "Enter string : ";
    cin >> arr;
    arraysize(arr);
    cout << "1.Bubble Sort" << endl << "2.Selection Sort" << endl;
    cin >> ch;
    if (ch == 1)
        bubble_sort(arr);
    else
        selection_search(arr);
    display(arr);
}