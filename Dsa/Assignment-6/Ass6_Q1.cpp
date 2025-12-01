#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

class DoublyList {
public:
    Node* head;
    DoublyList() : head(NULL) {}
    void insertFirst(int val) {
        Node* n = new Node(val);
        if (!head) head = n;
        else {
            n->next = head;
            head->prev = n;
            head = n;
        }
    }
    void insertLast(int val) {
        Node* n = new Node(val);
        if (!head) head = n;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = n;
            n->prev = temp;
        }
    }
    void insertAfter(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        Node* n = new Node(val);
        n->next = temp->next;
        n->prev = temp;
        if (temp->next) temp->next->prev = n;
        temp->next = n;
    }
    void insertBefore(int key, int val) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        Node* n = new Node(val);
        n->next = temp;
        n->prev = temp->prev;
        if (temp->prev) temp->prev->next = n;
        else head = n;
        temp->prev = n;
    }
    void deleteNode(int key) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) return;
        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
    }
    void search(int key) {
        Node* temp = head;
        while (temp) {
            if (temp->data == key) {
                cout << "Found\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Not Found\n";
    }
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

class CircularList {
public:
    Node* head;
    CircularList() : head(NULL) {}
    void insertLast(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = n;
            n->next = head;
        }
    }
    void insertFirst(int val) {
        Node* n = new Node(val);
        if (!head) {
            head = n;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            n->next = head;
            temp->next = n;
            head = n;
        }
    }
    void deleteNode(int key) {
        if (!head) return;
        if (head->data == key && head->next == head) {
            delete head;
            head = NULL;
            return;
        }
        Node* curr = head;
        Node* prev = NULL;
        while (curr->next != head && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }
        if (curr->data == key) {
            if (curr == head) {
                Node* temp = head;
                while (temp->next != head) temp = temp->next;
                temp->next = head->next;
                head = head->next;
            } else prev->next = curr->next;
            delete curr;
        }
    }
    void search(int key) {
        if (!head) return;
        Node* temp = head;
        do {
            if (temp->data == key) {
                cout << "Found\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Not Found\n";
    }
    void display() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    DoublyList d;
    CircularList c;
    int choice, val, key;
    while (true) {
        cout << "\n1.Insert First (Doubly)\n2.Insert Last (Doubly)\n3.Insert After (Doubly)\n4.Delete (Doubly)\n5.Search (Doubly)\n6.Display (Doubly)\n7.Insert (Circular)\n8.Delete (Circular)\n9.Search (Circular)\n10.Display (Circular)\n0.Exit\n";
        cin >> choice;
        if (choice == 0) break;
        switch (choice) {
            case 1: cin >> val; d.insertFirst(val); break;
            case 2: cin >> val; d.insertLast(val); break;
            case 3: cin >> key >> val; d.insertAfter(key, val); break;
            case 4: cin >> key; d.deleteNode(key); break;
            case 5: cin >> key; d.search(key); break;
            case 6: d.display(); break;
            case 7: cin >> val; c.insertLast(val); break;
            case 8: cin >> key; c.deleteNode(key); break;
            case 9: cin >> key; c.search(key); break;
            case 10: c.display(); break;
        }
    }
}
