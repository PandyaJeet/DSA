#include <iostream>
using namespace std;
#define MAX 5
int arr[MAX], ele, FRONT = -1, REAR = -1;
void insert()
{
    if (REAR == MAX - 1)
    {
        cout << "Queue is full \n";
        return;
    }
    cout << "Enter element : ";
    cin >> ele;
    arr[++REAR] = ele;
    if (FRONT == -1)
        FRONT++;
}
void delet()
{
    if (FRONT == -1)
    {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Element removed " << arr[FRONT] << endl;
    if (FRONT == REAR)
        FRONT = REAR = -1;
    else
        FRONT++;
}
void display()
{
    if (FRONT == -1 && REAR == -1)
    {
        cout << "Queue is empty \n";
        return;
    }
    for (int i = FRONT; i <= REAR; i++)
    {
        cout << i << ". " << arr[i] << endl;
    }
}
int main()
{
    int ch;
    while (true) {
        cout << "1.Insert\n2.Delete\n3.Display\n4.Exit\nChoice : ";
        cin >> ch;
        switch (ch)
        {
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
