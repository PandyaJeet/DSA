/*
This program will contain 
    1.STACK
    2.QUEUE
    3.SORTING METHODS (Bubble Sort,Selection Sort)
    4.SEARCHING(Binary Search,Linear Search)
In all possible implementations possible
*/
#include <iostream>
#define MAX 5
using namespace std;

void stack();
void stack_push();
void stack_peep();
void stack_change();
void stack_pop();
void s_display();
void queue();
void queue_insertion();
void queue_delete();
void q_display();
void bubble_sort();
void selection_sort();


int TOP=-1,POS,arr[MAX],ELE,FRONT=-1,REAR=-1,n=MAX,i,j;

int main(){
	int ch;
	cout << "1.STACK\n2.QUEUE\n3.Exit\nEnter your choice : ";
	cin>> ch;
	switch(ch){
		case 1:
			stack();
			main();
			break;
		case 2:
			queue();
			main();
			break;
		case 3:
			return 0;
		deafult:
			cout << "Invalid Choice\n";
			main();
	}
}

void reset(){
	for(i =0 ; i<MAX ; i++)
		arr[i] =0;
	TOP = REAR = FRONT = -1;
}
/*********************STACK OPERATIONS*********************/

void stack_push(){
	if(TOP == (MAX-1)){
		cout << "STACK OVERFLOW " << endl;
		return;
	}
	cout << "Enter value to insert : ";
	cin >> ELE;
	arr[++TOP] = ELE;
	cout << "Successfully Inserted " << ELE << " at " << (TOP+1) << endl;
	return;
}

void stack_pop(){
	if(TOP == -1){
		cout << "STACK UNDERFLOW" << endl;
		return;
	}
	cout << "Element " << arr[TOP] << " removed from index " << TOP-- <<endl;
}

void stack_peep(){
	cout << "Enter positon to PEEP : ";
	cin >> POS;
	if ((TOP-POS+1) < 0){
		cout << "Invalid Position" << endl;
		return;
	}
	cout << "Value at position " << (TOP-POS+2) << " is " << arr[TOP-POS+1];
}

void stack_change(){
	cout << "Enter positon you want to change : ";
	cin >> POS;
	if(TOP - POS +1 < 0  ){
		cout << "Invalid Position" << endl;
		return;
	}
	cout << "Enter updated value : ";
	cin >> arr[TOP-POS+1];
	cout << "Value " << arr[TOP-POS+1] << " updated at " << (TOP-POS+1)<< endl;	
}

void s_display(){
	cout << "ELEMENTS : ";
	for(i=0 ; i<=TOP ; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void stack(){
	reset();
	while(1){
	int ch;
	cout << "Press 1 to perform PUSH"<<endl;
	cout << "Press 2 to perform POP"<<endl;
	cout << "Press 3 to perform PEEP"<<endl;
	cout << "Press 4 to perform CHANGE"<<endl;
	cout << "Press 5 to perform DISPLAY"<<endl;
	cout << "Press 6 to perform BUBBLE SORT"<<endl;
	cout << "Press 7 to perform EXIT"<<endl;
	cin >> ch;
	switch(ch){
		case 1:
			stack_push();
			break;
		case 2:
			stack_pop();
			break;
		case 3:
			stack_peep();
			break;
		case 4:
			stack_change();
			break;
		case 5:
			s_display();
			break;
		case 6:
			n=TOP;
			i=j=0;
			bubble_sort();
			break;
		case 7:
			return;
	}
}
}

/*********************QUEUE OPERATIONS*********************/

void queue_insertion(){
	if(REAR >= (MAX - 1)){
		cout <<"QUEUE OVERFLOW\n";
		return; 
	}
	cout << "Enter value to insert : ";
	cin >> ELE;
	if (FRONT == -1 && REAR == -1 )
		FRONT = REAR = 0;
	else
		REAR++;
	arr[REAR] = ELE;
	cout << "Value " << arr[REAR] << " inserted at " << REAR<<endl;
	
}

void queue_delete(){
	if(FRONT == -1){
		cout << "QUEUE UNDERFLOW\n";
		return;
	}
	cout << "Value " << arr[FRONT] << " removed at "<< FRONT <<endl;
	if (FRONT == REAR)
		FRONT = REAR = -1;
	else
		FRONT++;
}

void q_display(){
	cout << "QUEUE : ";
	for(i = FRONT; i <=REAR ; i ++)
		cout << arr[i] << " ";
	cout << endl;
}

void queue(){
	reset();
	int ch;
	while(1){
	cout << "1.Press 1 to perform INSERTION\n";
	cout << "2.Press 2 to perform DELETION\n";
	cout << "3.Press 3 to perform DISPLAY\n";
	cout << "4.Press 4 to perform BUBBLE SORT\n";
	cout << "5.Press 5 to EXIT\n";
	cin >> ch;
	switch(ch){
		case 1:
			queue_insertion();
			break;
		case 2:
			queue_delete();
			break;
		case 3:
			q_display();
			break;
		case 4:
			i=FRONT,n=REAR;
			selection_sort();
			break;
		case 5:
			return;
	}
}
}

void bubble_sort(){
	cout << "ELEMENTS ARE SORTED" <<endl;
	bool swapped;
	for(; i< n ; i++){
		swapped=false;
		for(; j<n ; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp;
				swapped=true;
			}
		}		
		if(!swapped) break;
	}
}

void selection_sort(){
	int minIndex = 0;
	for( ; i < n - 1 ; i++){
		minIndex = i;
		for (int j = i ; j < REAR-i-1;j++){
			if(arr[minIndex] > arr[j])
				swap(arr[minIndex],arr[j]);
		}
}
}
