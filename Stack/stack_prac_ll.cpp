#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

struct Stack
{
    Node *top;
    int sz;
    Stack()
    {
        sz = 0;
        top = nullptr;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
    void push(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = top;
        top = newNode;
        sz++;

        cout << "pushed hard! " << top->data << '\n';
    }
    int pop()
    {
        if (isEmpty())
        {
            cout << "Kisu nai reh" << '\n';
            return -1;
        }
        Node *temp = top;
        cout << "popped this criminal " << temp->data << '\n';
        top = top->next;
        delete temp;
        sz--;
        return top->data;
    }
    int peek()
    {
        cout << "peek 00 " << top->data << '\n';
        return top->data;
    }
    int size()
    {
        cout<< sz <<'\n';
        return sz <= 0 ? -1 : sz;
    }
    void display()
    {
        Node *curr = top;
        if (!top)
        {
            cout << "Empty" << '\n';
        }
        while (curr)
        {
            cout << curr->data << '\n';
            curr = curr->next;
        }
    }
};

// driver code
int main(void)
{
    Stack s;
    string cmd;
    int x;
    while (cin >> cmd && cmd != "q")
    {
        if (cmd == "push")
        {
            cin >> x;
            s.push(x);
        }
        else if (cmd == "pop")
        {
            s.pop();
        }
        else if (cmd == "peek")
        {
            s.peek();
        }
        else if (cmd == "size")
        {
            s.size();
        }
        else if (cmd == "show")
        {
            s.display();
        }
        else
            return 0;
    }

    return 0;
}