/*Given a function n, write a function that generates and prints all binary numbers with decimal 
values from 1 to n. 
Input: n = 2 
Output: 1, 10*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<string> q;
    q.push("1");
    for (int i = 1; i <= n; i++) {
        string s = q.front();
        q.pop();
        cout << s << " ";
        q.push(s + "0");
        q.push(s + "1");
    }
}
