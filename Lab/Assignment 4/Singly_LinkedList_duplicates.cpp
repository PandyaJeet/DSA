#include <iostream>
#include <malloc.h>
using namespace std;

struct SLL
{
    int data;
    struct SLL *next;
} *node, *head, *last, *temp;

void display()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    int i = 1;
    temp = head;
    while (temp != NULL)
    {
        cout << "Node " << i++ << ": " << temp->data << endl;
        temp = temp->next;
    }
}

void insert_element()
{
    node = (struct SLL *)malloc(sizeof(struct SLL));
    cout << "Enter data: ";
    cin >> node->data;
    node->next = NULL;

    if (head == NULL)
        head = last = node;
    else
    {
        last->next = node;
        last = node;
    }
    cout << "Element inserted successfully!" << endl;
}

void delete_from_end()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = last = NULL;
        cout << "Last element deleted successfully!" << endl;
        return;
    }

    temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
    last = temp;
    cout << "Last element deleted successfully!" << endl;
}

void remove_duplicates()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    struct SLL *temp1, *temp2;
    temp1 = head;

    while (temp1 != NULL && temp1->next != NULL)
    {
        temp2 = temp1;
        while (temp2->next != NULL)
        {
            if (temp1->data == temp2->next->data)
            {
                temp = temp2->next;
                temp2->next = temp2->next->next;
                free(temp);
            }
            else
                temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    cout << "Duplicates removed successfully!" << endl;
}

void count_duplicates()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    int count = 0;
    struct SLL *temp1, *temp2;
    temp1 = head;

    while (temp1 != NULL)
    {
        int duplicate_found = 0;
        temp2 = temp1->next;
        while (temp2 != NULL)
        {
            if (temp1->data == temp2->data)
            {
                duplicate_found = 1;
                break;
            }
            temp2 = temp2->next;
        }
        if (duplicate_found)
            count++;
        temp1 = temp1->next;
    }

    cout << "Total number of duplicate elements: " << count << endl;
}

int main()
{
    int choice;
    while (true)
    {
        cout << "\n========== SINGLE LINKED LIST MENU ==========\n";
        cout << "1. Insert an element\n";
        cout << "2. Delete last element\n";
        cout << "3. Display all elements\n";
        cout << "4. Remove duplicates (unsorted list)\n";
        cout << "5. Count total number of duplicate elements\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insert_element();
            break;
        case 2:
            delete_from_end();
            break;
        case 3:
            display();
            break;
        case 4:
            remove_duplicates();
            break;
        case 5:
            count_duplicates();
            break;
        case 6:
            cout << "Exiting program..." << endl;
            exit(0);
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
}
