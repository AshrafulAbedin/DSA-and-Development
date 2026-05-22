#include <bits/stdc++.h>
using namespace std;

bool isValid(string expr)
{
    stack<char> st;
    for(char ch : expr)
    {
        if(ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else 
        {
            if(st.empty())
            {
                return false;
            }
            char top = st.top();
            st.pop();
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '['))
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main(void)
{
    string expr;
    getline(cin, expr);
    if (isValid(expr))
    {
        cout<< "Valid" <<'\n';
    }
    else  
        cout<< "Not Valid" <<'\n';
    
    return 0;
}