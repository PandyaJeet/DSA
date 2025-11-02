#include <iostream>
using namespace std;
int main()
{
	int a[20], b[20];
	int m, n, i, j, c[20], k = 0, p;
	cout << "\nENTER THE SIZE OF THE ARRAY 1 : ";
	cin >> n;
	for (i = 0; i <= n - 1; i++)
	{
		cin >> a[i];
	}

	cout << "\nENTER THE SIZE OF THE ARRAY 2 : ";
	cin >> m;
	for (j = 0; j <= m - 1; j++)
	{
		cin >> b[j];
	}
	i = 0;
	j = 0;
	while (i <= n - 1 && j <= m - 1)
	{
		if (a[i] < b[j])
		{
			c[k] = a[i];
			k++;
			i++;
		}
		else
		{
			c[k] = b[j];
			k++;
			j++;
		}
	}
	if (i == n)
	{
		for (p = j; p <= m - 1; p++)
		{
			c[k] = b[p];
			k++;
		}
	}
	else if (j == m)
	{
		for (p = i; p <= n - 1; p++)
		{
			c[k] = a[p];
			k++;
		}
	}

	cout << "\nIN SORTED ARRAY : ";
	for (i = 0; i < k; i++)
	{
		cout << "  " << c[i];
	}
}
