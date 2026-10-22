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

    LinkedList merge(LinkedList& list2)
    {
        LinkedList newList;

        Node* temp = head;

        while (temp != NULL)
        {
            newList.insert(temp->data);
            temp = temp->next;
        }

        temp = list2.head;

        while (temp != NULL)
        {
            newList.insert(temp->data);
            temp = temp->next;
        }

        return newList;
    }
};   // <-- Yahan semicolon missing tha

int main()
{
    LinkedList list1;
    LinkedList list2;

    list1.insert(1);
    list1.insert(2);
    list1.insert(3);

    list2.insert(4);
    list2.insert(5);
    list2.insert(6);

    cout << "First List: ";
    list1.display();

    cout << "Second List: ";
    list2.display();

    LinkedList list3 = list1.merge(list2);

    cout << "Merged List: ";
    list3.display();

    return 0;
}
