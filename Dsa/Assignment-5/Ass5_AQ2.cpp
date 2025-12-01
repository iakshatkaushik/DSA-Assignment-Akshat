/*Given a linked list and a positive number K, reverse the nodes in groups of K. All the remaining 
nodes after multiples of k should be left as it is. */
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* reverseK(Node* head, int k) {
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;
    while (curr && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (next) head->next = reverseK(next, k);
    return prev;
}
