#include <bits/stdc++.h>
using namespace std;

#define MAX 100

struct Stack
{
    int arr[MAX], top;
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == MAX - 1;
    }
    void push(int val)
    {
        if (isFull())
        {
            cout << "FULL" << '\n';
            return;
        }
        arr[++top] = val;
        cout << "Pushed " << val << '\n';
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Empty :(" << '\n';
            return -1;
        }
        cout << "popped " << arr[top] << '\n';
        return arr[top--];
    }

    int peek()
    {
        if (isEmpty())
        {
            return -1;
        }
        cout << arr[top] << '\n';
        return arr[top];
    }

    int size()
    {
        cout << top + 1 << '\n';
        return top + 1;
    }
    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
};

// Driver code
int main(void)
{
    Stack s;
    int cmd, x;

    while (cin >> cmd && cmd != 0)
    {
        if (cmd == 1)
        {
            cin >> x;
            s.push(x);
        }
        else if (cmd == 2)
        {
            s.pop();
        }
        else if (cmd == 3)
        {
            s.peek();
        }
        else if (cmd == 4)
        {
            s.size();
        }
        else if (cmd == 5)
        {
            s.display();
        }
        else
            return 0;
    }

    return 0;
}