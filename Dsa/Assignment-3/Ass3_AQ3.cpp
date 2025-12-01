/*Given an array arr[ ] of integers, the task is to find the Next Greater Element for each element of the 
array in order of their appearance in the array. Note: The Next Greater Element for an element x is 
the first greater element on the right side of x in the array. Elements for which no greater element 
exist, consider the next greater element as -1. */
#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], ans[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && s.top() <= a[i]) s.pop();
        if (s.empty()) ans[i] = -1;
        else ans[i] = s.top();
        s.push(a[i]);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
}
