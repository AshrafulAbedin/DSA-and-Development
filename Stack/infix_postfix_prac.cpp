#include <bits/stdc++.h>
using namespace std;

bool isOP(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
int prec(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    if (ch == '*' || ch == '/')
    {
        return 2;
    }
    if (ch == '^')
    {
        return 3;
    }
    return 0;
}

string infix_to_postfix(string expr)
{
    stack<char> st;
    string res ="";
    for (int i = 0; i < expr.size(); i++)
    {
        char ch = expr[i];

        if (isdigit(ch))
        {
            while (i < expr.size() && isdigit(expr[i]))
            {
               res += expr[i];
               i++;
            }
            res +=" ";
            i--;
            
        }

        else if(ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {          
                    res += st.top();
                    res += " ";
                    st.pop();
                
            }
            if (st.top() == '(')
            {
                st.pop();
            }
            
        }
        else if (isOP(ch))
        {
            while (!st.empty() && st.top() != '(' &&
                   (prec(st.top()) > prec(ch) || (prec(st.top()) == prec(ch) && ch != '^')))
            {
                res += st.top();
                res += " ";
                st.pop();
            }
            st.push(ch);
            
        }
        
        
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
        res += " ";
    }
    
    return res;
}

int main(void)
{
    string expr;
    getline(cin, expr);
    cout<< infix_to_postfix(expr) <<'\n';

    return 0;
}