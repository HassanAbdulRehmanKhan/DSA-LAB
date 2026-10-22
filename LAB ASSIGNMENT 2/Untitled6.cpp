#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Add an element at the rear
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

    // Bubble Sort by swapping node data
    for (int i = 0; i < n - 1; i++) {
        Node* p = front;

        for (int j = 0; j < n - i - 1; j++) {
            if (p->data > p->next->data) {
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
            }
            p = p->next;
        }
    }

    cout << "Sorted elements: ";
    Node* p = front;

    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }

    return 0;
}
