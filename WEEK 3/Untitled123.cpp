#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Function to reverse a part of linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;

    while (current != NULL) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

int main() {

    // Creating nodes
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Find middle node
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Middle node is 3
    Node* middle = slow;

    // Reverse first part: 1 -> 2 becomes 2 -> 1
    Node* first = head;
    Node* prev = NULL;

    while (first != middle) {
        Node* nextNode = first->next;
        first->next = prev;
        prev = first;
        first = nextNode;
    }

    head = prev;

    // Connect 1 to middle(3)
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = middle;

    // Reverse second part: 4 -> 5 becomes 5 -> 4
    Node* second = middle->next;
    middle->next = reverseList(second);

    // Display final list
    Node* current = head;

    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}
