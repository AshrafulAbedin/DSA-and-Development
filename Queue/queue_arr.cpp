#include <bits/stdc++.h>
using namespace std;
#define MAX 6

struct Queue
{
    int arr[MAX], front, rear;
    Queue()
    {
        front = rear = 0;
    }
    bool isEmpty()
    {
        return front == rear;
    }
    bool isFull()
    {
        return front == (rear + 1) % MAX;
    }

    void en_q(int val)
    {
        if (isFull())
        {
            cout << "Full" << '\n';
            return;
        }

        arr[rear] = val;
        rear = (rear + 1) % MAX;
        cout << "enqueued " << val << '\n';
    }

    int de_q()
    {
        if (isEmpty())
        {
            cout << "Empty" << '\n';
            return -1;
        }

        int val = arr[front];
        front = (front + 1) % MAX;
        cout << "dequeued " << val << '\n';
        return val;
    }
    int get_front()
    {
        cout << arr[front] << '\n';
        return arr[front];
    }
    int size()
    {
        cout << (rear - front + MAX) % MAX << '\n';
        return (rear - front + MAX) % MAX;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Empty" << '\n';
        }
        int i = front;
        while (i != rear)
        {
            cout << arr[i] << " ";
            i = (i + 1) % MAX;
        }
    }
};

int main(void)
{
    Queue q;
    int cmd, x;
    while (cin >> cmd && cmd != 0)
    {
        if (cmd == 1)
        {
            cin >> x;
            q.en_q(x);
        }
        else if (cmd == 2)
        {
            q.de_q();
        }
        else if (cmd == 3)
        {
            q.get_front();
        }
        else if (cmd == 4)
        {
            q.size();
        }
        else if (cmd == 5)
        {
            q.display();
        }
        else
            return 0;
    }

    return 0;
}