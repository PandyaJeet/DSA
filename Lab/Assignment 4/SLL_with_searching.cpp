#include <iostream>
#include <malloc.h>
#include <algorithm>
using namespace std;

int counto = -1;

struct SLL
{
    int data;
    struct SLL *next;
} *node, *head, *last, *temp, *headfin, *lastfin;

void display(struct SLL *h)
{
    if (h == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    int i = -1;
    while (h != NULL)
    {
        cout << "-----" << ++i << "-----" << endl;
        cout << "Data : " << h->data;
        cout << endl
             << "------------" << endl;
        h = h->next;
    }
}

void counti()
{
    temp = head;
    counto = -1;
    while (temp != NULL)
    {
        counto++;
        temp = temp->next;
    }
}
void create_at_begin()
{
    node = (struct SLL *)malloc(sizeof(struct SLL));
    cout << "Enter data : ";
    cin >> node->data;
    node->next = NULL;
    if (head == NULL)
        head = last = node;
    else
    {
        node->next = head;
        head = node;
    }
}

void create_at_last()
{
    node = (struct SLL *)malloc(sizeof(struct SLL));
    cout << "Enter data : ";
    cin >> node->data;
    node->next = NULL;
    if (head == NULL)
        head = last = node;
    else
    {
        last->next = node;
        last = node;
    }
}

void create_at_pos()
{
    int pos;
    cout << "Enter position : ";
    cin >> pos;
    counti();
    if (pos == 0)
        create_at_begin;
    else if (pos == counto)
        create_at_last;
    else if (pos < 0 && pos > counto)
        cout << "Invalid position\n";
    else
    {
        node = (struct SLL *)malloc(sizeof(struct SLL));
        cout << "Enter data : ";
        cin >> node->data;
        node->next = NULL;
        if (head == NULL)
            head = last = node;
        else
        {
            temp = head;
            for (int i = 0; i < pos - 1; i++)
                temp = temp->next;
            node->next = temp->next;
            temp->next = node;
        }
    }
}

void delete_at_front()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else if (head->next == NULL)
    {
        head = last = NULL;
        return;
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void sum_of_list()
{
    int sum = 0;
    temp = head;
    while (temp != NULL)
    {
        sum += temp->data;
        temp = temp->next;
    }
    cout << "Sum of List : " << sum << endl;
}

void search_data()
{
    int key;
    cout << "Enter key : ";
    cin >> key;
    temp = head;
    while (temp != NULL)
    {
        if (key == temp->data)
        {
            cout << "Element is present" << endl;
            return;
        }
        else
        {
            temp = temp->next;
        }
    }
    cout << "Data isn't present" << endl;
}

void reverse_linkedlist()
{
    struct SLL *temp1, *temp2;
    while (head != NULL)
    {
        temp2 = head->next;
        head->next = temp;
        temp = head;
        head = temp2;
    }
    head = temp;
}

void sorting(struct SLL *h)
{
    if (h == NULL || h->next == NULL)
    {
        cout << "List is too small to be sorted " << endl;
        return;
    }
    struct SLL *i, *j;
    bool swapped;
    for (i = h; i->next != NULL; i = i->next)
    {
        swapped = false;
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                swapped = true;
                swap(i->data, j->data);
            }
        }
        if (!swapped)
            break;
    }
}
SLL *head2, *last2;
void second_linked_list()
{
    int n;
    cout << "How many nodes in second list? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        node = (struct SLL *)malloc(sizeof(struct SLL));
        cout << "Enter data " << i + 1 << ": ";
        cin >> node->data;
        node->next = NULL;

        if (head2 == NULL)
            head2 = last2 = node;
        else
        {
            last2->next = node;
            last2 = node;
        }
    }
}

void merge()
{
    second_linked_list();
    sorting(head);
    sorting(head2);
    if (head == NULL)
    {
        head = head2;
        return;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    cout << "Successfully Merged!!!" << endl;
    display(head);
}

void concatenate()
{
    if (head == NULL)
    {
        head = head2;
        return;
    }
    temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = head2;
    cout << "Concatenation Successfull" << endl;
}
void Union_SLL()
{
    second_linked_list();
    sorting(head);
    sorting(head2);
    SLL *t1 = head, *t2 = head2;
    SLL *headfin = NULL, *lastfin = NULL;

    while (t1 != NULL && t2 != NULL)
    {
        int val;
        if (t1->data < t2->data)
        {
            val = t1->data;
            t1 = t1->next;
        }
        else if (t1->data > t2->data)
        {
            val = t2->data;
            t2 = t2->next;
        }
        else
        {
            val = t1->data;
            t1 = t1->next;
            t2 = t2->next;
        }

        node = (SLL *)malloc(sizeof(SLL));
        node->data = val;
        node->next = NULL;

        if (headfin == NULL)
            headfin = lastfin = node;
        else
        {
            lastfin->next = node;
            lastfin = node;
        }
    }

    while (t1 != NULL)
    {
        node = (SLL *)malloc(sizeof(SLL));
        node->data = t1->data;
        node->next = NULL;
        if (headfin == NULL)
            headfin = lastfin = node;
        else
        {
            lastfin->next = node;
            lastfin = node;
        }
        t1 = t1->next;
    }

    while (t2 != NULL)
    {
        node = (SLL *)malloc(sizeof(SLL));
        node->data = t2->data;
        node->next = NULL;
        if (headfin == NULL)
            headfin = lastfin = node;
        else
        {
            lastfin->next = node;
            lastfin = node;
        }
        t2 = t2->next;
    }
    cout << "Union of Linked Lists:" << endl;
    display(headfin);
}
void Intersection_SLL()
{
    second_linked_list();
    sorting(head);
    sorting(head2);
    SLL *t1 = head, *t2 = head2;
    SLL *headfin = NULL, *lastfin = NULL;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data < t2->data)
            t1 = t1->next;
        else if (t1->data > t2->data)
            t2 = t2->next;
        else
        {
            SLL *node = (SLL *)malloc(sizeof(SLL));
            node->data = t1->data;
            node->next = NULL;

            if (headfin == NULL)
                headfin = lastfin = node;
            else
            {
                lastfin->next = node;
                lastfin = node;
            }
            t1 = t1->next;
            t2 = t2->next;
        }
    }

    if (headfin == NULL)
        cout << "No common elements found." << endl;
    else
    {
        cout << "Intersection of Linked Lists:" << endl;
        display(headfin);
    }
}
int main()
{
    int choice;
    head = last = head2 = last2 = NULL;

    while (true)
    {
        cout << "\n========= LINKED LIST OPERATIONS =========\n";
        cout << "1.  Insert element at front (List 1)\n";
        cout << "2.  Delete element from front (List 1)\n";
        cout << "3.  Sum of elements (List 1)\n";
        cout << "4.  Count number of nodes (List 1)\n";
        cout << "5.  Search element in List 1\n";
        cout << "6.  Reverse List 1\n";
        cout << "7.  Display Lists\n";
        cout << "8.  Create/Modify Second Linked List\n";
        cout << "9.  Concatenate Lists (List1 + List2)\n";
        cout << "10. Merge Lists (Sorted)\n";
        cout << "11. Union of Lists\n";
        cout << "12. Intersection of Lists\n";
        cout << "13. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
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
            cout << "Total number of elements: " << counto + 1 << endl;
            break;
        case 5:
            search_data();
            break;
        case 6:
            cout << "Before Reversing:\n";
            display(head);
            reverse_linkedlist();
            cout << "After Reversing:\n";
            display(head);
            break;
        case 7:
            cout << "\n--- First List ---\n";
            display(head);
            cout << "\n--- Second List ---\n";
            display(head2);
            break;
        case 8:
            second_linked_list();
            break;
        case 9:
            concatenate();
            display(head);
            break;
        case 10:
            merge();
            break;
        case 11:
            Union_SLL();
            break;
        case 12:
            Intersection_SLL();
            break;
        case 13:
            cout << "Exiting program..." << endl;
            exit(0);
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    }
}