#include<iostream>
using namespace std;

int main () {
	int a[5],i;
	cout<<"Enter five Elements : ";
	for(i=0 ; i<5 ; i++) {
		cin>>a[i];
	}
	cout<<endl;
	for(i=4 ; i>=0 ; i--) {
		cout<<a[i]<<endl;
	}
}
