#include <iostream>
#include <stack>
using namespace std;

// This function returns operator priority
int priority(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '^')
        return 3;

    return 0;
}

int main()
{
    string infix;
    stack<char> s;
    string postfix = "";

    cout << "Enter infix expression: ";
    cin >> infix;

    // Read the expression character by character
    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        // Add operands directly to postfix
        if (isalnum(ch))
        {
            postfix += ch;
        }

        // Push opening bracket into stack
        else if (ch == '(')
        {
            s.push(ch);
        }

        // Pop operators until opening bracket is found
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            // Remove opening bracket
            if (!s.empty())
                s.pop();
        }

        // Handle operators
        else
        {
            // Pop higher or equal priority operators
            while (!s.empty() &&
                   priority(s.top()) >= priority(ch))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    // Pop remaining operators from stack
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix Expression: " << postfix;

    return 0;
}
