/*Find the intersection node of two singly linked lists that merge into a Y-shaped structure. 
The lists may vary in length and have distinct nodes at the beginning, but from the point of 
intersection onward, they share the same sequence of nodes. The task is to identify the first 
common node where the two lists converge. If the two linked lists have no intersection at all, 
return null. */
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int getLength(Node* head) {
    int len = 0;
    while (head) { len++; head = head->next; }
    return len;
}

Node* getIntersection(Node* a, Node* b) {
    int len1 = getLength(a), len2 = getLength(b);
    int d = abs(len1 - len2);
    if (len1 > len2) while (d--) a = a->next;
    else while (d--) b = b->next;
    while (a && b) {
        if (a == b) return a;
        a = a->next;
        b = b->next;
    }
    return NULL;
}
