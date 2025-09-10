#include <iostream>
using namespace std;
void binary_search(int arr[],int n){
	int key;
	cout << "Enter element to search : ";
	cin >>key;
	int low=0,high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid] > key) 
			high = mid-1;
		else if (arr[mid] < key)
			low = mid+1;
		else if (arr[mid] == key){
			cout << "Element was found at " << mid <<endl;
			return ;
		}
	}
	cout << "Element was not present" <<endl;
}
void input(int arr[],int n){
	cout << "Enter elements \n";
	for(int i = 0 ; i < n ; i ++){
		cout << i<<". ";
		cin>>arr[i];
	}
}
int main(){
	int n;
	cout <<"Enter size of array : ";
	cin >>n;
	int arr[n];
	input(arr,n);
	binary_search(arr,n);
}