#include <iostream>
using namespace std;
void binary_search(int arr[],int n){
    int key;
    cout << "Enter value of key : ";
    cin >> key;
    int left = 0 , right = n-1;
    while(left <= right){
        int mid = (left+right) / 2;
        if(arr[mid ] > key)
            right = mid - 1;
        else if (arr[mid ] < key)
            left = mid + 1;
        else if (arr[mid ] == key){
            cout << "Element found at index " << mid << endl;
            return;
        }
    }
    cout << "Element not found" << endl;
    return;
}
int main(){
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cout << "Enter element " << i << " : ";
        cin >> arr[i];
    }
    binary_search(arr, n);
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
}