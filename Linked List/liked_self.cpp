#include <iostream>
#include <malloc.h>
using namespace std;
struct linked{
    int data;
    struct linked *next;
}*node,*head,*last,*temp;
void createatbegin(){
    node = (struct linked*) malloc (sizeof(struct linked));
    cout << "Enter data: ";
    cin >> node->data;
    node->next = NULL;
    if(head == NULL)
        head=last=node;
    else{
        node->next=head;
        head=node;        
    }
}
void display(){
    temp=head;
    while(temp != NULL){
        cout << "Data is " << temp->data << endl;
        temp=temp->next;
    }
}
int main(){
    int ch;
    while(1){
        cout << "1.Add a node at begin\n2.Display all nodes\nEnter Choice : ";
        cin >> ch;
        switch(ch){
            case 1:
                createatbegin();
                break;
            case 2:
                display();
                break;
            default:
                return 0;
        }
    }
}