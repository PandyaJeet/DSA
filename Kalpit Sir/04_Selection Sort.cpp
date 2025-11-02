#include<iostream>
using namespace std;
void inputArray(int a[], int n);
void selectionSort(int a[], int n);
void printArray(int a[], int n);

int main() 
{
    int n;
    int a[15];
    cout<<"\nENTER THE SIZE OF THE ARRAY : ";
    cin>>n;
    inputArray(a, n);
    selectionSort(a, n);
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

void selectionSort(int a[], int n) 
{
    for(int i=0;i<n-1;i++) 
	{
        int minIndex=i;
        for(int j=i+1;j<n;j++) 
		{
            if(a[j]<a[minIndex])
                minIndex = j;
        }
        int temp=a[i];
        a[i]=a[minIndex];
        a[minIndex]=temp;
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
