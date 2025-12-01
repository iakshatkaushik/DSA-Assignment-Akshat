/*Given an array of integers temperatures represents the daily temperatures, return an 
array answer such that answer[i] is the number of days you have to wait after the ith day to get a 
warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead. */
#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    int t[n], ans[n];
    for (int i = 0; i < n; i++) cin >> t[i];
    stack<int> s;
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && t[s.top()] <= t[i]) s.pop();
        if (s.empty()) ans[i] = 0;
        else ans[i] = s.top() - i;
        s.push(i);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
}
