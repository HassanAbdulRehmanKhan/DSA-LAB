#include <iostream>
using namespace std;

int q1[100], q2[100];
int n1 = 0, n2 = 0;

// Push an element using two queues
void push(int x) {
    q2[0] = x;
    n2 = 1;

    for (int i = 0; i < n1; i++)
        q2[n2++] = q1[i];

    for (int i = 0; i < n2; i++)
        q1[i] = q2[i];

    n1 = n2;
    n2 = 0;
}

// Remove the top element
void pop() {
    if (n1 == 0) {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Popped: " << q1[0] << endl;

    for (int i = 0; i < n1 - 1; i++)
        q1[i] = q1[i + 1];

    n1--;
}

int main() {
    push(10);
    push(20);
    push(30);

    pop();
    pop();

    return 0;
}
