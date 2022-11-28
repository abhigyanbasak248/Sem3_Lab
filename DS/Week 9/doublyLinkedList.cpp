#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};
node *head, *tail = NULL;

void insert_end(int data)
{
    node *newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
    }
    tail = newNode;
}

void del_end() {
    if (tail->prev==NULL) {
        head=tail=NULL;
    }
    else {
        tail->prev->next=NULL;
        tail=tail->prev;
    }
}

void insert_pos(int data, int pos)
{
    node *newNode = new node;
    newNode->data = data;
    node *curr = head;
    if (pos == 1)
    {
        newNode->next = head;
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            curr = curr->next;
        }
        if (curr == NULL)
            insert_end(data);
        else
        {
            curr->prev->next = newNode;
            newNode->prev = curr->prev;
            curr->prev = newNode;
            newNode->next = curr;
        }
    }
}

void del_pos(int pos) {
    if (pos==1) {
        head=head->next;
    }
    else {
        node *curr=head;
        for (int i=0;i<pos-1;i++) {
            curr=curr->next;
        }
        if (curr==NULL) {
            del_end();
        }
        else {
            curr->prev->next=curr->next;
            curr->next->prev=curr->prev;
        }
    }   
}

void insert_aft(int data,int ele) {
    node *newNode=new node;
    newNode->data=data;
    node *curr=head;
    bool found=false;
    while(curr!=NULL) {
        if (curr->data==ele) {
            found=true;
            if (curr->next==NULL)
                insert_end(data);
            else {
                curr->next->prev=newNode;
                newNode->next=curr->next;
                newNode->prev=curr;
                curr->next=newNode;
            }
            break;
        }   
        curr=curr->next;
    }
    if (!found)
        cout<<"Element not found"<<endl;
}
void insert_begin(int data) {
    node *newNode=new node;
    newNode->data=data;
    newNode->prev=NULL;
    if (head==NULL) {
        newNode->next=NULL;
        head=newNode;
        tail=newNode;
    }
    else {
        newNode->next=head;
        head=newNode;
    }
}
void insert_bef(int data,int ele) {
    node *newNode=new node;
    newNode->data=data;
    node *curr=head;
    bool found=false;
    while (curr!=NULL) {
        if (curr->data==ele) {
            found=true;
            if (curr->prev==NULL)
                insert_begin(data);
            else {
                curr->prev->next=newNode;
                newNode->next=curr;
                newNode->prev=curr->prev;
                curr->prev=newNode;
            }
            break;
        }
        curr=curr->next;
    }
    if (!found)
        cout<<"Element not found"<<endl;
}

void display()
{
    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }

}

int main() {

    int opt;
    int pos, elem;
    cout << "Enter the Option:" << endl;
    cout << "1.Insert at end" << endl;
    cout << "2.Delete from end" << endl;
    cout << "3.Insert at Position" << endl;
    cout << "4.Delete from Position" << endl;
    cout << "5.Insert after another element" << endl;
    cout << "6.Insert before another element" << endl;
    cout << "7.Print the list" << endl;
    cout << "8.Exit" << endl;

    while (1) {
        cout << "\nEnter your choice:  ";
        cin >> opt;
        switch (opt) {
            case 1:
                cout << "Enter the element to insert:";
                cin >> elem;
                insert_end(elem);
                break;
            case 2:
                del_end();
                break;
            case 3:
                cout << "Enter the position:";
                cin >> pos;
                cout << "Enter the element to insert:";
                cin >> elem;
                insert_pos(elem, pos);
                break;
            case 4:
                cout << "Enter the location:";
                cin >> pos;
                del_pos(pos);
                break;
            case 5:
                cout << "Enter the element to insert after:";
                cin >> pos;
                cout << "Enter the element to insert:";
                cin >> elem;
                insert_aft(elem, pos);
                break;
            case 6:
                cout << "Enter the element to insert before:";
                cin >> pos;
                cout << "Enter the element to insert:";
                cin >> elem;
                insert_bef(elem, pos);
                break;
            case 7:
                cout << "Linked List : ";
                display();
                break;
            case 8:
                cout << "Exited!" << endl;
                exit(0);
            default:
                cout << "Invalid Choice!" << endl;
        }
    }
}