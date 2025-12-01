/*Write a program to implement a stack using (b) One Queue.*/
#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;
public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() { if (!q.empty()) q.pop(); }
    int top() { return q.front(); }
    bool empty() { return q.empty(); }
};

int main() {
    Stack s;
    s.push(5);
    s.push(8);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
}
