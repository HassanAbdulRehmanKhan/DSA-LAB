
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

// Insert a new node at the end of the list
void insertAtEnd(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    // Make the new node the first node if list is empty
    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;

    // Move to the last node
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Display the linked list
void display(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Find the middle node using slow and fast pointers
Node* findMiddle(Node* head) {
    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    // Slow moves one step and fast moves two steps
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Slow points to the middle node
    return slow;
}

// Check whether the linked list contains a cycle
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    // Move both pointers at different speeds
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // Both pointers meet if a cycle exists
        if(slow == fast)
            return true;
    }

    // Fast reaches NULL when there is no cycle
    return false;
}

int main() {
    // Create a linked list by inserting values at the end
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtEnd(60);
    insertAtEnd(70);

    cout << "Linked List: ";
    display(head);

    // Find and print the middle node
    Node* middle = findMiddle(head);

    if(middle != NULL)
        cout << "Middle Node: " << middle->data << endl;

    // Check the list before creating a cycle
    cout << "Cycle before linking: ";

    if(hasCycle(head))
        cout << "Yes\n";
    else
        cout << "No\n";

    // Find the last node
    Node* last = head;

    while(last->next != NULL) {
        last = last->next;
    }

    // Connect the last node back to node 30
    Node* earlier = head->next->next;
    last->next = earlier;

    // Check the list after creating a cycle
    cout << "Cycle after linking: ";

    if(hasCycle(head))
        cout << "Yes\n";
    else
        cout << "No\n";

    // Remove the cycle before deleting the nodes
    last->next = NULL;

    // Delete all nodes to free the memory
    while(head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

