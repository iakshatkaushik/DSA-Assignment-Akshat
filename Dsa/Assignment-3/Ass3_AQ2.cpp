/*Design a stack that supports getMin() in O(1) time and O(1) extra space.*/
#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    stack<long long> s;
    long long minVal;
public:
    void push(int x) {
        if (s.empty()) {
            s.push(x);
            minVal = x;
        } else if (x < minVal) {
            s.push(2LL * x - minVal);
            minVal = x;
        } else s.push(x);
    }
    void pop() {
        if (s.empty()) return;
        long long t = s.top();
        s.pop();
        if (t < minVal) minVal = 2LL * minVal - t;
    }
    int top() {
        long long t = s.top();
        if (t < minVal) return minVal;
        return t;
    }
    int getMin() {
        return minVal;
    }
};

int main() {
    SpecialStack s;
    s.push(3);
    s.push(5);
    cout << s.getMin() << endl;
    s.push(2);
    s.push(1);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.getMin() << endl;
    s.pop();
    cout << s.top() << endl;
}
