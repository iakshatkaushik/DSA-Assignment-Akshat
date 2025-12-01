/*Develop a menu driven program demonstrating the following operations on a Stack using array: 
(i) 
push(),  (ii) pop(),  (iii) isEmpty(),  (iv) isFull(),  (v) display(), and  (vi) peek(). */
#include <iostream>
using namespace std;

struct stack
{
    int m;
    int arr[50];
    int top;
};

int isFull(stack s)
{
    if (s.top == s.m - 1)
    {
        cout << "Stack Overflow\n";
        return 1;
    }
    return 0;
}

int isEmpty(stack s)
{
    if (s.top == -1)
    {
        cout << "Stack Underflow\n";
        return 1;
    }
    return 0;
}

void push(stack &s, int value)
{
    if (isFull(s))
        return;
    s.top++;
    s.arr[s.top] = value;
    cout << value << " pushed into stack\n";
}

void pop(stack &s)
{
    if (isEmpty(s))
        return;
    cout << s.arr[s.top] << " popped from stack\n";
    s.top--;
}

void peek(stack s)
{
    if (isEmpty(s))
        return;
    cout << "Top element: " << s.arr[s.top] << endl;
}

void display(stack s)
{
    if (isEmpty(s))
        return;
    cout << "Stack elements:\n";
    for (int i = s.top; i >= 0; i--)
        cout << s.arr[i] << endl;
}

int main()
{
    stack s;
    s.m = 50;
    s.top = -1;
    int choice, value;
    do
    {
        cout << "\n1. Push\n2. Pop\n3. isEmpty\n4. isFull\n5. Display\n6. Peek\n7. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            push(s, value);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            if (isEmpty(s))
                cout << "Stack is empty\n";
            else
                cout << "Stack is not empty\n";
            break;
        case 4:
            if (isFull(s))
                cout << "Stack is full\n";
            else
                cout << "Stack is not full\n";
            break;
        case 5:
            display(s);
            break;
        case 6:
            peek(s);
            break;
        }
    } while (choice != 7);
    return 0;
}
