#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string exp;
    stack<char> s;

    cout << "Enter brackets: ";
    cin >> exp;

    bool balanced = true;

    // Check each bracket one by one
    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        // Push opening brackets into stack
        if (ch == '(' || ch == '[' || ch == '{')
        {
            s.push(ch);
        }

        // Check closing brackets
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            // If stack is empty, brackets are not balanced
            if (s.empty())
            {
                balanced = false;
                break;
            }

            char top = s.top();
            s.pop();

            // Check whether brackets match
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{'))
            {
                balanced = false;
                break;
            }
        }
    }

    // Stack should be empty for balanced brackets
    if (!s.empty())
    {
        balanced = false;
    }

    if (balanced)
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}
