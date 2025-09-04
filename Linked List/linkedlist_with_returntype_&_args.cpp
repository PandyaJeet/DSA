#include <bits/stdc++.h>
using namespace std;

class NODE{
    private:
        NODE *node,*head,*last,*temp;
    public:
        int data;
        NODE * next;
    
    void create_at_begin(){
        o.node =(NODE*) malloc (sizeof(NODE));
        cout << "Enter data : ";
        cin >> o.node->data;
        o.node->next = NULL;
        if(o.head == NULL)
            o.head=o.last=NULL;
        else{
            o.head->next=o.node;
            o.node=o.head;
        }
    }
    
    void create_at_last(){
        o.node=(NODE*)malloc(sizeof(NODE));
        cout << "Enter data : ";
        cin >> o.node->data;
        o.node->next=NULL;
        if(o.head==NULL)
            o.head=o.last=NULL;
        else{
            o.last->next=node;
            o.last=o.node;
        }    
    }
    
    void display(){
        o.temp=o.head;
        while(o.temp!=NULL){
            cout << "Data is " << o.temp->data;
            o.temp=o.temp->next;
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
//                create_at_last();
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
