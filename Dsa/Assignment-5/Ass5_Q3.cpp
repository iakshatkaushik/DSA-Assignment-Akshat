/*3. Write a program to find the middle of a linked list. 
Input: 1->2->3->4->5 
Output: 3*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int x) {
    Node* n = new Node;
    n->data = x;
    n->next = NULL;
    if (!head) head = n;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }
}

int main() {
    Node* head = NULL;
    int n, x; cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; insert(head, x); }
    Node* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data;
}
