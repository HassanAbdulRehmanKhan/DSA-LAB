#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Push an element onto the stack
void push(Node*& top, int x) {
    Node* n = new Node{x, top};
    top = n;
}

int main() {
    Node* top = NULL;
    int n, x, a[100];

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        push(top, x);
    }

    // Copy stack data into an array
    Node* p = top;
    int i = 0;

    while (p != NULL) {
        a[i++] = p->data;
        p = p->next;
    }

    // Sort array using Insertion Sort
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }

    cout << "Sorted elements: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
