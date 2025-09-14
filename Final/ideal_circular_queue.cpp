#include <iostream>
using namespace std;
#define MAX 5

int arr[MAX], ele, FRONT = -1, REAR = -1;

void insert() {
    if ((FRONT == 0 && REAR == MAX - 1) || 
        (REAR + 1) % MAX == FRONT) {
        cout << "Queue is full\n";
        return;
    }
    cout << "Enter element: ";
    cin >> ele;
    if (FRONT == -1) {
        FRONT = REAR = 0;
    } else {
        REAR = (REAR + 1) % MAX;
    }
    arr[REAR] = ele;
}

void delet() {
    if (FRONT == -1) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Element removed: " << arr[FRONT] << endl;
    if (FRONT == REAR) {
        FRONT = REAR = -1;
    } else {
        FRONT = (FRONT + 1) % MAX;
    }
}

void display() {
    if (FRONT == -1) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue elements:\n";
    int i = FRONT;
    while (true) {
        cout << i << ". " << arr[i] << endl;
        if (i == REAR) break;
        i = (i + 1) % MAX;
    }
}

int main() {
    int ch;
    while (true) {
        cout << "\n1. Insert\n2. Delete\n3. Display\n4. Exit\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                delet();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
}