#include <bits/stdc++.h>
using namespace std;
void bubble_sort(int arr[],int n){
    bool swapped;
    for(int i=0;i<n-1;i++){
        swapped = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}
void selection_sort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex])
                minIndex=j;
        }
        swap(arr[i],arr[minIndex]);
    }
}
void assign_value(int arr[],int n){
    cout << "Enter the elements: "<<endl;
    for(int i=0;i<n;i++){
        cout <<  (i+1) << ". ";
        cin>>arr[i];
    }
        
}
void display(int arr[], int n){
    cout << "Final Array : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main(){
    int n,ch;
    cout << "Enter the size of Array : ";
    cin >> n;
    int arr[n];
    assign_value(arr, n);
    cout << "1.Bubble Sort" << endl<<"2.Selection Sort" << endl;
    cin >> ch;
    if(ch==1)
        bubble_sort(arr, n);
    else if(ch==2)
        selection_sort(arr, n);
    display(arr, n);
    return 0;
}