/*Given two polynomial numbers represented by two linked lists. The task is 
to add these lists (meaning the coefficients with the same variable powers will be 
added).  */
#include <iostream>
using namespace std;

struct Node {
    int coeff, pow;
    Node* next;
};

Node* insert(Node* head, int c, int p) {
    Node* n = new Node;
    n->coeff = c; n->pow = p; n->next = NULL;
    if (!head) return n;
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
    return head;
}

Node* addPoly(Node* a, Node* b) {
    Node* res = NULL;
    Node* tail = NULL;
    while (a && b) {
        Node* n = new Node;
        n->next = NULL;
        if (a->pow > b->pow) { n->coeff = a->coeff; n->pow = a->pow; a = a->next; }
        else if (b->pow > a->pow) { n->coeff = b->coeff; n->pow = b->pow; b = b->next; }
        else { n->coeff = a->coeff + b->coeff; n->pow = a->pow; a = a->next; b = b->next; }
        if (!res) { res = tail = n; }
        else { tail->next = n; tail = n; }
    }
    while (a) { res = insert(res, a->coeff, a->pow); a = a->next; }
    while (b) { res = insert(res, b->coeff, b->pow); b = b->next; }
    return res;
}

int main() {
    Node* a = NULL;
    Node* b = NULL;
    a = insert(a, 5, 2);
    a = insert(a, 4, 1);
    a = insert(a, 2, 0);
    b = insert(b, 5, 1);
    b = insert(b, 5, 0);
    Node* res = addPoly(a, b);
    while (res) { cout << "[" << res->coeff << "," << res->pow << "] "; res = res->next; }
}
