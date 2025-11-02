#include<iostream>
using namespace std;
int main()
{
	int i,n;
	int a[20];
	int ele,flag=0;
	int low,mid,high;

	//Input
	cout<<"\nENTER THE SIZE OF THE ARRAY : ";
	cin>>n;
	cout<<"\nENTER THE ARRAY ELEMENTS : ";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"\nENTER THE SEARCHING ELEMENT : ";
	cin>>ele;
	
	//Logic
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(ele==a[mid])
		{
			flag=1;
			break;
		}
		else
			if(ele<a[mid])
				high=mid-1;
			else
				low=mid+1;
	}
	if(flag==0)
		cout<<"\nELEMENT IS NOT PRESENT";
	else
		cout<<"\nELEMENT IS PRESENT";
	return 0;
}
		
		
		
		
	
	
	
	
	
