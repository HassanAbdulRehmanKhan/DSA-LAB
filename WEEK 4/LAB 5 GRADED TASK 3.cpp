#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string postfix;
    stack<int> s;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    // Read postfix expression character by character
    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        // Push numbers into stack
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }

        // Perform calculation for operators
        else
        {
            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            int result;

            // Apply the required operation
            if (ch == '+')
                result = a + b;
            else if (ch == '-')
                result = a - b;
            else if (ch == '*')
                result = a * b;
            else if (ch == '/')
                result = a / b;

            // Push result back into stack
            s.push(result);
        }
    }

    // Final value is present at the top
    cout << "Result = " << s.top();

    return 0;
}
