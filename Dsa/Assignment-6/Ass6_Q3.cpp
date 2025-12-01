#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

int sizeDoubly(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int sizeCircular(Node* head) {
    if (!head) return 0;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    Node* d1 = new Node(10);
    Node* d2 = new Node(20);
    Node* d3 = new Node(30);
    d1->next = d2; d2->prev = d1; d2->next = d3; d3->prev = d2;

    cout << "Doubly Size: " << sizeDoubly(d1) << endl;

    Node* c1 = new Node(5);
    Node* c2 = new Node(10);
    Node* c3 = new Node(15);
    c1->next = c2; c2->next = c3; c3->next = c1;
    cout << "Circular Size: " << sizeCircular(c1) << endl;
}
