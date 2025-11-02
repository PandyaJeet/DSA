#include<iostream>
#include<stdlib.h>
using namespace std;
void insfirst();
void inslast();
void inspos();
void delfirst();
void dellast();
void delpos();
void display();
int count();
struct SList
{
	int info;
	struct SList *next;
}*node,*head,*last,*temp,*prev;
int main()
{
	int ch,ans;
	while(1)
	{
		cout<<"\nPRESS 1 FOR INSERT FIRST";
		cout<<"\nPRESS 2 FOR INSERT LAST";
		cout<<"\nPRESS 3 FOR INSERT BASE ON POSITION";
		cout<<"\nPRESS 4 FOR DELETE FIRST";
		cout<<"\nPRESS 5 FOR DELETE LAST";
		cout<<"\nPRESS 6 FOR DELETE BASE ON POSITION";
		cout<<"\nPRESS 7 FOR DISPLAY";
		cout<<"\nPRESS 8 FOR COUNT";
		cout<<"\nPRESS 9 FOR EXIT";
		
		cout<<"\nENTER YOUR CHOICE: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1:
				insfirst();
				break;
				
			case 2:
				inslast();
				break;
				
			case 3:
				inspos();
				break;
				
			case 4:
				delfirst();
				break;
				
			case 5:
				dellast();
				break;
				
			case 6:
				delpos();
				break;
				
			case 7:
				display();
				break;
				
			case 8:
				ans=count();
				cout<<"TOTAL COUNT IS: "<<ans;
				break;
				
			case 9:
				exit(0);
				break;
				
			default:
				cout<<"\nINVALID INPUT!!";
		}
	}
	return 0;
}

void insfirst()
{
	node=(struct SList*)malloc(sizeof(struct SList));
	cout<<"\nENTER THE VALUE: ";
	cin>>node->info;
	if(head=='\0')
	{
		head=node;
		node->next='\0';
		last=node;
	}
	else
	{
		node->next=head;
		head=node;
	}
}

void inslast()
{
	node=(struct SList*)malloc(sizeof(struct SList));
	cout<<"\nENTER THE VALUE: ";
	cin>>node->info;
	node->next='\0';
	if(head=='\0')
	{
		head=node;
		last=node;
	}
	else
	{
		last->next=node;
		last=node;
	}
}

void inspos()
{
	int pos;
	cout<<"\nENTER THE POSITION: ";
	cin>>pos;
	int ans=count();
	if(pos<1||pos>ans+1)
	{
		cout<<"\nINVALID POSITION!";
	}
	else
	{
		if(pos==1)
			insfirst();
		else
		{
			if(pos==ans+1)
				inslast();
			else
			{
				node=(struct SList*)malloc(sizeof(struct SList));
				cout<<"\nENTER THE VALUE: ";
				cin>>node->info;
				temp=head;
				int i=1;
				while(i!=pos)
				{
					prev=temp;
					temp=temp->next;
					i=i+1;
				}
				node->next=prev->next;
				prev->next=node;
			}
		}
	}
}

void delfirst()
{
	if(head=='\0')
	{
		cout<<"\nLIST IS EMPTY!!";
	}
	else
	{
		if(head->next=='\0')
		{
			temp=head;
			head='\0';
			free(temp);
		}
		else
		{
			temp=head;
			head=temp->next;
			free(temp);
		}
	}
}

void dellast()
{
	if(head=='\0')
	{
		cout<<"\nLIST IS EMPTY!!";
	}
	else
	{
		if(head->next=='\0')
		{
			temp=head;
			head='\0';
			free(temp);
		}
		else
		{
			temp=head;
			while(temp!=last)
			{
				prev=temp;
				temp=temp->next;
			}
			prev->next='\0';
			last=prev;
			free(temp);
		}
	}
}

void delpos()
{
	int pos;
	cout<<"\nENTER THE POSITION: ";
	cin>>pos;
	if(head=='\0')
	{
		cout<<"\nLIST IS EMPTY";
	}
	else
	{
		int ans=count();
		if(pos<1||pos>ans)
		{
			cout<<"\nINVALID POSITION";
		}
		else
		{
			if(pos==1)
				delfirst();
			else
			{
				if(pos==ans)
					dellast();
				else
				{
					int i=1;
					temp=head;
					while(i!=pos)
					{
						prev=temp;
						temp=temp->next;
						i=i+1;
					}
					cout<<"\n"<<temp->info<<" IS DELETED";
					prev->next=temp->next;
					temp->next='\0';
					free(temp);
				}
			}
		}
	}
}

void display()
{
	if(head=='\0')
	{
		cout<<"\nLIST IS EMPTY";
	}
	else
	{
		temp=head;
		while(temp!='\0')
		{
			cout<<temp->info<<" ";
			temp=temp->next;
		}
	}
}

int count()
{
	int c=0;
	if(head=='\0')
	{
		cout<<"\nLIST IS EMPTY";
	}
	else
	{
		temp=head;
		while(temp!='\0')
		{
			c=c+1;
			temp=temp->next;
		}
	}
	return c;
}
