#include <iostream>
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

    void findOccurrences(int value)
    {
        Node* temp = head;
        int position = 1;
        bool found = false;

        while (temp != NULL)
        {
            if (temp->data == value)
            {
                cout << value << " found at position "
                     << position << endl;

                found = true;
            }

            temp = temp->next;
            position++;
        }

        if (found == false)
        {
            cout << value << " not found in the list." << endl;
        }
    }
};

int main()
{
    LinkedList list;

    list.insert(45);
    list.insert(50);
    list.insert(55);
    list.insert(60);
    list.insert(65);
    list.insert(70);

    cout << "Linked List: ";
    list.display();

    int value;

    cout << "Enter value to search: ";
    cin >> value;

    list.findOccurrences(value);

    return 0;
}
