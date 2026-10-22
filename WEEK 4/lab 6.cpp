#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> q1, q2;
stack<int> s;

// Insert data into Queue
void enqueue(int x)
{
    q1.push(x);
}

// Remove data from Queue 1
void dequeue()
{
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }
}

// Insert data into Stack
void push()
{
    while (!q2.empty())
    {
        s.push(q2.front());
        q2.pop();
    }
}

// Remove data from Stack
void pop()
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();
    push();
    pop();

    return 0;
}
