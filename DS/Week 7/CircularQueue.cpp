#include <iostream> 
using namespace std;

char queue[5][15];
int front=0, rear=0, n=5, cnt=0;

void Insert(char ele[15]) {
	if (cnt==n) 
		cout<<"Queue Overflow"<<endl;
	else {
		int i;
		for(i = 0; ele[i] != '\0'; i++){
			queue[rear][i] = ele[i];
		queue[rear][i] = '\0';
		rear = (rear + 1) % n;
		cnt++;
	}
} 

void Delete() {
	if (cnt==0)
		cout<<"Queue Underflow"<<endl;
	else {
		cout<<"Element being deleted: "<<queue[front]<<endl;
		front=(front+1)%n;
		cnt--;
	}
}

void Display() {
	if (cnt==0) {
		cout<<"The queue is empty"<<endl;
	}
	else {
		cout<<"The elements are:\n";
		if (front<rear) {
			for (int i=front;i<=rear;i++) {
				cout<<queue[i]<<" ";
			}
		}
		else {
			for (int i=front;i<n;i++) {
				cout<<queue[i]<<" ";
			}
			for (int i=0;i<rear;i++) {
				cout<<queue[i]<<" ";
			}
		}		
	}
}

int main() {
	int ch;
	char ele[15];
	cout<<"Enter 1 to Insert\nEnter 2 to Delete\nEnter 3 to Display\nEnter 4 to Exit"<<endl;
	do {
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter element to insert:"<<endl;
				cin>>ele;
			    Insert(ele);
				break;
			case 2:
				Delete();
				break;
			case 3:
				Display();
				cout<<"\nFront:"<<front<<" Rear:"<<rear;
				break;
			case 4:
				cout<<"EXIT";
				break;
			default:
				cout<<"Enter valid choice"<<endl;
		}
	}while (ch!=4);
}
