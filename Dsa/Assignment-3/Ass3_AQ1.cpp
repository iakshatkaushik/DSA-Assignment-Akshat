/*Given an array A, find the nearest smaller element for every element A[i] in the array such that the 
element has an index smaller than i. */
#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], ans[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    stack<int> s;
    for (int i = 0; i < n; i++) {
        while (!s.empty() && s.top() >= a[i]) s.pop();
        if (s.empty()) ans[i] = -1;
        else ans[i] = s.top();
        s.push(a[i]);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
}
