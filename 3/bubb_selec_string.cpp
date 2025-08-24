#include <iostream>
using namespace std;
void bubble_sort(string arr[],int n){
    bool swapped;
    for (int i = 0 ; i< n-1 ; i ++ ){
        swapped = false;
        for (int j = 0 ; j < n - i - 1 ; j ++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
void selection_sort(string arr[],int n){
    int minIndex;
    for(int i = 0 ; i < n - 1 ; i ++){
        minIndex = i;
        for(int j = i + 1 ; j < n ; j ++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}
void display(string arr[],int n){
    cout << "City Names in Sorted Order: \n";
    for (int i = 0; i < n; i++) {
        cout << (i+1) << " : " << arr[i] << endl;
    }
}
void assign(string arr[],int n){
    cout << "Enter the City Names : \n";
    for (int i = 0 ; i< n ; i++){
        cout << (i+1) << " : ";
        cin >> arr[i];
    }
}
int main(){
    int n;
    cout << "Enter size of the string : ";
    cin >> n;
    string arr[n];
    assign(arr, n);

    display(arr,n);
}