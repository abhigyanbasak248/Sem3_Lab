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
    void display()
    {
        if (isEmpty())
            cout << "Stack is empty";
        else
        {
            cout << "Stack elements are:";
            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main()
{
    string c;
    cout << "Enter a string: ";
    cin >> c;
    int n = c.length(), i, flag = 1;
    stack s;
    for (i = 0; i < n / 2; i++)
        s.push(c[i]);
    if (n % 2 != 0)
        ++i;
    char e;
    while (c[i] != '\0')
    {
        e = s.peek();
        s.pop();
        if (e != c[i])
        {
            flag = 0;
            break;
        }
        i++;
    }
    if (flag == 1)
        cout << "Palindrome";
    else
        cout << "Not palindrome";
    return 0;
}