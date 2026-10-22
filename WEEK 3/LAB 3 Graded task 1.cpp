#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};

// Insert node at the end
void insertNode(Node*& head, Node*& tail, int value)
{
    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Display list
void display(Node* head)
{
    Node* current = head;

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

// Reverse doubly linked list
void reverseList(Node*& head, Node*& tail)
{
    Node* current = head;
    Node* temp;

    while (current != NULL)
    {
        temp = current->next;

        current->next = current->prev;
        current->prev = temp;

        current = temp;
    }

    temp = head;
    head = tail;
    tail = temp;
}

// Delete list
void deleteList(Node*& head)
{
    Node* current = head;

    while (current != NULL)
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    head = NULL;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int n;
    int value;

    cout << "===== LAB 03 - TASK 1 =====" << endl;
    cout << "Reverse a Doubly Linked List" << endl;

    cout << "\nEnter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        insertNode(head, tail, value);
    }

    cout << "\nOriginal Doubly Linked List: ";
    display(head);

    reverseList(head, tail);

    cout << "Reversed Doubly Linked List: ";
    display(head);

    deleteList(head);

    return 0;
}
