
#include<iostream>
using namespace std;

class Stack {
    int arr[100];
    int topIndex;

public:
    Stack() {
        topIndex = -1;  // Stack is empty at the start
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == 99;
    }

    void push(int x) {
        if(isFull()) {
            cout << "Stack is full\n";
            return;
        }

        arr[++topIndex] = x;  // Add value at the top
    }

    int pop() {
        if(isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }

        return arr[topIndex--];  // Remove the top value
    }

    int top() {
        if(isEmpty())
            return -1;

        return arr[topIndex];  // Return top value without removing it
    }

    void display() {
        cout << "[ ";
        for(int i = 0; i <= topIndex; i++)
            cout << arr[i] << " ";
        cout << "]\n";
    }
};

class MyQueue {
    Stack s1, s2;  // These two stacks are used to make a queue

public:
    void enqueue(int x) {
        s1.push(x);  // Add new value to the first stack
    }

    int dequeue() {
        // Move values only when the second stack is empty
        if(s2.isEmpty()) {
            while(!s1.isEmpty())
                s2.push(s1.pop());
        }

        if(s2.isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        return s2.pop();  // Remove the oldest value
    }

    int front() {
        // Prepare the second stack if it is empty
        if(s2.isEmpty()) {
            while(!s1.isEmpty())
                s2.push(s1.pop());
        }

        if(s2.isEmpty())
            return -1;

        return s2.top();  // Show the first queue value
    }

    bool isEmpty() {
        return s1.isEmpty() && s2.isEmpty();
    }

    void display() {
        cout << "s1 (bottom to top): ";
        s1.display();

        cout << "s2 (bottom to top): ";
        s2.display();
    }
};

int main() {
    MyQueue q;

    q.enqueue(15);
    q.display();

    q.enqueue(25);
    q.display();

    q.enqueue(35);
    q.display();

    cout << "Removed: " << q.dequeue() << endl;
    q.display();

    q.enqueue(45);
    q.display();

    cout << "Front value: " << q.front() << endl;
    q.display();

    cout << "Removed: " << q.dequeue() << endl;
    q.display();

    return 0;
}

