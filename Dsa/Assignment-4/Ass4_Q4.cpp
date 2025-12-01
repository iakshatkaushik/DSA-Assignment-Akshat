/* Write a program to find first non-repeating character in a string using Queue. Sample I/P: a a 
b c Sample O/P: a -1 b b*/
#include <iostream>
#include <queue>
using namespace std;

int main() {
    string s;
    cin >> s;
    queue<char> q;
    int freq[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        freq[s[i]-'a']++;
        q.push(s[i]);
        while (!q.empty() && freq[q.front()-'a'] > 1) q.pop();
        if (q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
}
