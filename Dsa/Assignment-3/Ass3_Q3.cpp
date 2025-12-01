/*Write a program that checks if an expression has balanced parentheses. */
#include <iostream>
using namespace std;

int main()
{
    int max = 100;
    char stack[100];
    int top = -1;
    string expr;
    cin >> expr;
    bool balanced = true;
    for (int i = 0; i < expr.length(); i++)
    {
        char c = expr[i];
        if (c == '(' || c == '{' || c == '[')
        {
            stack[++top] = c;
        }
        else if (c == ')' || c == '}' || c == ']')
        {
            if (top == -1)
            {
                balanced = false;
                break;
            }
            char popped = stack[top--];
            if ((c == ')' && popped != '(') ||
                (c == '}' && popped != '{') ||
                (c == ']' && popped != '['))
            {
                balanced = false;
                break;
            }
        }
    }
    if (top != -1)
        balanced = false;
    cout << (balanced ? "Balanced" : "Not Balanced") << endl;
    return 0;
}
