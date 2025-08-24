#include <iostream>
using namespace std;
#define MAX 5
int FRONT = -1 , REAR = -1 ;
int Q[MAX],ELE;
void insertion(){
    if ((FRONT == 0 && REAR == MAX - 1) || (FRONT == REAR + 1)) {
        cout << "Queue is full\n";
        return;
    }
    else {  
        cout << "Enter value to add : " ;
        cin >> ELE;
        if (REAR == MAX - 1)
            REAR=0; 
        else if (REAR == -1 )
            FRONT = REAR = 0;
        else
            REAR++;
        Q[REAR] = ELE;
            return;
    }
}
void deletion(){
    if (FRONT == -1 ){
        cout << "Queue is empty\n";
        return;
    }
    else {
        ELE = Q[FRONT];
        Q[FRONT] = -2 ;
        if (FRONT == REAR ){
            FRONT = REAR = -1;
        }
        else if (FRONT == MAX -1 )
            FRONT = 0;
        else
            FRONT++;
        cout << "Deleted element: " << ELE << " at index: " << FRONT << endl;
        return;
    }
}
void display(){
    for (int i = 0; i< MAX ; i++){
        if (Q[i] == -2)
            cout << "__ ";
        else
            cout << Q[i] << " ";
    }
    cout << endl;
}
int main(){
    while (1){
        cout << "1. Insertion\n2. Deletion\n3. Display\n4. Exit\n";
        int ch;
        cin >> ch;
        switch (ch) {
            case 1:
                insertion();
                break;
            case 2:
                deletion();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}