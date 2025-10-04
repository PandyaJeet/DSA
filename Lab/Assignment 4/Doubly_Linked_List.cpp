#include <iostream>
#include <malloc.h>

using namespace std;

int count = -1;

struct Double_Linkedlist{
    int data;
    struct Double_Linkedlist * next;
    struct Double_Linkedlist * prev;
}*node,*head,*last,*temp;

void display(){
    temp=head;
    int i = -1;
    while(temp!=NULL){
        i++;
        cout <<endl << "------" << i << "-----" << endl;
        cout << "Data is : " << temp->data;
        cout << endl << "------------" <<endl;
        temp=temp->next;
    }
}
void counti(){
    temp=head;
    count=-1;
    while(temp!=NULL ){
        count++;
        temp=temp->next;
    }
}
void create_at_begin(){
    node=(struct Double_Linkedlist*) malloc (sizeof(struct Double_Linkedlist));
    cout << "Enter data : ";
    cin >> node->data;
    node->next = node->prev = NULL;
    if ( head == NULL )
        head = last = node;
    else{
        node->next = head;
        head->prev=node;
        head=node;
    }
}

void create_at_last(){
    node=(struct Double_Linkedlist* ) malloc (sizeof(struct Double_Linkedlist));
    cout << "Enter data : ";
    cin >> node->data;
    node->prev=node->next=NULL;
    if (head == NULL)
        head=last=node;
    else{
        last->next=node;
        node->prev=last;
        last=node;
    }
}

void create_at_position(){
    int pos;
    cout << "Enter position : ";
    cin >> pos;
    counti();
    if(pos == 0 ){
        create_at_begin();
        return;
    }
    else if (pos == count){
        create_at_last();
        return;
    }
    else if (pos > 0 && pos < count){
        node=(struct Double_Linkedlist* ) malloc (sizeof(struct Double_Linkedlist));
        cout << "Enter data : ";
        cin >> node->data;
        node->next=node->prev=NULL;
        if(head==NULL)
            head=last=NULL;
        else{
            temp=head;
            for(int i = 0 ; i < pos - 1 ; i ++){
                temp=temp->next;
            }
            node->next=temp->next;
            node->prev=temp;
            temp->next->prev = node;
            temp->next=node;
        }
    }
}



int main(){
    
        int choice;
    head = last = NULL;
    
    while(1){
        cout << "\n1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                create_at_begin();
                break;
            case 2:
                create_at_last();
                break;
            case 3:
                create_at_position();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    

    }
