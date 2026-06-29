#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
class TrieNode
{
public:
    TrieNode *children[26];
    bool isEnd;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
            isEnd = false;
        }
    }
};

class trie
{
public:
    TrieNode *root = new TrieNode();

    void insert(string w)
    {
        TrieNode *curr = root;
        for (char ch : w)
        {
            int i = ch - 'a';
            if (!curr->children[i])
            {
                curr->children[i] = new TrieNode();
            }

            curr = curr->children[i];
        }
        curr->isEnd = true;
    }
    bool search(string w)
    {
        TrieNode *curr = root;
        for (char ch : w)
        {
            int i = ch - 'a';

            if (!curr->children[i])
            {
                return false;
            }
            curr = curr->children[i];
        }
        return curr->isEnd;
    }

    bool startWith(string p)
    {
        TrieNode *curr = root;
        for (char ch : p)
        {
            int i = ch - 'a';
            if (!curr->children[i])
            {
                return false;
            }
            curr = curr->children[i];
        }
        return true;
    }

    string findroot(string w)
    {
        TrieNode *curr = root;
        string prefix = "";
        for (char ch : w)
        {
            int i = ch - 'a';
            if (!curr->children[i])
            {
                return w;
            }
            curr = curr->children[i];
            prefix += ch;
            if (curr->isEnd)
            {
                return prefix;
            }
        }
        return w;
    }
};

int main(void)
{

    trie t;
    int type;
    while (cin>>type)
    {
        string w;
        if (type == 0)
        {
            return 0;
        }
        else if (type == 1)
        {
            cin >> w;
            t.insert(w);
        }
        else if (type == 2)
        {
            cin >> w;
            cout<< (t.search(w) ? "True" : "False") <<'\n';
        }
        else if (type == 3)
        {
            cin >> w;
            cout<< (t.startWith(w) ? "True" : "False") <<'\n';
        }
        
        
    }
    
    return 0;
}