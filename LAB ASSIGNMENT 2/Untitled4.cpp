#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct Queue {
    Node *front = NULL, *rear = NULL;
};

// Insert an element into a queue
void enqueue(Queue& q, int x) {
    Node* n = new Node{x, NULL};

    if (q.rear == NULL)
        q.front = q.rear = n;
    else {
        q.rear->next = n;
        q.rear = n;
    }
}

// Remove an element from a queue
int dequeue(Queue& q) {
    Node* temp = q.front;
    int x = temp->data;

    q.front = q.front->next;

    if (q.front == NULL)
        q.rear = NULL;

    delete temp;
    return x;
}

void push(Queue& q1, Queue& q2, int x) {
    enqueue(q2, x);

    while (q1.front != NULL)
        enqueue(q2, dequeue(q1));

    Queue temp = q1;
    q1 = q2;
    q2 = temp;
}

void pop(Queue& q1) {
    if (q1.front == NULL) {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Popped: " << dequeue(q1) << endl;
}

int main() {
    Queue q1, q2;

    push(q1, q2, 10);
    push(q1, q2, 20);
    push(q1, q2, 30);

    pop(q1);
    pop(q1);

    return 0;
}
