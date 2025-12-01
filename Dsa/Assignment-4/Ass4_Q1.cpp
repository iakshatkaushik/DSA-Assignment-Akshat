/*Develop a menu driven program demonstrating the following operations on simple 
Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek(). */
#include <iostream>
using namespace std;
#define SIZE 5

class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() { front = -1; rear = -1; }
    bool isFull() { return rear == SIZE - 1; }
    bool isEmpty() { return front == -1 || front > rear; }

    void enqueue(int x) {
        if (isFull()) cout << "Queue is full\n";
        else {
            if (front == -1) front = 0;
            arr[++rear] = x;
        }
    }

    void dequeue() {
        if (isEmpty()) cout << "Queue is empty\n";
        else front++;
    }

    void peek() {
        if (isEmpty()) cout << "Queue is empty\n";
        else cout << "Front: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) cout << "Queue is empty\n";
        else {
            for (int i = front; i <= rear; i++) cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    int ch, x;
    do {
        cout << "1.Enqueue 2.Dequeue 3.Display 4.Peek 5.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cin >> x; q.enqueue(x); break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
            case 4: q.peek(); break;
        }
    } while (ch != 5);
}
