#include <iostream> 
using namespace std;

int queue[100], front=-1, rear=-1, n=100;

void enqueue(int ele) {
	if (rear>n-1) 
		cout<<"Queue Overflow"<<endl;
	else {
		if (front==-1) 
			front=0;
		if (rear==-1) {
			rear++;
			queue[rear]=ele;		
		}
		else {
			queue[rear]=ele;
			rear++;
		}
		
	}
} 

void dequeue() {
	if (front==rear)
		cout<<"Queue Underflow";
	else {
		front++;
	}
}

void display() {
	if (front==rear)
		cout<<"Queue is empty"<<endl;
	else {
		cout<<"The elements are:\n";
		for (int i=front;i<=rear;i++) {
			cout<<queue[i]<<" ";
		}
	}
	
}

int main() {
	int ch,ele;
	cout<<"Enter 1 to enQueue\nEnter 2 to deQueue\nEnter 3 to display\nEnter 4 to Exit"<<endl;
	do {
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter element to insert:"<<endl;
				cin>>ele;
			    enqueue(ele);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				cout<<"EXIT";
				break;
			default:
				cout<<"Enter valid choice"<<endl;
		}
	}while (ch!=4);
}
