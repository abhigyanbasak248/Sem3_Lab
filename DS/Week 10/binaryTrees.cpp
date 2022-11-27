#include <iostream> 
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

node *insert(node *root,int data) {
    node *newNode =new node;
    newNode->data=data;
    newNode->right=newNode->left=NULL;
    if (root==NULL) {
        root=newNode;
        return root;
    }
    node *curr=root;
    char str;
    while(curr!=NULL) {
        cout<<"Insert Left or Right(l/r) of "<<curr->data<<" ?"<<endl;
        cin>>str;
        if (str=='l') {
            if (curr->left==NULL) {
                curr->left=newNode;
                break;
            }
            else {
                curr=curr->left;
            }
        }
        else if (str=='r') {
            if (curr->right==NULL) {
                curr->right=newNode;
                break;
            }
            else {
                curr=curr->right;
            }
        }
    }
    return root;
}

void inorder(node *root) {
    if (root!=NULL) {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void postorder(node *root) {
    if (root!=NULL) {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

void preorder(node *root) {
    if (root!=NULL) {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

int cnt_leaves(node *root) {
    if (root==NULL)
        return 0;
    else if (root->left==NULL && root->right==NULL) 
        return 1;
    else 
        return (cnt_leaves(root->left)+cnt_leaves(root->right));
}

void parent(node *root,int val,int p) {
    if (root==NULL)
        return;
    else if (root->data==val) 
        cout<<p<<endl;
    else {
        parent(root->left,val,root->data);
        parent(root->right,val,root->data);
    }
}

int depth(node *root) {
    if (root==NULL)
        return 0;
    else {
        int c1=depth(root->left)+1;
        int c2=depth(root->right)+1;
        if (c1>c2)
            return c1;
        else 
            return c2;
    }
}

bool ancestors(node *root,int val) {
    if (root==NULL) 
        return false;
    if (root->data==val)
        return true;
    if (ancestors(root->left,val) || (ancestors(root->right,val))) {
        cout<<root->data<<" ";
        return true;
    }
    else 
        return false;
}

int main() {
    node *root=NULL;
    cout<<"Creation of Binary Tree:"<<endl;
    char ch='y';
    while (ch=='y') {
        cout<<"Enter element: ";
        int e;
        cin>>e;
        root=insert(root,e);
        cout<<"Do you want to continue(y/n)?"<<endl;
        cin>>ch;
    }
    int op,n;
    cout<<"1.Inorder Traversal"<<endl;
    cout<<"2.Postrder Traversal"<<endl;
    cout<<"3.Prerder Traversal"<<endl;
    cout<<"4.Count number of leaves"<<endl;
    cout<<"5.Parent of node"<<endl;
    cout<<"6.Depth of tree"<<endl;
    cout<<"7.Ancestors of tree"<<endl;
    cout<<"8.Exit"<<endl;
    while (op!=8) {
        cout<<"\nEnter choice: ";
        cin>>op;
        switch(op) {
            case 1:
                inorder(root);
                break;
            case 2:
                postorder(root);
                break;
            case 3:
                preorder(root);
                break;
            case 4:
                cout<<"Number of leaves: "<<cnt_leaves(root);
                break; 
            case 5:
                cout<<"Enter node to get parents of: ";
                cin>>n;
                parent(root,n,-1);
                break; 
            case 6:
                cout<<"Depth of tree: "<<depth(root);
                break;
            case 7:
                cout<<"Enter node to get ancestors of: ";
                cin>>n;
                cout<<"Ancestors: ";
                ancestors(root,n);
                break;
            case 8:
                cout<<"EXIT"<<endl;
                exit(0);
            default:
                cout<<"Invalid Choice"<<endl;
                break;
        }
    }
}