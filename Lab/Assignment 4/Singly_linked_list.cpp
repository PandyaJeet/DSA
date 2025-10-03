    #include <iostream>
    #include <malloc.h>
    using namespace std;
    int count;
    struct Linked {
        int data;
        char arr[20];
        struct Linked * next;
    }*node, *head, *last, *temp;

    void counti(){
        temp=head;
        count = 0;
        while (temp != NULL){
            count++;
            temp=temp->next;
        }
    }

    void create_at_begin (){
        node = (struct Linked * )malloc (sizeof(struct Linked));
        cout<< "Enter data & arr : ";
        cin >> node->data ;
        cin >> node->arr;
        node->next=NULL;
        if(head==NULL)
            head=last=node;
        else{
            node->next=head;
            head=node;
        }
    }

    void create_at_last(){
        node = (struct Linked * ) malloc (sizeof(struct Linked));
        cout << "Enter data & arr : ";
        cin >> node->data;
        cin >> node->arr;
        node->next=NULL;
        if (head==NULL)
            head=last=node;
        else{
            last->next=node;
            last=node;
        }
    }

    void create_at_pos(){
        int pos;
        cout << "Enter position : ";
        cin >> pos;
        counti();
        if ( pos == 0 ){
            create_at_begin();
            return;
        }
        else if (pos == count){
            create_at_last();
            return;
        }
        else if (pos > 0 && pos < count){
            node=(struct Linked * ) malloc (sizeof(struct Linked));
            cout << "Enter data & arr : ";
            cin >> node->data;
            cin >> node->arr;
            node->next=NULL;
            if (head == NULL)
                head = last= node;
            else {
                temp = head;
                for(int i = 0 ; i < pos - 1 ; i++){
                    temp=temp->next;
                }
                node->next = temp->next;
                temp->next = node;
            }
        }
    }

    void delete_at_begin(){
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        temp = head;
        head = head->next;
        free(temp);
        if (head == NULL) last = NULL;
    }

    void delete_at_end(){
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == NULL) {  
            free(head);
            head = last = NULL;
            return;
        }
        temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        last = temp;
    }

    void delete_at_pos(){
        int pos;
        cout << "Enter position : ";
        cin >> pos;
        counti();
        if (pos == 0 ){
            delete_at_begin();
            return;
        } 
        else if (pos == count ){
            delete_at_end();
            return;
        }
        else if (pos > 0 && pos < count){
            temp = head;
            for(int i = 0 ; i < pos - 1 ; i ++){
                temp=temp->next;
            }
            struct Linked *t1 = temp->next;
            temp->next = t1->next;
            free(t1);
        }
    }
    void display(){
        temp=head;
        while (temp!=NULL){
            cout << "--------------"<<endl;
            cout << "Data : " << temp->data<<endl;
            cout << "Arr : " << temp->arr<<endl;
            temp=temp->next;
        }
    }
    
    int main() {
        int choice;
        while (1) {
            cout << "\n--- Singly Linked List Operations ---\n";
            cout << "1. Insert at Begin\n2. Insert at Last\n3. Insert at Position\n";
            cout << "4. Delete at Begin\n5. Delete at Last\n6. Delete at Position\n";
            cout << "7. Display\n8. Count Nodes\n9. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1: create_at_begin(); break;
                case 2: create_at_last(); break;
                case 3: create_at_pos(); break;
                case 4: delete_at_begin(); break;
                case 5: delete_at_end(); break;
                case 6: delete_at_pos(); break;
                case 7: display(); break;
                case 8: counti(); cout << "Total Nodes: " << count << endl; break;
                case 9: exit(0);
                default: cout << "Invalid choice!" << endl;
            }
        }
    }