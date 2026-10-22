#include <iostream>
using namespace std;

struct SNode
{
    int data;
    SNode* next;
};

struct DNode
{
    int data;
    DNode* next;
    DNode* prev;
};

// Insert node in singly linked list
void insertSingly(SNode*& head, SNode*& tail, int value)
{
    SNode* newNode = new SNode;

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// Insert node in doubly linked list
void insertDoubly(DNode*& head, DNode*& tail, int value)
{
    DNode* newNode = new DNode;

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

// Display singly linked list
void displaySingly(SNode* head)
{
    SNode* current = head;

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

// Display doubly linked list
void displayDoubly(DNode* head)
{
    DNode* current = head;

    while (current != NULL)
    {
        cout << current->data << " ";
        current = current->next;
    }

    cout << endl;
}

// Convert singly linked list into doubly linked list
DNode* convertToDoubly(SNode* singlyHead, DNode*& doublyTail)
{
    DNode* doublyHead = NULL;
    doublyTail = NULL;

    SNode* current = singlyHead;

    while (current != NULL)
    {
        insertDoubly(doublyHead, doublyTail, current->data);

        current = current->next;
    }

    return doublyHead;
}

// Delete singly linked list
void deleteSingly(SNode*& head)
{
    SNode* current = head;

    while (current != NULL)
    {
        SNode* temp = current;
        current = current->next;
        delete temp;
    }

    head = NULL;
}

// Delete doubly linked list
void deleteDoubly(DNode*& head)
{
    DNode* current = head;

    while (current != NULL)
    {
        DNode* temp = current;
        current = current->next;
        delete temp;
    }

    head = NULL;
}

int main()
{
    SNode* singlyHead = NULL;
    SNode* singlyTail = NULL;

    DNode* doublyHead = NULL;
    DNode* doublyTail = NULL;

    int n;
    int value;

    cout << "===== LAB 03 - TASK 3 =====" << endl;
    cout << "Convert Singly Linked List into Doubly Linked List" << endl;

    cout << "\nEnter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " values:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        insertSingly(singlyHead, singlyTail, value);
    }

    cout << "\nOriginal Singly Linked List: ";
    displaySingly(singlyHead);

    doublyHead = convertToDoubly(singlyHead, doublyTail);

    cout << "Converted Doubly Linked List: ";
    displayDoubly(doublyHead);

    deleteSingly(singlyHead);
    deleteDoubly(doublyHead);

    return 0;
}
