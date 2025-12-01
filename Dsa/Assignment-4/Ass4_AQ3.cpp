/*Given a Queue consisting of first n natural numbers (in random order). The task is to check whether 
the given Queue elements can be arranged in increasing order in another Queue using a stack. The 
operation allowed are:  
1. Push and pop elements from the stack  
2. Pop (Or Dequeue) from the given Queue.  
3. Push (Or Enqueue) in the another Queue. 
Input : Queue[] = { 5, 1, 2, 3, 4 }  
Output : Yes */
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q1, q2;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        q1.push(x);
    }
    stack<int> s;
    int expected = 1;
    while (!q1.empty()) {
        int front = q1.front();
        q1.pop();
        if (front == expected) expected++;
        else {
            if (!s.empty() && s.top() < front) break;
            s.push(front);
        }
        while (!s.empty() && s.top() == expected) {
            s.pop();
            expected++;
        }
    }
    if (expected - 1 == n) cout << "Yes";
    else cout << "No";
}
