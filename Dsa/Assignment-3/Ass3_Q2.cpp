/*Given a string, reverse it using STACK. For example “DataStructure” should be output as 
“erutcurtSataD.” */
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int max = 100;
    char stack[100];
    int top = -1;
    char str[100], reversed[100];
    cin >> str;
    int n = strlen(str);
    for (int i = 0; i < n; i++)
        stack[++top] = str[i];
    for (int i = 0; i < n; i++)
        reversed[i] = stack[top--];
    reversed[n] = '\0';
    cout << reversed << endl;
    return 0;
}
