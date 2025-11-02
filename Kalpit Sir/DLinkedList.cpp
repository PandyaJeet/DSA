#include<iostream>
#include<stdlib.h>
using namespace std;
struct DList
{
	int info;
	struct DList *next,*prev;
}*node,*l,*r,*temp,*prev1;
void insfirst();
void inslast();
void inspos();
void delfirst();
void dellast();
void delpos();
void displayl();
void displayr();
int count();
int main()
{
	int ch,ans;
	while(1)
	{
		cout<<"\nPRESS 1 FOR INSERT FIRST";
		cout<<"\nPRESS 2 FOR INSERT LAST";
		cout<<"\nPRESS 3 FOR INSERT BASED ON POSITION";
		cout<<"\nPRESS 4 FOR DELETE FIRST";
		cout<<"\nPRESS 5 FOR DELETE LAST";
		cout<<"\nPRESS 6 FOR DELETE BASED ON POSITION";
		cout<<"\nPRESS 7 DISPLAY FROM LEFT";
		cout<<"\nPRESS 8 DISPLAY FROM RIGHT";
		cout<<"\nPRESS 9 FOR COUNT";
		cout<<"\nPRESS 10 FOR EXIT";
		
		cout<<"\nENTER YOUR CHOICE : ";
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
				displayl();
				break;
			case 8:
				displayr();
				break;
			case 9:
				ans=count();
				cout<<"\nTOTAL NUMBER OF NODE : "<<ans;
				break;
			case 10: 
				exit(0);
				break;
			default:
				cout<<"\nINVALID INPUT";
		}
	}
	return 0;
}

void insfirst()
{
	node=(struct DList*)malloc(sizeof(struct DList));
	cout<<"\nENTER THE VALUE : ";
	cin>>node->info;
	if(l=='\0' && r=='\0')
	{
		l=node;
		r=node;
		node->next='\0';
		node->prev='\0';
	}
	else
	{
		node->next=l;
		node->prev='\0';
		l->prev=node;
		l=node;
	}
}

void inslast()
{
	node=(struct DList*)malloc(sizeof(struct DList));
	cout<<"\nENTER THE VALUE : ";
	cin>>node->info;
	if(l=='\0' && r=='\0')
	{
		l=node;
		r=node;
		node->next='\0';
		node->prev='\0';
	}
	else
	{
		node->prev=r;
		node->next='\0';
		r->next=node;
		r=node;
	}
}

void inspos()
{
	int i,pos;
	cout<<"\nENTER THE POSITION : ";
	cin>>pos;
	int ans=count();
	if(pos<1||pos>ans+1)
	{
		cout<<"\nINVALID POSITION";
	}
	else
	{
		if(pos==1)
			insfirst();
		else
			if(pos==ans+1)
				inslast();
			else
			{
				node=(struct DList*)malloc(sizeof(struct DList));
				cout<<"\nENTER THE VALUE : ";
				cin>>node->info;
				temp=l;
				i=1;
				while(i!=pos)
				{
					prev1=temp;
					temp=temp->next;	
					i=i+1;
				}
				prev1->next=node;
				temp->prev=node;
				node->prev=prev1;
				node->next=temp;
			}
	}
}

void delfirst()
{
	if(l=='\0'&&r=='\0')
	{
		cout<<"\nLIST IS EMPTY";
	}
	else
	{
		if(l==r)
		{
			temp=l;
			l='\0';
			r='\0';
		}
		else
		{
			temp=l;
			l=temp->next;
			temp->next='\0';
			l->prev='\0';
		}
		cout<<" "<<temp->info<<" IS DELETED";
		free(temp);
	}
}


void dellast()
{
	if(l=='\0'&&r=='\0')
	{
		cout<<"\nLIST IS EMPTY";
	}
	else
	{
		if(l==r)
		{
			temp=l;
			l='\0';
			r='\0';
		}
		else
		{
			temp=r;
			r=temp->prev;
			temp->prev='\0';
			r->next='\0';	
		}
		cout<<" "<<temp->info<<" IS DELETED";
		free(temp);
	}
}

void delpos()
{
	int pos;
	cout<<"\nENTER THE POSITION : ";
	cin>>pos;
	int ans=count();
	if(pos<1||pos>ans)
	{
		cout<<"\nINVALID POSITION";
	}
	else
		if(pos==1)
			delfirst();
		else
			if(pos==ans)
				dellast();
			else
			{
				temp=l;
				int i=1;
				while(i!=pos)
				{
					prev1=temp;
					temp=temp->next;
					i=i+1;
				}
				temp->next->prev=prev1;
				prev1->next=temp->next;
				temp->next='\0';
				temp->prev='\0';
				cout<<" "<<temp->info<<" IS DELETED";
				free(temp);				
			}
}

void displayl()
{
	if(l=='\0'&&r=='\0')
	{
		cout<<"\nLIST IS EMPTY";
	}
	else
	{
		temp=l;
		while(temp!='\0')
		{
			cout<<"  "<<temp->info;
			temp=temp->next;
		}			
	}
}

void displayr()
{
	if(l=='\0'&&r=='\0')
	{
		cout<<"\nLIST IS EMPTY";
	}
	else
	{
		temp=r;
		while(temp!='\0')
		{
			cout<<"  "<<temp->info;
			temp=temp->prev;
		}
	}
}

int count()
{
	int c=0;
	temp=l;
	while(temp!='\0')
	{
		c=c+1;
		temp=temp->next;
	}
	return c;
}





