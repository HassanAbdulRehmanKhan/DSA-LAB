#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
void displayReverse(Node* head)
{
    if (head == NULL)
        return;
    // Recursively reach the last node first
    displayReverse(head->next);
    // Display nodes while returning from recursion
    cout << head->data << " ";
}
int main()
{
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* fourth = new Node;

    // Create and connect the linked list
    head->data = 10;
    head->next = second;
    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;

    cout << "Original List: ";
    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
    // Display the list in reverse without changing its structure
    cout << "Reverse Display: ";
    displayReverse(head);

    cout << endl;
    return 0;
}

