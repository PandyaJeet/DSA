#include <iostream>
#include <malloc.h>
using namespace std;

struct SLL
{
    int data;
    struct SLL *next;
} *head = NULL, *last = NULL, *node, *temp;

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

void print_and_count_primes()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    temp = head;
    int count = 0;
    cout << "Prime numbers in the list: ";

    while (temp != NULL)
    {
        int num = temp->data;
        int isPrime = 1;

        if (num <= 1)
            isPrime = 0;
        else
        {
            for (int i = 2; i < num; i++)
            {
                if (num % i == 0)
                {
                    isPrime = 0;
                    break;
                }
            }
        }

        if (isPrime)
        {
            cout << num << " ";
            count++;
        }

        temp = temp->next;
    }

    if (count == 0)
        cout << "None";

    cout << "\nTotal prime numbers: " << count << endl;
}

int main()
{
    int choice;
    while (1)
    {
        cout << "\n========== SINGLE LINKED LIST MENU ==========\n";
        cout << "1. Insert an element\n";
        cout << "2. Delete element from end\n";
        cout << "3. Display all elements\n";
        cout << "4. Print all Prime numbers and count total\n";
        cout << "5. Exit\n";
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
            print_and_count_primes();
            break;
        case 5:
            cout << "Exiting program..." << endl;
            exit(0);
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
}
