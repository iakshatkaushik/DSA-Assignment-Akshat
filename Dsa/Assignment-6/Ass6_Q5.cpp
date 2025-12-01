#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

bool isCircular(Node* head) {
    if (!head) return false;
    Node* temp = head->next;
    while (temp && temp != head) temp = temp->next;
    return temp == head;
}

int main() {
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
    a->next = b; b->next = c; c->next = a;
    cout << (isCircular(a) ? "Circular" : "Not Circular");
}
