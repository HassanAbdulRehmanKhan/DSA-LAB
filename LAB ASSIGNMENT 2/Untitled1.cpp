#include <iostream>
using namespace std;

int s1[100], s2[100];
int top1 = -1, top2 = -1;

// Insert an element into the stack
void push1(int x) {
    s1[++top1] = x;
}

// Remove an element from the stack
int pop1() {
    return s1[top1--];
}

void enqueue(int x) {
    push1(x);
}

void dequeue() {
    if (top1 == -1 && top2 == -1) {
        cout << "Queue is empty\n";
        return;
    }

    if (top2 == -1) {
        while (top1 != -1)
            s2[++top2] = pop1();
    }

    cout << "Deleted: " << s2[top2--] << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();
    dequeue();

    return 0;
}
