#include <iostream>
#include <malloc.h>
using namespace std;
struct Linked{
    int data;
    struct Linked* next;
}*node, *head, *last, *temp;

void create_at_begin(){
    node = (struct Linked*) malloc (sizeof(struct Linked));
    cout << "Enter data : ";
    cin >> node->data;
    node->next=NULL;
    if (head == NULL)
        head = last = node;
    else{
        node->next = head;
        head=node;
    }
}
void create_at_last(){
    node = (struct Linked*) malloc (sizeof(struct Linked));
    cout << "Enter data : ";
    cin >> node->data;
    node->next = NULL;
    if(head == NULL) 
        head=last=node;
    else {
        last->next=node;
        last=node;
    }
}
int counti(){
   int count=0; 
    temp=head;
    while (temp != NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
void create_at_mid(){
    int count, pos;
    cout << "Enter position : ";
    cin >> pos;
    count=counti();
    if(pos == 0) {
        create_at_begin();
        return;
    }
    else if ( pos == count  ){
        create_at_last();
        return;
    }
    else if (pos > 0 && pos < count){
        node=(struct Linked*) malloc (sizeof(struct Linked));
        cout << "Enter data : ";
        cin >> node->data;
        node->next=NULL;
        temp=head;
        for(int i = 1 ; i < pos; i++){
            temp=temp->next;
        }
        node->next=temp->next;
        temp->next=node;
    }
    else 
        cout << "Invalid Position \n";
}

void delete_at_begin(){
    if(head == NULL){
        cout << "List is empty\n";
        return;
    }

    temp=head;
    head=head->next;
    free(temp);
    if(head == NULL) last = NULL;
}

void delete_at_end(){
    if(head == NULL){
        cout << "List is empty\n";
        return;
    }

    if(head->next == NULL){ 
        free(head);
        head = last = NULL;
        return;
    }

    temp = head;
    while(temp->next != last){
        temp = temp->next;
    }

    free(last);
    last = temp;
    last->next = NULL;
}

void delete_at_mid (){
    int pos,count;
    cout << "Enter position : ";
    cin >> pos;
    count = counti();
    if (pos == 1){
        delete_at_begin();
        return;
    }
    else if (pos == count ){
        delete_at_end();
        return;
    }
    else if (pos >1 && pos <count){
        struct Linked*tem;
        temp=head;
        for(int i = 1; i < pos-1 ; i ++){
            temp=temp->next;
        }
        tem=temp->next;
        temp->next=temp->next->next;
        free(tem);
    }
}
void display(){
    temp = head;
    while ( temp != NULL){
        cout << "Data is " << temp->data <<endl;
        temp=temp->next;
    }
}

int main() {
    int choice;

    while (1) {
        cout << "\n\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Middle\n";
        cout << "4. Delete at Beginning\n";
        cout << "5. Delete at End\n";
        cout << "6. Delete at Middle\n";
        cout << "7. Display List\n";
        cout << "8. Count Nodes\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                create_at_begin();
                break;
            case 2:
                create_at_last();
                break;
            case 3:
                create_at_mid();
                break;
            case 4:
                delete_at_begin();
                break;
            case 5:
                delete_at_end();
                break;
            case 6:
                delete_at_mid();
                break;
            case 7:
                display();
                break;
            case 8:
                cout << "Total Nodes: " << counti() << endl;
                break;
            case 9:
                cout << "Exiting program.\n";
                exit(0);
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
