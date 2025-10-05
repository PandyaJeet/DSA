#include <iostream>
#include <malloc.h>
#include <algorithm>
using namespace std;

int counto = -1;

struct SLL {
    int data;
    struct SLL * next;
}*node,*head,*last,*temp;

void display(){
    temp=head;
    if(head==NULL){
        cout << "List is empty" <<endl;
        return;
    }
    int i = -1;
    while(temp!=NULL){
        cout << "-----" << ++i << "-----" <<endl;
        cout << "Data : " << temp->data ;
        cout << endl << "------------" << endl;
        temp=temp->next;
    }
}

void counti(){
    temp=head;
    while(temp!=NULL){
        counto++;
        temp=temp->next;
    }
}
void create_at_begin(){
    node=(struct SLL*) malloc (sizeof(struct SLL));
    cout << "Enter data : ";
    cin >> node->data;
    node->next=NULL;
    if(head==NULL)
        head=last=node;
    else{
        node->next=head;
        head=node;
    }
}

void create_at_last(){
    node=(struct SLL*)malloc(sizeof(struct SLL));
    cout << "Enter data : ";
    cin >> node->data;
    node->next=NULL;
    if(head==NULL)
        head=last=node;
    else{
        last->next=node;
        last=node;
    }
}

void create_at_pos(){
    int pos;
    cout << "Enter position : ";
    cin >> pos;
    counti();
    if(pos == 0 )   create_at_begin;
    else if (pos == counto) create_at_last;
    else if (pos<0 && pos >counto) cout<<"Invalid position\n";
    else{
        node=(struct SLL*)malloc(sizeof(struct SLL));
        cout << "Enter data : ";
        cin >> node->data;
        node->next=NULL;
        if(head==NULL) head=last=node;
        else{
            temp=head;
            for(int i=0;i<pos-1;i++)    temp=temp->next;
            node->next=temp->next;
            temp->next=node;
        }
    } 
}

void delete_at_front(){
    if (head == NULL){
        cout << "List is empty" << endl;
        return;
    }
    else if (head->next == NULL){
        head=last=NULL;
        return;
    }
    else {
        temp=head;
        head=head->next;
        free(temp);
    }
}

void sum_of_list(){
    int sum=0;
    temp=head;
    while(temp!=NULL){
        sum+=temp->data;
        temp=temp->next;
    }
    cout << "Sum of List : " <<sum<<endl;
}

void search_data(){
    int key;
    cout << "Enter key : ";
    cin >>key;
    temp=head;
    while(temp!=NULL){
        if(key == temp->data){
            cout << "Element is present"<<endl;
            return;
        }
        else{
            temp=temp->next;
        }
    }
    cout << "Data isn't present" <<endl;
}

void reverse_linkedlist(){
    struct SLL*temp1,*temp2;
    while(head!=NULL){
        temp2=head->next;
        head->next=temp;
        temp=head;
        head=temp2;
    }
    head=temp;  
}

void sorting(){
    if(head==NULL || head->next == NULL){
       cout << "List is too small to be sorted " <<endl;
       return;
    }
    struct SLL *i,*j;
    bool swapped;
    for(i = head;i->next != NULL ; i=i->next){
        swapped = false;
        for(j = i->next; j!=NULL ; j=j->next){
            if(i->data > j->data){
                swapped = true;
                swap(i->data,j->data);
            }
        }
        if(!swapped) break; 
    }
}
    SLL *head2, *last2;
void second_linked_list (){
    node=(struct SLL * ) malloc (sizeof(struct SLL));
    cout << "Enter data : ";
    cin >> node->data;
    node->next = NULL;
    if(head == NULL)
        head=last=NULL;
    else{
        head->next = node;
        head=node;
    }
}

void concatenate(){
    if(head==NULL){
        head=head2;
        return;
    }
    temp=head;
    while(temp->next != NULL)
        temp=temp->next;
    temp->next=head2;
    cout << "Concatenation Successfull"<<endl;
}

int main(){
    int choice;
    head=last=NULL;
    while(1){
        cout << "1.Insert element from front" <<endl;
        cout << "2.Delete element from front" <<endl;
        cout << "3.Sum of data" <<endl;
        cout << "4.Count number of nodes" <<endl;
        cout << "5.Search given element" <<endl;
        cout << "6.Reverse the Linked List" <<endl;
        cout << "7.Display all elements" <<endl;
        cout << "8.Exit" <<endl;
        cin >> choice;
        switch(choice){
            case 1:
                create_at_begin();
                break;
            case 2:
                delete_at_front();
                break;
            case 3:
                sum_of_list();
                break;
            case 4:
                counti();
                cout << "Total number of element : "<< counto<< endl;
                break;
            case 5:
                search_data();
                break;
            case 6:
                cout << "Before Reversing : " <<endl;
                display();
                reverse_linkedlist();
                cout << "After Reversing : " <<endl;
                display();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                cout << "Invalid choice" <<endl;
                break;
        }
    }
}