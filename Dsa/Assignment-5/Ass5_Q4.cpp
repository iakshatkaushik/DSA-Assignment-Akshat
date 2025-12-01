/*Write a program to reverse a linked list. 
Input: 1->2->3->4->NULL 
Output: 4->3->2->1->NULL*/
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

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    Node* head = NULL;
    int n, x; cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; insert(head, x); }
    head = reverse(head);
    while (head) { cout << head->data << " "; head = head->next; }
}
