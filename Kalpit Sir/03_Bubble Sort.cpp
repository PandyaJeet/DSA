#include<iostream>
using namespace std;
void inputArray(int a[],int n);
void bubbleSort(int a[],int n);
void printArray(int a[],int n);
int main()
{
	int n;
	int a[15];
	cout<<"\nENTER THE SIZE OF THE ARRAY : ";
	cin>>n;
	inputArray(a,n);
	bubbleSort(a,n);
	printArray(a,n);
	return 0;
}
void inputArray(int a[],int n)
{
	int i;
	cout<<"\nENTER THE ARRAY ELEMENTS : ";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
void bubbleSort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)//PASS
	{
		for(j=0;j<n-i-1;j++)//Multiple time Comparision
		{
			if(a[j]>a[j+1])//Compare
			{
				temp=a[j];//Swapping
				a[j]=a[j+1];
				a[j+1]=temp;
			}			
		}
	}
}

void printArray(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<"  "<<a[i];
	}
}
	
	
	
	
