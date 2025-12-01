/*Develop a menu driven program demonstrating the following operations on Circular Queues: 
enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().*/
#include <iostream>
using namespace std;
#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;
public:
    CircularQueue() { front = -1; rear = -1; }
    bool isFull() { return (front == 0 && rear == SIZE - 1) || (rear + 1 == front); }
    bool isEmpty() { return front == -1; }

    void enqueue(int x) {
        if (isFull()) cout << "Queue full\n";
        else {
            if (front == -1) front = 0;
            rear = (rear + 1) % SIZE;
            arr[rear] = x;
        }
    }

    void dequeue() {
        if (isEmpty()) cout << "Queue empty\n";
        else if (front == rear) front = rear = -1;
        else front = (front + 1) % SIZE;
    }

    void peek() {
        if (isEmpty()) cout << "Queue empty\n";
        else cout << "Front: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) cout << "Queue empty\n";
        else {
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear) break;
                i = (i + 1) % SIZE;
            }
            cout << endl;
        }
    }
};

int main() {
    CircularQueue q;
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
