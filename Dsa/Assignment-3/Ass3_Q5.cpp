/*Write a program for the evaluation of a Postfix expression. */
#include <iostream>
using namespace std;

int main()
{
    int max = 100;
    int stack[100];
    int top = -1;
    char postfix[100];
    cin >> postfix;
    int i = 0;
    while (postfix[i])
    {
            int b = stack[top--];
            int a = stack[top--];

    }
    cout << stack[top] << endl;
    return 0;
}
