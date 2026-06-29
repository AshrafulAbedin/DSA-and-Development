#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    int height;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        height = 1;
        left = right = nullptr;
    }
};

class AVL
{
public:
    int height_(Node *n)
    {
        return n ? n->height : 0;
    }

    void updateHeight(Node *n)
    {
        if (n)
        {
            n->height = 1 + max(height_(n->left), height_(n->right));
        }
    }

    int getBF(Node *n)
    {
        return n ? height_(n->left) - height_(n->right) : 0;
    }

    Node *rightRot(Node *z)
    {
        Node *y = z->left;
        Node *T3 = y->right;

        y->right = z;
        z->left = T3;

        updateHeight(z);
        updateHeight(y);

        return y;
    }

    Node *leftRot(Node *z)
    {
        Node *y = z->right;
        Node *T2 = y->left;

        y->left = z;
        z->right = T2;

        updateHeight(z);
        updateHeight(y);

        return y;
    }

    Node *balance(Node *n)
    {
        updateHeight(n);

        int bf = getBF(n);

        // LL or LR
        if (bf > 1)
        {
            if (getBF(n->left) < 0)
            {
                n->left = leftRot(n->left); // LR
            }
            return rightRot(n); // LL
        }

        // RR or RL
        if (bf < -1)
        {
            if (getBF(n->right) > 0)
            {
                n->right = rightRot(n->right); // RL
            }
            return leftRot(n); // RR
        }

        return n;
    }

    Node *insert(Node *n, int val)
    {
        if (!n)
        {
            return new Node(val);
        }

        if (val < n->data)
        {
            n->left = insert(n->left, val);
        }
        else if (val > n->data)
        {
            n->right = insert(n->right, val);
        }
        else
        {
            return n; 
        }

        return balance(n);
    }

    Node *search(Node *n, int val)
    {
        if (!n)
        {
            return nullptr;
        }

        if (n->data == val)
        {
            return n;
        }

        if (val < n->data)
        {
            return search(n->left, val);
        }

        return search(n->right, val);
    }

    void inorder(Node *n)
    {
        if (!n)
            return;

        inorder(n->left);
        cout << n->data << " ";
        inorder(n->right);
    }

    void preorder(Node *n)
    {
        if (!n)
            return;

        cout << n->data << " ";
        preorder(n->left);
        preorder(n->right);
    }
};

int main()
{
    AVL tree;
    Node *root = nullptr;

    cout << "Commands:\n";
    cout << "  1 X  - Insert X\n";
    cout << "  2 X  - Search X\n";
    cout << "  3    - Inorder Traversal\n";
    cout << "  4    - Preorder Traversal\n";
    cout << "  5 X  - Height of Node X\n";
    cout << "  6 X  - Balance Factor of Node X\n";
    cout << "  0    - Exit\n\n";

    int cmd;

    while (cin >> cmd && cmd != 0)
    {
        if (cmd == 1)
        {
            int x;

            root = tree.insert(root, (cin >> x, x));

            cout << "Inserted " << x << ". Inorder: ";
            tree.inorder(root);
            cout << "\n";
        }
        else if (cmd == 2)
        {
            int x;
            cin >> x;

            Node *found = tree.search(root, x);

            if (found)
            {
                cout << x << " Found. Height: "
                     << found->height - 1
                     << ", BF: "
                     << tree.getBF(found)
                     << "\n";
            }
            else
            {
                cout << x << " Not Found.\n";
            }
        }
        else if (cmd == 3)
        {
            cout << "Inorder: ";
            tree.inorder(root);
            cout << "\n";
        }
        else if (cmd == 4)
        {
            cout << "Preorder: ";
            tree.preorder(root);
            cout << "\n";
        }
        else if (cmd == 5)
        {
            int x;
            cin >> x;

            Node *found = tree.search(root, x);

            if (found)
            {
                cout << "Height of " << x << ": "
                     << found->height - 1 << "\n";
            }
            else
            {
                cout << x << " Not Found.\n";
            }
        }
        else if (cmd == 6)
        {
            int x;
            cin >> x;

            Node *found = tree.search(root, x);

            if (found)
            {
                cout << "BF of " << x << ": "
                     << tree.getBF(found) << "\n";
            }
            else
            {
                cout << x << " Not Found.\n";
            }
        }
        
        else
        {
            cout << "Unknown Command.\n";
        }
    }

    cout << "Exiting...\n";
    return 0;
}