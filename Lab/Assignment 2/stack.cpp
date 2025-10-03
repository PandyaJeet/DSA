#include <iostream>
using namespace std;
#define MAX 5
int TOP = -1 ,s[MAX], POS, ELE;
void push(){
    if (TOP == MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    else{
        TOP++;
        cout << "Enter the element to push: ";
        cin >> s[TOP];
        cout << "Element pushed: " << s[TOP] << " at index: "<<TOP  << endl;
    }
}
void pop(){
    if (TOP == -1 ){
        cout << "Stack Underflow\n";
        return;
    }
    else {
        cout << "Element popped: " << s[TOP] << " from index: " << TOP << endl;
        TOP--;
    }
}
int peep(int POS){
    if ( TOP - POS +1 <= 0){
        cout << "Invalid position\n";
        return -1;
    }
    else {
        return s[TOP - POS + 1];
    }
}
void change(int POS){
    cout << "Enter element to change at position " << TOP - POS + 1 << ": ";
    cin >> ELE;
    if (TOP - POS + 1 <= 0) {
        cout << "Invalid position for change\n";
        return;
    }
    else {
        s[TOP - POS + 1] = ELE;
        cout << "Element at position " << TOP - POS + 1 << " changed to: " << ELE << endl;
    }
}
int main(){
    while(1){
        cout << "1. Push\n2. Pop\n3. Peep\n4. Change\n5. Exit\n";
        int ch;
        cin >> ch;
        switch(ch){
            case 1: push(); break;
            case 2: pop(); break;
            case 3:
                cout << "Enter position to peep ";
                cin >> POS;
                {
                int ans = peep(POS);
                if (ans == -1)
                    cout << "Pop operation failed.\n";
                else 
                    cout << "Element at postion " << POS << " is: " << ans << endl;
                }
                    break;
            case 4:
                cout << "Enter position to change : ";
                cin >> POS;
                change(POS);
                break;
            case 5: return 0; 
            default: cout << "Invalid choice, please try again.\n";
        }
    }
}