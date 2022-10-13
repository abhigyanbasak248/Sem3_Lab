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
};