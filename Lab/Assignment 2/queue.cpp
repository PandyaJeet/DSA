#include <iostream>
using namespace std;
#define MAX 10
int FRONT = -1 , REAR = -1 ,ELE,Q[MAX];
void insertion(){
    if (REAR == MAX){
        cout << "Queue is full\n";
        return;
    }
    else {
        cout << "Enter value to insert at index " << REAR << ": ";
        cin >> ELE;
        REAR ++ ;
        Q[REAR] = ELE;
        if (FRONT == -1 ){
            FRONT = 0;
        }
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
        if (FRONT == REAR ){
            FRONT = -1;
            REAR = -1;
        }
        else {
            FRONT ++;
        }
        cout << "Deleted element: " << ELE << " at index: " << FRONT << endl;
        return;
    }
}
void display(){
    if ( FRONT == -1 ){
        cout << "Queue is empty\n";
        return;
    }
    else {
        for (int i = FRONT; i <= REAR; i++)
            cout << Q[i] << " ";
        cout << endl;
        return;
    }
}
int main(){
    while (1){
        cout << "1. Insertion\n2. Deletion\n3. Display\n4. Exit\n";
        int choice;
        cin >> choice;
        switch (choice) {
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
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}