#include <iostream>
#include <cstring>
#include <malloc.h>
using namespace std;
struct LL
{
    int data;
    struct LL *next, *prev;
} *node, *head, *last, *temp;
void create_at_pos()
{
    node = (struct LL *)malloc(sizeof(struct LL));
    cout << "Enter data : ";
    cin >> node->data;
    node->next = node->prev = NULL;
    if (head == NULL)
    {
        head = last = node;
    }
    else
    {
        if (node->data == 0)
        {
            temp = head;
            struct LL *pichu = NULL;
            while (temp != NULL)
            {
                if (temp->data == -1)
                    pichu = temp;
                temp = temp->next;
            }
            if (pichu == NULL)
            {
                node->next = head;
                head->prev = node;
                head = node;
            }
            else if (pichu->next == NULL)
            {
                last->next = node;
                node->prev = last;
                last = node;
            }
            else
            {
                node->next = pichu->next;
                node->prev = pichu;
                pichu->next = node;
                node->next->prev = node;
            }
        }
        else{
            node->next=head;
            head->prev=node;
            head=node;
        }
    }
}
void display()
{
    temp = head;
    int i = 0;
    while (temp != NULL)
    {
        cout << "------" << i++ << "-----" << endl;
        cout << " Data : " << temp->data << endl;
        cout << "------------" << endl;
        temp = temp->next;
    }
}
void delete_at_pos()
{
    if(head==NULL){
        cout << "List is empty " <<endl;
        return;
    }
    else {
        temp=head;
        struct LL * pichu = NULL;
        while(temp!=NULL){
            if(temp->data == 0) {
                pichu=temp;
            }
            temp=temp->next;
        }
        if(pichu == NULL){
            temp=head;
            head=head->next;
            head->prev=NULL;
            free(temp);
        }
        else if (pichu->next==NULL){
            temp=pichu;
            pichu->prev->next=NULL;
            last=pichu->prev;
            free(pichu);
            
        }
        else {
            temp=pichu;
            pichu->prev->next=pichu->next;
            pichu->next->prev=pichu->prev;
            free(temp);
        }

    }
}
int main()
{
    int choice;
    while (1)
    {
        cout << "1.Create" << endl;
        cout << "2.Delete" << endl;
        cout << "3.Display" << endl;
        cout << "Enter choice : " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            create_at_pos();
            break;
        case 2:
            delete_at_pos();
            break;
        case 3:
            display();
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }
}