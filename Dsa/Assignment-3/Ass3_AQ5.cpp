/*You have an array A of integers of size N, an array B (initially empty) and a stack S (initially 
empty). You are allowed to do the following operations: 
a) Take the first element of array A and push it into S and remove it from A. 
b) Take the top element from stack S, append it to the end of array B and remove it from S. 
You have to tell if it possible to move all the elements of array A to array B using the above 
operations such that finally the array B is sorted in ascending order. */
#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    stack<int> s;
    int expected = 1;
    for (int i = 0; i < n; i++) {
        s.push(A[i]);
        while (!s.empty() && s.top() == expected) {
            s.pop();
            expected++;
        }
    }
    if (s.empty()) cout << "YES";
    else cout << "NO";
}
