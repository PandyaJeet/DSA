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

void display(){
    temp = head;
    while(temp != NULL){
        cout << "Data is " << temp->data << endl;
        temp = temp->next;
    }
}

