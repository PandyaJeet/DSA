#include<iostream>
using namespace std;
void inputArray(int a[], int n);
void insertionSort(int a[], int n);
void printArray(int a[], int n);

int main() 
{
    int n;
    int a[15];
    cout<<"\nENTER THE SIZE OF THE ARRAY : ";
    cin>>n;
    inputArray(a, n);
    insertionSort(a, n);
    printArray(a, n);
    return 0;
}

void inputArray(int a[], int n) 
{
    cout<<"\nENTER THE ARRAY ELEMENTS : ";
    for(int i=0;i<n;i++) 
	{
        cin>>a[i];
    }
}

void insertionSort(int a[], int n) 
{
    for(int i=1;i<n;i++) 
	{
        int key=a[i];
        int j=i-1;
        while (j>=0 && a[j]>key)
		{
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void printArray(int a[], int n) 
{
    cout<<"\nSORTED ARRAY: ";
    for(int i=0;i<n;i++) 
	{
        cout<<"  "<<a[i];
    }
}
