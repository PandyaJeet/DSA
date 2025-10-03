#include <iostream>
#include <malloc.h>

using namespace std;

int count = 0;

struct Double_Linkedlist{
    int data;
    struct Double_Linkedlist * next;
    struct Double_Linkedlist * prev;
}*node,*head,*last,*temp;

void create_at_begin(){
    node=(struct Double_Linkedlist*) malloc (sizeof(struct Double_Linkedlist));
    cout << "Enter data : ";
    cin >> node->data;
    node->next = node->prev = NULL;
    if ( head == NULL )
        head = last = node;
    else{
        head->next=node;
        node->prev = head;
        node=head;
    }
}