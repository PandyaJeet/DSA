#include <iostream>
using namespace std;
int main()
{
    int n, count = 0;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Odd elements: ";
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 != 0)
        {
            cout << a[i] << " ";
            count++;
        }
    }
    cout << "\nNumber of odd elements: " << count << endl;
    return 0;
}
