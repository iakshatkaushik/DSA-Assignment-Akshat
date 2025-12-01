/* Write a program interleave the first half of the queue with second half.*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q1, q2;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n / 2; i++) q1.push(a[i]);
    for (int i = n / 2; i < n; i++) q2.push(a[i]);
    while (!q1.empty() && !q2.empty()) {
        cout << q1.front() << " " << q2.front() << " ";
        q1.pop(); q2.pop();
    }
}
