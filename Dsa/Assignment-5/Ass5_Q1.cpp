/*1. Develop a menu driven program for the following operations on a Singly Linked 
List. 
(a) Insertion at the beginning. 
(b) Insertion at the end. 
(c) Insertion in between (before or after a node having a specific value, say 'Insert a 
new Node 35 before/after the Node 30'). 
(d) Deletion from the beginning. 
(e) Deletion from the end. 
(f) Deletion of a specific node, say 'Delete Node 60'). 
(g) Search for a node and display its position from head. 
(h) Display all the node values.*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBeg(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = head;
    head = n;
}

void insertEnd(int x) {
    Node* n = new Node;
    n->data = x;
    n->next = NULL;
    if (head == NULL) head = n;
    else {
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = n;
    }
}

void insertAfter(int val, int x) {
    Node* temp = head;
    while (temp != NULL && temp->data != val) temp = temp->next;
    if (temp == NULL) cout << "Value not found\n";
    else {
        Node* n = new Node;
        n->data = x;
        n->next = temp->next;
        temp->next = n;
    }
}

void insertBefore(int val, int x) {
    if (head == NULL) return;
    if (head->data == val) { insertBeg(x); return; }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != val) temp = temp->next;
    if (temp->next == NULL) cout << "Value not found\n";
    else {
        Node* n = new Node;
        n->data = x;
        n->next = temp->next;
        temp->next = n;
    }
}

void deleteBeg() {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteEnd() {
    if (head == NULL) return;
    if (head->next == NULL) { delete head; head = NULL; return; }
    Node* temp = head;
    while (temp->next->next != NULL) temp = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void deleteVal(int val) {
    if (head == NULL) return;
    if (head->data == val) { deleteBeg(); return; }
    Node* temp = head;
    while (temp->next != NULL && temp->next->data != val) temp = temp->next;
    if (temp->next == NULL) cout << "Value not found\n";
    else {
        Node* t = temp->next;
        temp->next = t->next;
        delete t;
    }
}

void search(int val) {
    Node* temp = head;
    int pos = 1;
    while (temp != NULL) {
        if (temp->data == val) { cout << "Found at position " << pos << endl; return; }
        pos++;
        temp = temp->next;
    }
    cout << "Not found\n";
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int ch, x, val;
    do {
        cout << "1.InsertBeg 2.InsertEnd 3.InsertBefore 4.InsertAfter 5.DeleteBeg 6.DeleteEnd 7.DeleteVal 8.Search 9.Display 10.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cin >> x; insertBeg(x); break;
            case 2: cin >> x; insertEnd(x); break;
            case 3: cin >> val >> x; insertBefore(val, x); break;
            case 4: cin >> val >> x; insertAfter(val, x); break;
            case 5: deleteBeg(); break;
            case 6: deleteEnd(); break;
            case 7: cin >> val; deleteVal(val); break;
            case 8: cin >> val; search(val); break;
            case 9: display(); break;
        }
    } while (ch != 10);
}
