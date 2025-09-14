#include <bits/stdc++.h>
using namespace std;

void linear_search(int arr[],int n){
    int key;
    cout << "Enter value : ";
    cin >> key;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == key){
            cout << "Value found at " << i << endl;
            return;
        }
    }
    cout << "Value not found \n";
    return;
}

void binary_search(int arr[],int n){
    int key;
    cout << "Enter value : ";
    cin >> key;
    int left=0,right=n-1;
    while (left <= right){
        int mid = (left+right) / 2;
        if(arr[mid] < key)
            left=mid+1;
        else if (arr[mid] > key)
            right=mid-1;
        else if (arr[mid] == key){
            cout << "Element found at " << mid <<endl;
            return;
        }
    }
    cout << "Element not found  " <<endl;
    return;
}

void bubble_sort(int arr[],int n){
    bool swapped;
    for(int i = 0; i < n-1; i++){
        swapped=false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped=true;
            }
        }
        if(!swapped) break;
    }
}

void selection_sort(int arr[],int n){
    for(int i = 0 ; i < n ; i ++){
        int minIndex=i;
        for(int j=i+1; j < n; j ++){
            if(arr[minIndex] > arr[j]){
                minIndex = j ;
            }
        }
        if(minIndex != i)   swap(arr[minIndex],arr[i]);
    }
}

void insertion_sort(int arr[],int n){
    for(int i = 0 ; i < n ; i ++){
        int key = arr[i],j;
        for(j = i-1; j>=0 && arr[j] > key; j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
}

void display(int arr[],int n){
    for(int i =0; i < n ; i ++)
        cout << i <<". " << arr[i] <<endl;
}

int main(){
    int n;
    cout << "Enter size : ";
    cin >>n;
    int arr[n];
    cout << "Enter value : \n";
    for(int i=0;i<n;i++){
        cout << i <<".";
        cin >> arr[i];
    }
    int ch;
    while(1){
    cout << "1.Linear Search\n2.Binary Search\n3.Bubble Sort\n4.Selection Sort\n5.Insertion Sort\n6.Display\nEnter choice : ";
    cin >> ch;
    switch(ch){
        case 1:
            linear_search(arr,n);
            break;
        case 2:
            binary_search(arr,n);
            break;
        case 3:
            bubble_sort(arr,n);
            break;
        case 4:
            selection_sort(arr,n);
            break;
        case 5:
            insertion_sort(arr,n);
            break;
        case 6:
            display(arr,n);
            break;
        default:
            break;
    }
}
}