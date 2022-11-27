#include <iostream> 
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

node *insert(node *root,int data) {
    node *newNode=new node;
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    if (root==NULL) {
        root=newNode;
        return root;
    }
    if (data<root->data)
        root->left=insert(root->left,data);
    else 
        root->right=insert(root->right,data);
    return root;
}

void inorder(node *root) {
    if (root!=NULL) {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

node *search(node *root,int t) {
    if (root==NULL)
        return root;
    if (t<root->data)
        root->left=search(root->left,t);
    else if (t>=root->data)
        root->right=search(root->right,t);
    else {
        cout<<"Target Found: "<<root->data<<endl;
    }
    return root;
    
}

int main() {
    node *root=NULL;
    cout<<"Creation of BST: "<<endl;
    char ch='y';
    while (ch=='y') {
        cout<<"Enter the element: ";
        int e;
        cin>>e;
        root=insert(root,e);
        cout<<"Do you want to continue(y/n) ?"<<endl;
        cin>>ch;
    }
    cout<<"Enter element to search: ";
    int ele;
    cin>>ele;
    root=search(root,ele);

}