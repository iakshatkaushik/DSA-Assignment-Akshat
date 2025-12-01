/*. Given a linked list, remove the loop if it exists.*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void removeLoop(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) break;
    }
    if (slow != fast) return;
    slow = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}
