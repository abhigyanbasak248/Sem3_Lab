#include <iostream> 
using namespace std;

int queue[5], head=0, tail=0, n=5, cnt=0;

void enqueue(int ele) {
	if (cnt==n) 
		cout<<"Queue Overflow"<<endl;
	else {
		queue[tail]=ele;
		tail=(tail+1)%n;
		cnt++;
	}
} 

void dequeue() {
	if (cnt==0)
		cout<<"Queue Underflow";
	else {
		cout<<"Element being deleted: "<<queue[head]<<endl;
		head=(head+1)%n;
		cnt--;
	}
}

void display() {
	if (cnt==0) {
		cout<<"The queue is empty"<<endl;
	}
	else {
		cout<<"The elements are:\n";
		if (head<tail) {
			for (int i=head;i<=tail;i++) {
				cout<<queue[i]<<" ";
			}
		}
		else {
			for (int i=head;i<n;i++) {
				cout<<queue[i]<<" ";
			}
			for (int i=0;i<tail;i++) {
				cout<<queue[i]<<" ";
			}
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
				cout<<"\nHead:"<<head<<" Tail:"<<tail;
				break;
			case 4:
				cout<<"EXIT";
				break;
			default:
				cout<<"Enter valid choice"<<endl;
		}
	}while (ch!=4);
}
