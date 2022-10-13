#include <iostream>
using namespace std;

class stack
{
public:
    char arr[100], n, top;
    stack()
    {
        top = -1;
        n = 100;
    }
    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
    bool isFull()
    {
        if (top == n - 1)
            return true;
        else
            return false;
    }
    char peek()
    {
        return arr[top];
    }
    void push(char a)
    {
        if (isFull())
            cout << "Stack overflow";
        else
        {
            top++;
            arr[top] = a;
        }
    }
    void pop()
    {
        if (isEmpty())
            cout << "Stack Underflow\n";
        else
        {
            char x = arr[top];
            top--;
        }
    }
};

int main() {
    stack s;
    cout<<"Enter expression: "<<endl;
    string c;
    cin>>c;
    int n=c.length();
    for (int i=0;i<n;i++) {
        if (c[i]=='(' || c[i]=='{' || c[i]=='[' || c[i]==')' || c[i]=='}' || c[i]==']') {
            if ((s.peek()=='(' && c[i]==')' )
            || (s.peek()=='{' && c[i]=='}' )
            || (s.peek()=='[' && c[i]==']' )) {
                s.pop();
            }
            else 
                s.push(c[i]);
        }
    }
    if (s.isEmpty()) 
        cout<<"Valid"<<endl;
    else
        cout<<"Invalid"<<endl;

}