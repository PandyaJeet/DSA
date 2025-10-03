#include <iostream>
using namespace std;
struct dblink{
    int data;
    struct dblink *next,*prev;   
}*node,*head,*last,*temp;
int count;
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

void counti(){
    temp = head;
    count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
}

void create_at_mid(){
    int pos;
    cout << "Enter position : ";
    cin >> pos;
    counti();
    if(pos == 0){
        create_at_begin();
        return;
    }
    else if (pos == count){
        create_at_last();
        return;
    }
    else if(pos > count){
        cout << "Invalid position\n";
        return;
    }
    else{
        node = (struct dblink*) malloc (sizeof(struct dblink));
        cout << "Enter data : ";
        cin >> node->data;
        node->next = node->prev = NULL;
        temp = head;
        for(int i=0; i<pos-1; i++)
                temp = temp->next;
        node->next=temp->next;
        temp->next->prev=node;
        temp->next=node;
        node->prev=temp;
}
}

void delete_at_begin(){
    temp=head;
    head->next->prev=NULL;
    head=head->next;
    free(temp);
}

void delete_at_last(){
    temp=last;
    last->prev->next=NULL;
    last=last->prev;
    free(temp);
}

void delete_at_mid(){
    int pos;
    cout << "Enter position : ";
    cin >> pos;
    counti();
    if(pos == 0 ){
        delete_at_begin();
        return;
    }
    else if (pos == count-1){
        delete_at_last();
        return;
    }
    else if(pos >= count){
        cout << "Invalid position\n";
        return;
    }
    else{
        temp = head;
        for(int i=0; i<pos; i++)
            temp = temp->next;
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }
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
        cout << "1. Create at begin\n2. Create at last\n3. Create at mid\n4. Delete at begin\n5. Delete at last\n6. Delete at mid\n7. Display\n8. Exit\nEnter your choice : ";
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
                create_at_mid();
                break;
            case 4:
                delete_at_begin();
                break;
            case 5:
                delete_at_last();
                break;
            case 6:
                delete_at_mid();
                break;  
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                cout << "Invalid choice\n";
                break;
    }
}
}
