#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
#define mii map <int,int>
#define llu unsigned long long 
#define lld long long 

class Node{
    public:
    int key, height;
    Node *left, *right, *parent;
    Node(int k)
    {
        key = k, height = 0;
        left = right = parent = nullptr;
    }
};

Node *root = nullptr;

int getHeight(Node* n)
{
    return n ? n->height : -1;
}

int recomputeHeight(Node* n)
{
    if (!n)
    {
        return -1;
    }
    n->height = 1 + max(recomputeHeight(n->left), recomputeHeight(n->right));
    return n->height;
}

void inorder(Node* n)
{
    if (!n)
    {
        return;
    }
    inorder(n->left);
    cout<< n->key <<" ";
    inorder(n->right);
}
void printInorder() { inorder(root); cout << "\n"; }
Node* search(int val) {
    Node* c = root;
    while (c) {
        if (val == c->key) return c;
        c = (val < c->key) ? c->left : c->right;
    }
    return nullptr;
}

void insert(int val) {
    Node* n = new Node(val);
    if (!root) { root = n; return; }
    Node* curr = root, *par = nullptr;
    while (curr) {
        par = curr;
        if (val < curr->key) curr = curr->left;
        else if (val > curr->key) curr = curr->right;
        else { delete n; return; }
    }
    n->parent = par;
    if (val < par->key) par->left = n; else par->right = n;
    recomputeHeight(root);
}
Node* deleteNode(Node* r, int val) {
    if (!r) return nullptr;
    if (val < r->key) {
        r->left = deleteNode(r->left, val);
        if (r->left) r->left->parent = r;
    } else if (val > r->key) {
        r->right = deleteNode(r->right, val);
        if (r->right) r->right->parent = r;
    } else {
        if (!r->left)  { Node* t = r->right; delete r; return t; }
        if (!r->right) { Node* t = r->left;  delete r; return t; }
        Node* succ = r->right;
        while (succ->left) succ = succ->left;
        r->key = succ->key;
        r->right = deleteNode(r->right, succ->key);
        if (r->right) r->right->parent = r;
    }
    return r;
}

void deleteKey(int val) {
    if (!search(val)) { cout << "Value not found\n"; printInorder(); return; }
    root = deleteNode(root, val);
    if (root) root->parent = nullptr;
    recomputeHeight(root);
    printInorder();
}

int main(void)
{
    
    return 0;
}