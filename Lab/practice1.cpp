#include <iostream>
using namespace std;
#define MAX 10
int S[MAX],TOP=-1;
void push(){
    if(TOP == (MAX-1)){
        cout << "Stack Overflow" <<endl;
        return;
    }
    int ele;
    cout << "Enter data : ";
    cin >> ele;
    S[++TOP] = ele;
    cout << "Added " <<S[TOP-1] << " at " << TOP-1;
}
void pop(){
    if(TOP==-1){
        cout << "Stack Underflow" <<endl;
        return;
    }
    S[TOP--];
    cout << "Element delete\n";
}
void peep (){
    int pos;
    cout << "Enter position : ";
    cin >> pos;
    if ((TOP-pos+1) < 0){
        cout << "Invalid position " <<endl;
        return;
    }
    cout << "Data is " << S[TOP-pos+1] <<endl;
}
void change (){
    int pos,ele;
    cout << "Enter pos : ";
    cin >> pos;
    cout << "Enter key : ";
    cin >> ele;
    S[TOP-pos+1] = ele;
    cout << "Element added" <<endl;

}
int main(){

}