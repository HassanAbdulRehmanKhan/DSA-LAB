#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, int x) {
    Node* n = new Node{x, NULL};

    if (rear == NULL)
        front = rear = n;
    else {
        rear->next = n;
        rear = n;
    }
}

int main() {
    Node *front = NULL, *rear = NULL;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        enqueue(front, rear, x);
    }

    // Selection Sort by swapping node data
    for (Node* p = front; p != NULL; p = p->next) {
        Node* minNode = p;

        for (Node* q = p->next; q != NULL; q = q->next) {
            if (q->data < minNode->data)
                minNode = q;
        }

        int temp = p->data;
        p->data = minNode->data;
        minNode->data = temp;
    }

    cout << "Sorted elements: ";
    Node* p = front;

    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }

    return 0;
}
