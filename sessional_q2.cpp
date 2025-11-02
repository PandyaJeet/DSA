#include <iostream>
using namespace std;
int length(char arr[]){
    int len = 0;
    while(arr[len] != '\0'){
        len++;
    }
    return len;
}
void bubble_sort(char arr[],int n){
    bool swapped;
    for(int i = 0 ; i < n-1; i ++){
        swapped = false;
        for(int j = 0 ; j < n - i - 1 ; j ++){
            if (arr[j] > arr[j+1]){
                swap(arr[i] , arr[j]);  
                swapped = true;
            }
        }
        if(!swapped) 
        break;
    }   
}
void selection_sort(char arr[],int n ){
    int minIndex;
    for(int i =0;i<n;i++){
        minIndex=i;
        for(int j = i+1;j<n;j++){
            if(arr[j] < arr[minIndex])
            minIndex=j;
        }
        if(minIndex!=i) swap(arr[i],arr[minIndex]);
    }
}
void binary_search
int main(){
    char arr[100];
    cout << "Enter string : ";
    cin >> arr;
    cout << "String : " <<endl;
    int len = length(arr);
    selection_sort(arr,len);
    bubble_sort(arr,len);
    for(int i = 0 ; i < len ; i ++ )
        cout << arr[i] << endl;
}