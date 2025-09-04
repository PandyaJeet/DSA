#include <iostream>
using namespace std;
void bubble_sort(){
	bool swapped;
	for (int i = 0 ; i < n ; i ++){
		swapped=false;
		for(int j = i ; j < n - i - 1; j ++){
			if(arr[j] > arr[j+1]){
				swap(arr[j],arr[j+1]);
				swapped=true;
			}
		}	
		if(!swapped) break;
	}
}
void selection_sort(){
	for(int i = 0 ; i < n-1 ; i ++){
		int minIndex = i;
		for(int j = i+1 ; j < n ; j ++){
			if(arr[minIndex] > arr[j]){
				minIndex=j;
			}
		}
		swap(arr[i],arr[minIndex]);
	}
}