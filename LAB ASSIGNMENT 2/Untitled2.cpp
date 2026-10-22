#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node *top1 = NULL, *top2 = NULL;

// Push an element into a stack
void push(Node*& top, int x) {
    Node* n = new Node{x, top};
    top = n;
}

// Pop an element from a stack
int pop(Node*& top) {
    int x = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return x;
}

void enqueue(int x) {
    push(top1, x);
}

void dequeue() {
    if (top1 == NULL && top2 == NULL) {
        cout << "Queue is empty\n";
        return;
    }

    if (top2 == NULL) {
        while (top1 != NULL)
            push(top2, pop(top1));
    }

    cout << "Deleted: " << pop(top2) << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    dequeue();
    dequeue();

    return 0;
}
