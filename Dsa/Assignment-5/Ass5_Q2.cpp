/*2. Write a program to count the number of occurrences of a given key in a singly linked 
list and then delete all the occurrences.  
Input: Linked List :  1->2->1->2->1->3->1 , key:  1                                                                    
Output: Count: 4 ,  Updated Linked List: 2->2->3. */
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node*& head, int x) {
    Node* n = new Node;
    n->data = x;
    n->next = NULL;
    if (!head) head = n;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }
}

void deleteKey(Node*& head, int key) {
    int count = 0;
    while (head && head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
        count++;
    }
    Node* curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node* t = curr->next;
            curr->next = curr->next->next;
            delete t;
            count++;
        } else curr = curr->next;
    }
    cout << "Count: " << count << " Updated: ";
    curr = head;
    while (curr) { cout << curr->data << " "; curr = curr->next; }
}

int main() {
    Node* head = NULL;
    int n, x, key;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; insert(head, x); }
    cin >> key;
    deleteKey(head, key);
}
