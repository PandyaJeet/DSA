#include <iostream>
#include <malloc.h>

using namespace std;

int counto=-1;

struct Double_Linkedlist{
    int data;
    struct Double_Linkedlist * next;
    struct Double_Linkedlist * prev;
}*node,*head,*last,*temp , *t1;

void display(){
    temp=head;
    if(head == NULL){
        cout << "List is NULL ";
        return;
    }
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
    counto=-1;
    while(temp!=NULL ){
        counto++;
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
    else if (pos == counto){
        create_at_last();
        return;
    }
    else if (pos > 0 && pos < counto ) {
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

void delete_at_begin(){
    if (head == NULL ){
        cout << "List is empty \n" ; 
        return;
    }
    else if (head->next == NULL){
        free (head);
        head =last = NULL;
    }
    else {
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
}

void delete_at_last(){
    if (head == NULL ){
        cout << "List is empty \n" ; 
        return;
    }
    else if (head->next == NULL){
        free (head);
        head =last = NULL;
    }    
    else {
    temp=last;
    last=last->prev;
    last->next=NULL;
    free(temp);
    }
}

void delete_at_pos(){
    int pos;
    cout << "Enter position : ";
    cin >> pos;
    counti();
    if (pos == 0){
        delete_at_begin();
        return;
    }
    else if (pos == counto){
        delete_at_last();
        return;
    }
    else if (pos > 0 && pos < counto) {
        temp = head;
        for(int i = 0 ; i < pos -1 ; i++)
            temp=temp->next;
        t1 = temp->next;
        temp->next=temp->next->next;
        if(t1->next!=NULL)
            temp->next->prev = temp;
        free(t1);
    }
    else 
        cout << "Invalid Positon"<<endl;
}

int main(){
    
    int choice;
    head = last = NULL;
    
     while(1){
        cout << "\n1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert at position\n";
        cout << "4. Delete at beginning\n";
        cout << "5. Delete at end\n";
        cout << "6. Delete at position\n";
        cout << "7. Display\n";
        cout << "8. Count nodes\n";
        cout << "9. Exit\n";
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
                delete_at_begin();
                break;
            case 5:
                delete_at_last();
                break;
            case 6:
                delete_at_pos();
                break;
            case 7:
                display();
                break;
            case 8:
                counti();
                cout << "Total number of nodes : "<<counto<<endl;
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }    
}
