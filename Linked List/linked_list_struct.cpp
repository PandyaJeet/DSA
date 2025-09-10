#include <iostream>
#include <malloc.h>

using namespace std;

int pos,count;

struct NODE{
	int data;
	struct NODE * next;
}*node,*head,*last,*temp;

void create_at_begin(){
	node=(struct NODE*)malloc(sizeof(struct NODE));
	cout << "Enter data : ";
	cin >> node->data;
	node->next=NULL;
	if(head==NULL)
		head=last=node;
	else{
		node->next=head;
		head=node;
	}
}

void create_at_last(){
	node=(struct NODE*)malloc(sizeof(struct NODE));
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

void counti(){
	temp=head;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	
}

void create_at_mid(){ 
	cout << "Enter position to enter : ";
    cin  >> pos;
    node= (struct NODE*)malloc(sizeof(struct NODE));
    cout<<"Enter Data at "<<pos<<" : ";
    cin>>node->data;
    node->next=NULL;
    counti();
    if(pos==1){
        create_at_last();
        return;
    }
    else if (pos==count){
        create_at_begin();
        return;
    }
    else if (pos > count || pos < 1){
        cout << "invalid Position\n";
        return;
    }
    else{
    	temp=head;
    	 for(int i = 1; i <= pos - 1; i++){
            temp = temp->next;
        }
        node->next = temp->next;
        temp->next = node;
	}
}

void display(){
	temp=head;
	while(temp!=NULL){
		cout << "Data is "<<temp->data <<endl;
		temp=temp->next;
	}
}

void delete_front(){
	if(head == NULL)
		cout << "No Elements to delete" <<endl;
	else{
		temp=head;
		head=head->next;
		free(temp);
	}
}

void delete_last(){
	counti();
	temp=head;
	while(temp->next!=last)
		temp=temp->next;
	free(last);
	last=temp;
	last->next=NULL;
}
/*
void delete_mid(){
	temp=head;
	cout << "Enter position to delete : ";
	cin >>pos;
	if(pos==1)
		delete_front();
	else if(pos<=count)
		delete_last();
	else if(pos < 0 || pos > count){
		cout << "Enter valid position" <<endl;
		return;
	}
	else{
	int p=0;
	while(temp!=NULL){
		p++;
		if(p==pos-1){
			NODE * t = temp->next;
			temp->next=temp->next->next;			
			free(t);
			return;
		}
		else
		temp=temp->next;
	}
}
}*/

void delete_mid(){
	cout << "Enter position to delete : ";
	cin>> pos;
	counti();
	if(pos==1)
		delete_front();
	else if(pos==count)
		delete_last();
	else if(pos < 0 || pos > count){
		cout << "Enter valid position" <<endl;
		return;
	}
	else{
		temp=head;
		int p=0;
		while(temp!=NULL){
			p++;
			if(p==pos-1){

				temp->next=temp->next->next;
				return;
			}
			temp=temp->next;
		}
	}
}

void delet(){
	int ch;
	cout << "1.Delete from front"<<endl;
	cout << "2.Delete from last" <<endl;
	cout << "3.Delete from mid"<<endl;
	cin >>ch;
	switch(ch){
		case 1:
			delete_front();
			break;
		case 2:
			delete_last();
			break;
		case 3:
			delete_mid();
			break;
		default:
			break;
	}
}

int main()
{
    int ch;
    while(1){
        cout<<"1. Add at BEGIN."<<endl;
        cout<<"2. Add At LAST."<<endl;
        cout<<"3. Add At Middle"<<endl;
        cout<<"4. Delete."<<endl;
        cout<<"5. Display."<<endl;
        cout<<"Enter choice: ";
        cin>>ch;
        switch (ch)
        {
            case 1:
                create_at_begin();
                break;
            case 2:
                create_at_last();
                break;
			case 3:
                create_at_mid();
                break;
            case 4:
            	delet();
                break;
            case 5:
                display();
                break;
            default:
             cout<<"Wrong answer"<<endl;
             return 0;
        }
    }
}
