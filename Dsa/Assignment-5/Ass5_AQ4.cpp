/* Given a linked list, and an integer k, rotate the list to the left by k positions and return 
the updated head. */
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* rotate(Node* head, int k) {
    if (!head || k == 0) return head;
    Node* curr = head;
    int len = 1;
    while (curr->next) { curr = curr->next; len++; }
    curr->next = head;
    k = k % len;
    int steps = len - k;
    while (steps--) curr = curr->next;
    head = curr->next;
    curr->next = NULL;
    return head;
}
