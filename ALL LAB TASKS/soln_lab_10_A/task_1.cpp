#include <bits/stdc++.h>
using namespace std;

struct Queue{
    int arr[5];
    int top, rear;
    Queue()
    {
        top = rear = -1;
    }

    void enq(int x)
    {
        if (top>5)
        {
            cout<< "Overflow" <<'\n';
        }
        
        arr[++top] = x;
        cout<< "Enqueued " << x <<'\n';
    }
    int dq()
    {
        if (top<0)
        {
            cout<< "Underflow" <<'\n';
            return -1;
        }
        
    }

};

int main(void)
{
    
    return 0;
}