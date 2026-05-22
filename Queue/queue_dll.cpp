#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = prev = nullptr;
    }
};

struct queue_dll
{
    Node *front, *rear;
    int sz;
    queue_dll()
    {
        front = rear = nullptr;
        sz = 0;
    }
    bool isEmpty()
    {
        return front == nullptr;
    }
    void push_front(int val)
    {
        Node *n = new Node(val);
        if (isEmpty())
        {
            front = rear = n;
        }
        else
        {
            n->next = front;
            front->prev = n;
            front = n;
        }
        sz++;
        cout << "Done!" << '\n';
    }
    void push_back(int val)
    {
        Node *n = new Node(val);
        if (isEmpty())
        {
            front = rear = n;
        }
        else
        {
            rear->next = n;
            n->prev = rear;
            rear = n;
        }
        sz++;
        cout << "Done!" << '\n';
    }
    int pop_front()
    {
        if (isEmpty())
        {
            cout << -1 << '\n';
            return -1;
        }
        else
        {
            Node *temp = front;
            int val = front->data;
            front = front->next;
            if (front)
            {
                front->prev = nullptr;
            }
            else
            {
                rear = nullptr;
            }

            delete temp;
            sz--;
            return val;
        }
    }
    int pop_back()
    {
        if (isEmpty())
        {
            cout << -1 << '\n';
            return -1;
        }
        else
        {
            Node *temp = rear;
            int val = rear->data;
            rear = rear->prev;
            if (rear)
            {
                rear->next = nullptr;
            }
            else
            {
                front = nullptr;
            }

            delete temp;
            sz--;
            return val;
        }
    }
    int get_front()
    {
        if (isEmpty())
        {
            return -1;
        }
        return front->data;
    }
    int get_rear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return rear->data;
    }
    int size()
    {
        return sz;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << '\n';
            return;
        }
        Node *cur = front;
        while (cur)
        {
            cout << cur->data;
            if (cur->next) cout << " <-> ";
            cur = cur->next;
        }
        cout << '\n';
    }
};

int main(void)
{
    queue_dll q;
    int cmd, x;
    while (cin >> cmd)
    {
        if (cmd == 1)
        {
            cin >> x;
            q.push_front(x);
        }
        else if (cmd == 2)
        {
            cin >> x;
            q.push_back(x);
        }
        else if (cmd == 3)
        {
            cout << q.pop_front() << '\n';
        }
        else if (cmd == 4)
        {
            cout << q.pop_back() << '\n';
        }
        else if (cmd == 5)
        {
            cout << q.get_front() << '\n';
        }
        else if (cmd == 6)
        {
            cout << q.get_rear() << '\n';
        }
        else if (cmd == 7)
        {
            cout << q.size() << '\n';
        }
        else if (cmd == 8)
        {
            q.display();
        }
    }

    return 0;
}