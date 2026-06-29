#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

struct DLL
{
    Node *head = nullptr;

    void insertAtHead(int val)
    {
        
    }

    void insertAtTail(int val)
    {
        
    }

    void insertAfter(int x, int val)
    {
        
    }

    void deleteVal(int val)
    {
        
    }

    void displayForward()
    {
        
    }

    void displayBackward()
    {
        
    }
};

int main()
{
    DLL dll;
    int cmd;
    int x, y;

    cout << "1. Insert at Head\n2. Insert at Tail\n3. Insert After\n4. Delete\n5. Display Forward\n6. Display Backward\n0. Exit\n";
    while (cin >> cmd)
    {
        if (cmd == 1)
        {
            cin >> x;
            dll.insertAtHead(x);
        }
        else if (cmd == 2)
        {
            cin >> x;
            dll.insertAtTail(x);
        }
        else if (cmd == 3)
        {
            cin >> x >> y;
            dll.insertAfter(x, y);
        }
        else if (cmd == 4)
        {
            cin >> x;
            dll.deleteVal(x);
        }
        else if (cmd == 5)
        {
            dll.displayForward();
        }
        else if (cmd == 6)
        {
            dll.displayBackward();
        }
        else if (cmd == 0)
        {
            break;
        }
        else
            cout << "Invalid option\n";
    }

    return 0;
}