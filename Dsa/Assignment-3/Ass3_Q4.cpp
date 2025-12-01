/*Write a program to convert an Infix expression into a Postfix expression. */
#include <iostream>
using namespace std;

int precedence(char c)
{
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

int isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int main()
{
    int max = 100;
    char s[100];
    int top = -1;
    char infix[100], postfix[100];
    cin >> infix;
    int i = 0, j = 0;
    while (infix[i])
    {
        char c = infix[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            postfix[j++] = c;
        }
        else if (c == '(')
        {
            s[++top] = c;
        }
        else if (c == ')')
        {
            while (top != -1 && s[top] != '(')
                postfix[j++] = s[top--];
            top--;
        }
        else if (isOperator(c))
        {
            while (top != -1 && precedence(s[top]) >= precedence(c))
                postfix[j++] = s[top--];
            s[++top] = c;
        }
        i++;
    }
    while (top != -1)
        postfix[j++] = s[top--];
    postfix[j] = '\0';
    cout << postfix << endl;
    return 0;
}
