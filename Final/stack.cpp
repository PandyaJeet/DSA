#include <iostream>
using namespace std;
#define MAX 5
int TOP = -1,arr[MAX];

void push(){
    int ele;
    if (TOP == MAX-1){
        cout << "Stack Overflow";
        return ;
    }
    cout << "Enter element to push : ";
    cin >> ele;
    arr[++TOP]=ele;
    cout << "Inserted " << arr[TOP] << " at " << TOP <<endl;
    return;

}
void pop (){
    if (TOP==-1){
        cout << "Stack Underflow";
        return; 
    }
    cout << "Deleted " << arr[TOP--] << " at " << TOP+1 <<endl;
}
void peep(){
    int pos;
    cout << "Enter position : ";
    cin >> pos;
    if (TOP - pos + 1 <= 0){
        cout << "Enter valid position " << endl;
        return;
    }
    cout << "Element at "<<pos<< " is " << arr[TOP-pos+1] <<endl;
}
void change(){
    int pos;
    cout << "Enter position : ";
    cin >> pos;
    if (TOP - pos + 1 <= 0){
        cout << "Enter valid position " << endl;
        return;
    }
    int ele;
    cout << "Enter element : ";
    cin >> ele;
    arr[TOP - pos +1 ] = ele;
    cout << "Element at " << pos << " is " << arr[TOP-pos+1]<<endl;  
}
void display(){
    for(int i = 0 ; i <= TOP ; i++){
        cout << i <<". " << arr[i] <<endl;
    }
}
int main(){
    int ch;
    cout << "Push\nPOP\nPEEP\nCHANGE\nCHOICE : ";
    cin >> ch;
    switch (ch){
        case 1:
            push();
            main();
            break;
        case 2:
            pop();
            main();
            break;
        case 3:
            peep();
            main();
            break;
        case 4:
            change();
            main();
            break;
        case 5:
            display();
            main();
            break;
        default:
            return 0;
    }
}