#include <iostream>
#include <malloc.h>
using namespace std;

class NODE{
    private:
        NODE *node,*head,*last,*temp;
        int data;
        NODE * next;
    public:

    void create_at_begin(){
        node =(NODE*) malloc (sizeof(NODE));
        cout << "Enter data : ";
        cin >> node->data;
        node->next = NULL;
        if(head == NULL)
            head=last=node;
        else{
            node->next=head;
            head=node;
        }
    }
    
    void create_at_last(){
        node=(NODE*)malloc(sizeof(NODE));
        cout << "Enter data : ";
        cin >> node->data;
        node->next=NULL;
        if(head==NULL)
            head=last=node;
        else{
            last->next=node;
            last=node;
        }    
    }
    
    void display(){
        temp=head;
        while(temp!=NULL){
            cout << "Data is " << temp->data <<endl;
            temp=temp->next;
        }
    }

}o;
int main(){
    int ch;
    while (1){
        cout << "1.Create at begin"<<endl;
        cout << "2.Create at last"<<endl;
        cout << "3.Create at mid"<<endl;
        cout << "4.Display"<<endl;
        cout << "5.Delete"<<endl;
        cout << "6.Exit"<<endl;
        cout << "Enter your choice : ";
        cin >> ch;
        switch(ch){
            case 1:
                o.create_at_begin();
                break;
            case 2:
                o.create_at_last();
                break;
            case 3:
//                create_at_mid();
                break;
            case 4:
                o.display();
                break;
            case 5:
                //delet();
                break;
            case 6:
                exit(0);
            default:
                cout << "Enter valid choice" << endl;
        }
    }
}
