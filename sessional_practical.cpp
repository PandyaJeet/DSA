#include <iostream>
#include<malloc.h>
#include <cstring>
using namespace std;
struct linked{
    int data;
    char domain[10];
    linked * next;
}*node,*head,*last,*temp;
void create_at_pos(){
    node=(struct linked*) malloc (sizeof(struct linked));
    cout << "Enter data : " ;
    cin >> node->data;
    cout << "Enter domain [AI, CLOUD, DS] : ";
    cin >> node->domain;
    node->next=NULL;
    if(head==NULL)
        head=last=node;
    else {
        struct linked * prev;
        if (strcmp(node->domain,"CLOUD") == 0 ){
            temp=head;
            while(temp!=NULL){
                if (strcmp(temp->domain,"CLOUD")==0){
                    break;
                }
                prev=temp;
                temp=temp->next;
            }
            node->next=temp;
            prev->next=node;
        }
        else{
            node->next=head;
            head=node;
        }
    }
}
void display(){
    if(head==NULL){
        cout << "List is empty" <<endl;
        return;
    }
    temp=head;
    while(temp!=NULL){
    }
}
/*void create_at_begin(){
    node=(struct linked* ) malloc (sizeof(struct linked));
    cout << "Enter data : ";
    cin >> node->data;
    cout << "Enter domain [AI, CLOUD, DS] : ";
    cin >> node->domain;
    node->next=NULL;
    if (head == NULL)
        head=last=node;
    else{
        node->next=head;
        head=node;
    }
}
void create_at_end(){
    node=(struct linked*) malloc (sizeof(struct linked));
    cout << "Enter data : ";
    cin >> node->data;
    node->next=NULL;
    if(head == NULL){
        head=last=node;
    }
    else{
        last->next=node;
        last=node;
    }
}
int counti(){
    int coun=0;
    temp=head;
    while(temp!= NULL){
        coun++ ;
        temp=temp->next;
    }
    return coun;
}
void create_at_pos(){
    cout << "Enter pos : ";
    int pos;
    cin >> pos;
    int coun = counti();
    if (pos < 0 || pos > coun){
        cout << "Invalid choice \n";
        return;
    }
    node=(struct linked*) malloc ( sizeof(struct linked));
    cout << "Enter data : ";
    cin >> node->data;
    node->next= NULL;
    if(head==NULL){
        head=last=node;
    }
    if (pos == 0 && coun!=0) {
        node->next=head;
        head=node;
    }
    else if (pos == coun){
        last->next=node;
        last=node;
    }
    else{
        temp=head;
        int gin=-1;
        while(temp != NULL){
            gin++;
            if(gin+1 == pos){
                break;
            }
            temp=temp->next;
        }
        //    struct linked * t1;
        node->next=temp->next;
        temp->next=node;
    }
}
void display() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    temp = head;
    int i = 0;

    cout << "\n--- LINKED LIST ---\n";
    while (temp != NULL) {
        cout << "Node " << i << " : " << temp->data << endl;
        temp = temp->next;
        i++;
    }
    cout << "-------------------\n";
}
void delete_at_begin(){
    if(head == NULL){
        cout << "List is empty" << endl;
    }
    else if(head->next == NULL){
        free(head);
        head=last=NULL;
    }
    else{
        temp=head;
        head=head->next;
        free(temp);
    }
}
void delete_at_end(){
    if(head==NULL){
        cout << "List is empty" <<endl;
    }
    else if (head->next==NULL){
        free(head);
        head=last=NULL;
    }
    else{
        temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
        last=temp;
    }
}
void delete_at_pos(){
    int pos;
    cout << "Enter pos : " ;
    cin >> pos;
    int coun = counti();
    if(pos == 0)
        delete_at_begin();
    else if (pos == coun-1)
        delete_at_end();
    else if (pos>=coun || pos < 0)
        cout << "Invalid choice \n";
    else {
        temp=head;
        int i = 0;
        while(temp!=NULL){
            i++;
            if (i==pos){
                break;   
            }
            temp=temp->next;
        }
        struct linked * t;
        t=temp->next;
        temp->next = temp->next->next;
        free(t);
    }
}
int main() {
    int mainChoice, subChoice;
    head = last = NULL;

    while (1) {
        cout << "\n========================================\n";
        cout << "       LINKED LIST OPERATIONS\n";
        cout << "========================================\n";
        cout << "1. Insert Node\n";
        cout << "2. Delete Node\n";
        cout << "3. Display List\n";
        cout << "4. Count Nodes\n";
        cout << "5. Exit\n";
        cout << "========================================\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:  // Insert submenu
                while (1) {
                    cout << "\n--- INSERT MENU ---\n";
                    cout << "1. Insert at Beginning\n";
                    cout << "2. Insert at End\n";
                    cout << "3. Insert at Position\n";
                    cout << "4. Back to Main Menu\n";
                    cout << "Enter choice: ";
                    cin >> subChoice;

                    if (subChoice == 4) break;

                    switch (subChoice) {
                        case 1:
                            create_at_begin();
                            break;
                        case 2:
                            create_at_end();
                            break;
                        case 3:
                            create_at_pos();
                            break;
                        default:
                            cout << "Invalid choice! Please try again.\n";
                            break;
                    }
                }
                break;

            case 2:  // Delete submenu
                while (1) {
                    cout << "\n--- DELETE MENU ---\n";
                    cout << "1. Delete from Beginning\n";
                    cout << "2. Delete from End\n";
                    cout << "3. Delete from Position\n";
                    cout << "4. Back to Main Menu\n";
                    cout << "Enter choice: ";
                    cin >> subChoice;

                    if (subChoice == 4) break;

                    switch (subChoice) {
                        case 1:
                            delete_at_begin();
                            break;
                        case 2:
                            delete_at_end();
                            break;
                        case 3:
                            delete_at_pos();
                            break;
                        default:
                            cout << "Invalid choice! Please try again.\n";
                            break;
                    }
                }
                break;

            case 3:  // Display
                display();
                break;

            case 4:  // Count
                {
                    int count = counti();
                    cout << "\nTotal nodes in the list: " << count << endl;
                }
                break;

            case 5:  // Exit
                cout << "\n========================================\n";
                cout << "Thank you for using the program!\n";
                cout << "Exiting...\n";
                cout << "========================================\n";
                return 0;

            default:
                cout << "Invalid choice! Please enter 1-5.\n";
                break;
        }
    }

    return 0;
}
*/