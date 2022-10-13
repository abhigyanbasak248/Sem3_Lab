#include <iostream>
using namespace std;

class stack
{
public:
    int arr[100], n, top;
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
    int peek()
    {
        return arr[top];
    }
    void push(int a)
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
            int x = arr[top];
            top--;
        }
    }
    void display()
    {
        if (isEmpty())
            cout << "Stack is empty";
        else
        {
            cout << "Stack elements are:"<<endl;
            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main()
{
    stack s;
    int c, a;
    cout << "Enter 1 to push" << endl;
    cout << "Enter 2 to pop" << endl;
    cout << "Enter 3 to peek" << endl;
    cout << "Enter 4 to check if stack is empty" << endl;
    cout << "Enter 5 to check if stack is full" << endl;
    cout << "Enter 6 to display stack" << endl;
    cout << "Enter 7 to exit" << endl;
    do
    {
        cout << "Enter choice: " << endl;
        cin >> c;
        switch (c)
        {
        case 1:
        {
            cout << "Enter value to push: " << endl;
            cin >> a;
            s.push(a);
            break;
        }
        case 2:
        {
            s.pop();
            break;
        }
        case 3:
        {
            cout << s.peek();
            break;
        }
        case 4:
        {
            if (s.isEmpty())
                cout << "Stack is empty" << endl;
            else
                cout << "Stack isn't empty" << endl;
            break;
        }
        case 5:
        {
            if (s.isFull())
                cout << "Stack is full" << endl;
            else
                cout << "Stack isn't full" << endl;
            break;
        }
        case 6:
        {
            s.display();
            break;
        }
        case 7:
        {
            cout << "EXIT";
            break;
        }
        default:
        {
            cout << "Invalid Choice";
        }
        }

    } while (c != 7);
    return 0;
}