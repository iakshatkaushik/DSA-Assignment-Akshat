#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

void display(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << head->data << endl;
}

int main() {
    Node* head = new Node(20);
    Node* n2 = new Node(100);
    Node* n3 = new Node(40);
    Node* n4 = new Node(80);
    Node* n5 = new Node(60);
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = head;
    display(head);
}
