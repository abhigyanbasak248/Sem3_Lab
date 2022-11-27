#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};
struct node *head=NULL;

void insert_begin(int x) {
    struct node *newNode= new struct node;
    newNode->data=x;
    newNode->next=head;
    head=newNode;
}

void insert_end(int x) {
	struct node *newNode=new struct node;
	newNode->data=x;
	newNode->next=NULL;
	struct node *temp=head;
	while (temp->next!=NULL) {
		temp=temp->next;
	}
	temp->next=newNode;
}

void del() {	
	cout<<"Enter position to delete at:\n";
	int pos;
	cin>>pos;
	if (pos==1) {
		struct node *temp=head;
		head=head->next;
		temp=NULL;
	}
	else {
		struct node *p=head;
		struct node *q=head->next;
		for (int i=1;i<pos-1;i++) {
			p=p->next;
			q=q->next;
		}
		p->next=q->next;
	}
	
}

void display() {
    struct node *ptr=head;
    while (ptr!=NULL) {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}

void insert_before(int x) {
	cout<<"Enter position before which to insert:\n";
	int pos;
	cin>>pos;
	struct node *newNode =new struct node;
	newNode->data=x;
	struct node *temp=head;
	for (int i=1;i<pos-1;i++) {
		temp=temp->next;
	}
	newNode->next=temp->next;
	temp->next=newNode;			
}

void insert_after(int x) {
	cout<<"Enter position after which to insert:\n";
	int pos; 
	cin>>pos;
	struct node *newNode =new struct node;
	newNode->data=x;
	struct node *temp=head;
	for (int i=1;i<pos;i++) {
		temp=temp->next;
	}
	newNode->next=temp->next;
	temp->next=newNode;
}

int main() {
    cout<<"Enter 1 to insert at beginning\n";
    cout<<"Enter 2 to insert at end\n";
    cout<<"Enter 3 to insert before an element\n";
    cout<<"Enter 4 to insert after an element\n";
    cout<<"Enter 5 to delete\n";
    cout<<"Enter 6 display the list\n";
    cout<<"Enter 7 to exit\n";
    int ch,e;
    do {
    	cin>>ch;
    	switch(ch) {
    		case 1:
    			cout<<"Enter element to insert at beginning:\n";
    			cin>>e;
    			insert_begin(e);
    			break;
    		case 2:
    			cout<<"Enter element to insert at end:\n";
    			cin>>e;
    			insert_end(e);
    			break;
    		case 3:
    			cout<<"Enter element to insert before an element:\n";
    			cin>>e;
    			insert_before(e);
    			break;
    		case 4:
    			cout<<"Enter element to insert after an element:\n";
    			cin>>e;
    			insert_after(e);
    			break;
    		case 5:
    			del();
    			break;
    		case 6:
				 cout<<"The list is:\n";
				 display();
				 break;
			case 7:
				cout<<"EXIT";
				break;
			default:
				cout<"Enter valid choice\n";
				break;
		}
	} while (ch!=7);
    
}
