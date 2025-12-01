/*2) Given a queue with random elements, we need to sort it. We are not allowed to use extra space. The 
operations allowed on queue are:  
       1.   enqueue() : Adds an item to rear of queue.  
2. dequeue() : Removes an item from front of queue.  
3. isEmpty() : Checks if a queue is empty.  
Input: 11, 5, 4, 21  
Output: 4, 5, 11, 21 */
#include <iostream>
#include <queue>
using namespace std;

int minIndex(queue<int> &q, int sortedIndex) {
    int min_index = -1, min_val = 1e9, n = q.size();
    for (int i = 0; i < n; i++) {
        int curr = q.front(); q.pop();
        if (curr <= min_val && i <= sortedIndex) {
            min_index = i;
            min_val = curr;
        }
        q.push(curr);
    }
    return min_index;
}

void insertMinToRear(queue<int> &q, int min_index) {
    int min_val;
    int n = q.size();
    for (int i = 0; i < n; i++) {
        int curr = q.front(); q.pop();
        if (i != min_index) q.push(curr);
        else min_val = curr;
    }
    q.push(min_val);
}

int main() {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; q.push(x);
    }
    for (int i = 1; i <= n; i++) {
        int min_index = minIndex(q, n - i);
        insertMinToRear(q, min_index);
    }
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}
