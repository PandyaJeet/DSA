#include <iostream>
using namespace std;
struct dblink{
    int data;
    struct dblink *next,*prev;   
}*node,*head,*last,*temp;

void create_at_begin(){
    node = (struct dblink*)malloc(sizeof(struct dblink));
    cout << "Enter data : ";
    cin >> node->data;
    node->next = node->prev= NULL;
    if(head == NULL)
        head = last = node;
    else{
        node->next = head;
        head->prev = node;
        head = node;
    }
}

void create_at_last(){
    node = (struct dblink*)malloc(sizeof(struct dblink));
    cout << "Enter data : ";
    cin >> node->data;
    node->next = node->prev= NULL;
    if(head == NULL)
        head = last = node;
    else{
        last->next = node;
        node->prev = last;
        last = node;
    }
}

void create_at_mid(){
    int pos;
    cout << "Enter position : ";
    cin >> pos;
}
void display(){
    temp = head;
    while(temp != NULL){
        cout << "Data is " << temp->data << endl;
        temp = temp->next;
    }
}

int main(){
    while (1){
        cout << "1. Create at begin\n2. Create at last\n3. Display\n4. Exit\nEnter your choice : ";
        int choice;
        cin >> choice;
        switch (choice){
            case 1:
                create_at_begin();
                break;
            case 2:
                create_at_last();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice\n";
                break;
    }
}
}
