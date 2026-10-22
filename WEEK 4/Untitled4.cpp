#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

int main()
{
    ofstream out("input.txt");

    int value;

    cout << "Enter 5 numbers: ";

    for (int i = 0; i < 5; i++)
    {
        cin >> value;
        out << value << " ";
    }

    out.close();

    ifstream in("input.txt");

    Node* head = NULL;
    Node* temp = NULL;

    while (in >> value)
    {
        Node* newNode = new Node;

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    in.close();

    cout << endl;
    cout << "Numbers in Linked List:" << endl;

    temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "   ";
        temp = temp->next;
    }

    return 0;
}
