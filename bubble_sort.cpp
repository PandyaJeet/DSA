#include <iostream>
using namespace std;
void bubble_sort(int arr[], int n){
    bool swapped;
    for (int i = 0 ; i < n - 1 ; i++){
        swapped = false;
        for(int j = 0 ; j < n - i - 1; j ++){
            if(arr[j]> arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(!swapped) break;
    }
}
int main(){
    int n;
    cout<< "Enter size of the array : ";
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i ++){
        cout << i << " : ";
        cin >> arr[i];
    }
    bubble_sort(arr, n);
    for(int i = 0 ; i < n ; i ++){
        cout << arr[i] << " ";
    }
}