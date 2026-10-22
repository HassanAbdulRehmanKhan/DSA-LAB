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

// Search a node by value
Node* searchNode(Node* head, int value)
{
    Node* current = head;

    while (current != NULL)
    {
        if (current->data == value)
        {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

// Swap two actual nodes
void swapNodes(Node*& head, Node*& tail, int value1, int value2)
{
    Node* node1 = searchNode(head, value1);
    Node* node2 = searchNode(head, value2);

    // Check whether both values exist
    if (node1 == NULL || node2 == NULL)
    {
        cout << "\nOne or both values were not found." << endl;
        return;
    }

    // Same node
    if (node1 == node2)
    {
        cout << "\nBoth values belong to the same node." << endl;
        return;
    }

    // Make node1 appear before node2
    if (node1->next == node2)
    {
        // node1 and node2 are adjacent
        Node* before = node1->prev;
        Node* after = node2->next;

        if (before != NULL)
            before->next = node2;
        else
            head = node2;

        if (after != NULL)
            after->prev = node1;
        else
            tail = node1;

        node2->prev = before;
        node2->next = node1;

        node1->prev = node2;
        node1->next = after;
    }
    else if (node2->next == node1)
    {
        // node2 and node1 are adjacent
        Node* before = node2->prev;
        Node* after = node1->next;

        if (before != NULL)
            before->next = node1;
        else
            head = node1;

        if (after != NULL)
            after->prev = node2;
        else
            tail = node2;

        node1->prev = before;
        node1->next = node2;

        node2->prev = node1;
        node2->next = after;
    }
    else
    {
        // Nodes are not adjacent
        Node* node1Prev = node1->prev;
        Node* node1Next = node1->next;

        Node* node2Prev = node2->prev;
        Node* node2Next = node2->next;

        // Put node2 where node1 was
        if (node1Prev != NULL)
            node1Prev->next = node2;
        else
            head = node2;

        if (node1Next != NULL)
            node1Next->prev = node2;

        node2->prev = node1Prev;
        node2->next = node1Next;

        // Put node1 where node2 was
        if (node2Prev != NULL)
            node2Prev->next = node1;
        else
            head = node1;

        if (node2Next != NULL)
            node2Next->prev = node1;

        node1->prev = node2Prev;
        node1->next = node2Next;

        // Update tail
        if (node1Next == NULL)
            tail = node2;

        if (node2Next == NULL)
            tail = node1;
    }

    cout << "\nNodes swapped successfully." << endl;
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
    int value1;
    int value2;

    cout << "===== LAB 03 - TASK 2 =====" << endl;
    cout << "Swap Two Nodes in a Doubly Linked List" << endl;

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

    cout << "\nEnter first value: ";
    cin >> value1;

    cout << "Enter second value: ";
    cin >> value2;

    swapNodes(head, tail, value1, value2);

    cout << "\nDoubly Linked List after swapping nodes: ";
    display(head);

    deleteList(head);

    return 0;
}
