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

struct sll
{
    Node *head;
    sll()
    {
        head = nullptr;
    }

    void insertAtHead(int val)
    {
        Node *n = new Node(val);
        if (!head)
        {
            head = n;
            return;
        }
        n->next = head;
        head = n;
    }

    void insertAtTail(int val)
    {
        Node *n = new Node(val);
        if (!head)
        {
            head = n;
            return;
        }

        Node *curr = head;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = n;
        n->next = nullptr;
    }
    void insertAfter(int x, int val)
    {
        Node *n = new Node(val);
        if (!head)
        {
            cout << x << " Not found\n";
            delete n;
            return;
        }
        Node *curr = head;
        while (curr && curr->data != x)
            curr = curr->next;

        if (curr)
        {
            n->next = curr->next;
            curr->next = n;
        }
        else
        {
            cout << x << " Not Found\n";
            delete n;
        }
    }

    int deleteVal(int val)
    {
        if (!head)
            return -1;

        if (head->data == val)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return val;
        }

        Node *t = head;
        while (t->next && t->next->data != val)
            t = t->next;

        if (t->next && t->next->data == val)
        {
            Node *temp = t->next;
            t->next = temp->next;
            delete temp;
            return val;
        }
        return -1;
    }

    Node *search(int key)
    {
        Node *curr = head;
        while (curr && curr->data != key)
            curr = curr->next;
        return curr;
    }

    int update(int key, int val)
    {
        Node *temp = search(key);
        if (temp)
            return temp->data = val;
        return -1;
    }

    void display()
    {
        Node *curr = head;
        while (curr)
        {
            cout << curr->data << "->";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
};

int main(void)
{
    sll list;

    cout << "Commands: 1=InsertHead  2=InsertTail  3=InsertAfter(x,val)\n"
         << "          4=Delete(x)   5=Search(x)   6=Update(x,val)\n"
         << "          7=Display     0=Exit\n";

    int cmd, x, y;
    while (cin >> cmd && cmd != 0)
    {
        if (cmd == 1)
        {
            cin >> x;
            list.insertAtHead(x);
        }
        else if (cmd == 2)
        {
            cin >> x;
            list.insertAtTail(x);
        }
        else if (cmd == 3)
        {
            cin >> x >> y;
            list.insertAfter(x, y);
        }
        else if (cmd == 4)
        {
            cin >> x;
            int res = list.deleteVal(x);
            if (res == -1) cout << x << " Not found\n";
            else cout << "Deleted " << res << "\n";
        }
        else if (cmd == 5)
        {
            cin >> x;
            Node *res = list.search(x);
            if (res) cout << "Found: " << res->data << "\n";
            else cout << x << " Not found\n";
        }
        else if (cmd == 6)
        {
            cin >> x >> y;
            int res = list.update(x, y);
            if (res == -1) cout << x << " Not found\n";
            else cout << "Updated to " << res << "\n";
        }
        else if (cmd == 7)
        {
            list.display();
        }
    }

    return 0;
}