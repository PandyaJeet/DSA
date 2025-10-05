#include <iostream>
#define MAX 5
using namespace std;
int TOP = -1, S[MAX];
int FRONT = -1, REAR = -1, Q[MAX];
void push()
{
    int ele;
    if (TOP == MAX - 1)
    {
        cout << "Stack Overflow " << endl;
        return;
    }
    cout << "Enter data : ";
    cin >> ele;
    S[++TOP] = ele;
    cout << S[TOP] << " element was inserted at " << TOP << endl;
}
void pop()
{
    if (TOP == -1)
    {
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << "Element " << S[TOP] << " was removed from " << TOP << endl;
    TOP--;
}
void change()
{
    int pos, ele;
    cout << "Enter position : ";
    cin >> pos;
    if ((TOP - pos + 1) < 0)
    {
        cout << "Invalid position " << endl;
        return;
    }
    cout << "Enter element : ";
    cin >> ele;
    cout << "Element i.e. " << S[TOP - pos + 1] << " was replaced by " << ele << endl;
    S[TOP - pos + 1] = ele;
}
void peep()
{
    int pos;
    cout << "Enter position : ";
    cin >> pos;
    if ((TOP - pos + 1) < 0)
    {
        cout << "Invalid position " << endl;
        return;
    }
    cout << "Element at " << pos << " is " << S[TOP - pos + 1];
}
void display()
{
    if (TOP == -1)
    {
        cout << "Stack is empty " << endl;
        return;
    }
    for (int i = TOP; i >= 0; i--)
    {
        cout << i << ". " << S[i] << endl;
    }
}
void stack()
{
    int choice;
    while (1)
    {
        cout << "1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "3.Peep" << endl;
        cout << "4.Change" << endl;
        cout << "5.Display" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peep();
            break;
        case 4:
            change();
            break;
        case 5:
            display();
            break;
        case 6:
            return;
        default:
            cout << "Invalid Choice" << endl;
        }
    }
}
void insertion()
{
    if (REAR == MAX - 1)
    {
        cout << "Queue is full" << endl;
        return;
    }
    int ele;
    cout << "Enter data : ";
    cin >> ele;
    if (REAR == -1)
        FRONT++;
    Q[++REAR] = ele;
    cout << "Element " << Q[REAR] << " inserted at " << REAR << endl;
}
void deletion()
{
    if (FRONT == -1)
    {
        cout << "Queue is empty " << endl;
        return;
    }
    cout << "Element " << Q[FRONT] << " was deleted " << endl;
    if (FRONT == REAR)
        FRONT = REAR = -1;
    else
        FRONT++;
}
void Qdisplay()
{
    if (REAR == -1)
    {
        cout << "Queue is empty " << endl;
        return;
    }
    cout << "----------" << endl;
    for (int i = FRONT; i <= REAR; i++)
    {
        cout << Q[i] << endl;
    }
    cout << "----------" << endl;
}
void queue()
{
    int choice;
    while (1)
    {
        cout << "1.Insertion" << endl;
        cout << "2.Deletion" << endl;
        cout << "3.Display" << endl;
        cout << "Enter choice : " << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            insertion();
            break;
        case 2:
            deletion();
            break;
        case 3:
            Qdisplay();
            break;
        case 4:
            return;
        default:
            cout << "Invalid choice " << endl;
            break;
        }
    }
}
struct SLL
{
    int data;
    SLL *next;
} *node, *head, *last, *temp;
void create_at_pos()
{
    node=(struct SLL*) malloc (sizeof(struct SLL));
    cout << "Enter data : " ;
    cin >> node->data;
    node->next=NULL;
    if(head==NULL)
        head=last=node;
    else{
        node->next=head;
        head=node;
    }
}
void Ldisplay(){
    if(head==NULL){
        cout << "List is empty \n";
        return;
    }
    temp=head;
    int i = -1;
    while(temp!=NULL){
        cout << "-----" <<++i << "-----"<<endl;
        cout << "Data : " << temp->data <<endl;
        cout << "------------" <<endl;
        temp=temp->next;
    }
}
void delete_at_pos(){
    if(head==NULL){
        cout << "List is empty" <<endl;
        return;
    }
    else if (head->next == NULL){
        head=last=NULL;
        return;
    }
    temp=head;
    head=head->next;
    free(temp);
}
void sort(){
    bool swapped;
    SLL *i, *j;
    for(i=head;i->next!=NULL;i=i->next){
        swapped = false;
        for(j=i;j!= NULL ; j=j->next){
            if(i->data < j->data){
                swapped = true;
            }
        }
    }
}
void ll()
{
    int choice;
    head = last = NULL;
    while (1)
    {
        cout << "1.Create at Begin " << endl;
        cout << "2.Delete at Pos" << endl;
        cout << "3.Sorted " << endl;
        cout << "4.Reverse" << endl;
        cout << "5.Display" <<endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            create_at_pos();
            break;
        case 2:
            delete_at_pos();
            break;
        case 5:
            Ldisplay();
            break;
        default:
            cout << "Invalid Choice "<<endl;
            break;
        }
    }
}
int main()
{
    int choice;
    while (1)
    {
        cout << "1.Stack" << endl;
        cout << "2.Queue" << endl;
        cout << "3.Linkedlist" << endl;
        cout << "Enter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            stack();
            break;
        case 2:
            queue();
            break;
        case 3:
            ll();
            break;
        }
    }
}