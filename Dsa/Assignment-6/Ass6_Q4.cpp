#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
    Node(char val) : data(val), next(NULL), prev(NULL) {}
};

bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* tail = head;
    while (tail->next) tail = tail->next;
    while (head && tail && head != tail && tail->next != head) {
        if (head->data != tail->data) return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    Node* a = new Node('r');
    Node* b = new Node('a');
    Node* c = new Node('d');
    Node* d = new Node('a');
    Node* e = new Node('r');
    a->next = b; b->prev = a;
    b->next = c; c->prev = b;
    c->next = d; d->prev = c;
    d->next = e; e->prev = d;
    cout << (isPalindrome(a) ? "True" : "False");
}
