#include<iostream>
#include<malloc.h>
using namespace std;
int count;
int pos;
class Node{
    public:
    int data;
    Node *next;
}*node,*last,*temp,*head,*previous;

void create_at_begin()
{
    node = (Node *) malloc (sizeof(Node));
    cout<<"Enter Data ";
    cin >> node->data;
    node->next = NULL;
    if(head == NULL)
        head=last=node;
    else{
        node->next = head;
        head = node;
    }
}

void create_at_end()
{
    node= (Node*) malloc (sizeof(Node));
    cout<<"Enter Data at Last.";
    cin>>node->data;
    node->next=NULL;
    if(head==NULL)
        head=last=node;
    else
    {
        last->next=node;
        last=node;
    } 
}

void counti(){
    temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
}

void create_at_mid(){
    int pos;
    cout << "Enter position to enter : ";
    cin  >> pos;
    node= (Node*) malloc (sizeof(Node));
    cout<<"Enter Data at "<<pos<<" : ";
    cin>>node->data;
    node->next=NULL;
    counti();
    if(pos==1){
        create_at_end();
        return;
    }
    else if (pos==count){
        create_at_begin();
        return;
    }
    if (pos > count || pos < 1){
        cout << "invalid Position\n";
        return;
    }
    else{
        temp = head;
        for(int i = 1; i <= pos - 1; i++){
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
    }
            
}

void display()
{
    temp=head;
    while(temp!=NULL)
    {
        cout << "Data = "<<temp->data<<endl;
        temp=temp->next;
    }
}

void delete_from_mid()
{   int ch;
    int prev;
    cout<<"Enter which node you want to delete: ";
    cin>>pos;
            temp = head;
            while(temp!=NULL)
            prev++;    
            if(prev = pos-1){
                previous->next=temp->next;
            }
            delete temp;
}   

void delete_from_front()
{
    temp=head;
    head = head->next;
    delete temp;
}

int main()
{
    int ch;
    while(1){
        cout<<"1. Add at BEGIN."<<endl;
        cout<<"2. Add At LAST."<<endl;
        cout<<"3. Add At Middle"<<endl;
        cout<<"4. Delete."<<endl;
        cout<<"5. Display."<<endl;
        cout<<"Enter choice: ";
        cin>>ch;
        switch (ch)
        {
            case 1:
                create_at_begin();
                break;
            case 2:
                create_at_end();
                break;
            case 3:
                create_at_mid();
                break;
            case 4:
                delete_from_mid();
                break;
            case 5:
                display();
                break;
            default:
             cout<<"Khotu che loda"<<endl;
             return 0;
        }
    }
}
