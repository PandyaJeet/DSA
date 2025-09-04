#include <bits/stdc++.h>
using namespace std;

class NODE{
    private:
        NODE *node,*head,*last,*temp;
        int data;
        NODE * next;
    public:

    void create_at_begin(){
        this->node =(NODE*) malloc (sizeof(NODE));
        cout << "Enter data : ";
        cin >> this->node->data;
        this->node->next = NULL;
        if(this->head == NULL)
            this->head=this->last=NULL;
        else{
            this->head->next=this->node;
            this->node=this->head;
        }
    }
    
    void create_at_last(){
        this->node=(NODE*)malloc(sizeof(NODE));
        cout << "Enter data : ";
        cin >> this->node->data;
        this->node->next=NULL;
        if(this->head==NULL)
            this->head=this->last=NULL;
        else{
            this->last->next=node;
            this->last=this->node;
        }    
    }
    
    void display(){
        this->temp=this->head;
        while(this->temp!=NULL){
            cout << "Data is " << this->temp->data;
            this->temp=this->temp->next;
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
