#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node* head;

    LinkedList()
    {
        head = NULL;
    }
    void insert(int value)
    {
        Node* newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void display()
    {
        Node* temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void reverseUsingLoop()
    {
        Node* temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        int* arr = new int[count];
        temp = head;
        for (int i = 0; i < count; i++)
        {
            arr[i] = temp->data;
            temp = temp->next;
        }
        for (int i = count - 1; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        delete[] arr;
    }
    void reverseUsingRecursion(Node* temp)
    {
        if (temp == NULL)
        {
            return;
        }
        reverseUsingRecursion(temp->next);
        cout << temp->data << " ";
    }
};
int main()
{
    LinkedList list;
    list.insert(2);
    list.insert(4);
    list.insert(6);
    list.insert(8);
    list.insert(10);
    cout << "Original List: ";
    list.display();
    cout << "Reverse using Loop: ";
    list.reverseUsingLoop();
    cout << "Reverse using Recursion: ";
    list.reverseUsingRecursion(list.head);
    return 0;
}


