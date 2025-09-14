#include <iostream>
#include <malloc.h>
using namespace std;
int count = 0;
struct dblink
{
    int data;
    struct dblink *next, *prev;
} *node, *head, *last, *temp;

void create_at_begin()
{
    node = (struct dblink *)malloc(sizeof(struct dblink));
    cout << "Enter data : ";
    cin >> node->data;
    node->next = node->prev = NULL;
    if (head == NULL)
        head = last = node;
    else
    {
        node->next = head;
        head->prev = node;
        head = node;
    }
}

void create_at_last()
{
    node = (struct dblink *)malloc(sizeof(struct dblink));
    cout << "Enter data : ";
    cin >> node->data;
    node->next = node->prev = NULL;
    if (head == NULL)
        head = last = node;
    else
    {
        last->next = node;
        node->prev = last;
        last = node;
    }
}

void counti()
{
    count = 0;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
}

void create_at_mid()
{
    counti();
    int pos;
    cout << "Enter position : ";
    cin >> pos;
    if (pos == 1)
    {
        create_at_begin();
        return;
    }
    else if (pos == count - 1)
    {
        create_at_last();
        return;
    }
    else if (pos > count && pos < 0)
    {
        cout << "Invalid position\n";
        return;
    }
    else
    {
        node = (struct dblink *)malloc(sizeof(struct dblink));
        cout << "Enter data : ";
        cin >> node->data;
        node->next = node->prev = NULL;
        if (head == NULL)
        {
            head = last = node;
        }
        else
        {
            int p = 1;
            temp = head;
            while (p < pos)
            {
                p++;
                temp = temp->next;
            }
            // node->next=temp->next;
            // temp->next=node;
            // node->prev=temp;
            // temp->next->next->prev=node;
            temp->next=node;
            temp->next->prev=node;

            node->next=temp->next->next;
            node->prev=temp;
        }
    }
}
void display()
{
    temp = head;
    cout << "From Head\n";
    while (temp != NULL)
    {
        cout << "Data is " << temp->data << endl;
        temp = temp->next;
    }
    cout << "From Last \n";
    temp = last;
    while (temp != NULL)
    {
        cout << "Data is " << temp->data << endl;
        temp = temp->prev;
    }
}

int main()
{
    int ch;
    cout << "1.Begin\n2.Last\n3.Mid\n4.Display\nEnter choice : ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        create_at_begin();
        main();
        break;
    case 2:
        create_at_last();
        main();
        break;
    case 3:
        create_at_mid();
        main();
        break;
    case 4:
        display();
        main();
        break;
    }
}