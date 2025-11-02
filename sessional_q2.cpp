#include <iostream>
using namespace std;
int length(char arr[]){
    int len = 0;
    while(arr[len] != '\0'){
        len++;
    }
    return len;
}
void sorting(){
    
}
int main(){
    char arr[100];
    cout << "Enter string : ";
    cin >> arr;
    cout << "String : " <<endl;
    int len = length(arr);
    sorting();

    for(int i = 0 ; i < len ; i ++ )
        cout << arr[i] << endl;
}