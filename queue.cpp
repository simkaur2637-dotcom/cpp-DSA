```cpp
#include <iostream>
#include <queue>
using namespace std;

/*
===========================================================
                    QUEUE - DSA
===========================================================

Queue follows FIFO:
FIFO = First In, First Out

Main Operations:
1. Enqueue  -> Insert element at rear
2. Dequeue  -> Remove element from front
3. Front    -> View first element
4. Back     -> View last element
5. isEmpty  -> Check whether queue is empty

This file covers:
1. Queue using Array
2. Queue using Linked List
3. Queue using C++ STL
===========================================================
*/


// =========================================================
// 1. QUEUE USING ARRAY
// =========================================================

class ArrayQueue {

private:
    int arr[5];
    int front;
    int rear;

public:

    // Constructor
    ArrayQueue() {
        front = -1;
        rear = -1;
    }

    // Enqueue: Insert element
    void enqueue(int value) {

        // Check overflow
        if (rear == 4) {
            cout << "Queue is full!" << endl;
            return;
        }

        // First element
        if (front == -1) {
            front = 0;
        }

        rear++;
        arr[rear] = value;

        cout << value << " inserted." << endl;
    }

    // Dequeue: Remove element
    void dequeue() {

        // Check underflow
        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << arr[front] << " removed." << endl;

        front++;
    }

    // Get front element
    void getFront() {

        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Front: " << arr[front] << endl;
    }

    // Get rear element
    void getRear() {

        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Rear: " << arr[rear] << endl;
    }

    // Display queue
    void display() {

        if (front == -1 || front > rear) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue: ";

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // Check if queue is empty
    bool isEmpty() {

        return front == -1 || front > rear;
    }
};


// =========================================================
// 2. QUEUE USING LINKED LIST
// =========================================================

class Node {

public:
    int data;
    Node* next;

    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};


class LinkedListQueue {

private:
    Node* front;
    Node* rear;

public:

    // Constructor
    LinkedListQueue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue
    void enqueue(int value) {

        Node* newNode = new Node(value);

        // If queue is empty
        if (rear == nullptr) {

            front = rear = newNode;

        }
        else {

            rear->next = newNode;
            rear = newNode;
        }

        cout << value << " inserted." << endl;
    }

    // Dequeue
    void dequeue() {

        // Queue is empty
        if (front == nullptr) {

            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;

        cout << front->data << " removed." << endl;

        front = front->next;

        // If queue becomes empty
        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    // Get front
    void getFront() {

        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Front: " << front->data << endl;
    }

    // Get rear
    void getRear() {

        if (rear == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Rear: " << rear->data << endl;
    }

    // Display
    void display() {

        if (front == nullptr) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue: ";

        Node* temp = front;

        while (temp != nullptr) {

            cout << temp->data << " ";

            temp = temp->next;
        }

        cout << endl;
    }

    // Check empty
    bool isEmpty() {

        return front == nullptr;
    }

    // Destructor
    ~LinkedListQueue() {

        while (front != nullptr) {

            Node* temp = front;
            front = front->next;

            delete temp;
        }

        rear = nullptr;
    }
};


// =========================================================
// 3. QUEUE USING C++ STL
// =========================================================

void STLQueueDemo() {

    queue<int> q;

    cout << "\n--- C++ STL Queue ---" << endl;

    // Enqueue
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Queue elements inserted." << endl;

    // Front
    cout << "Front: " << q.front() << endl;

    // Rear
    cout << "Rear: " << q.back() << endl;

    // Dequeue
    q.pop();

    cout << "After pop, Front: "
         << q.front() << endl;

    // Size
    cout << "Size: "
         << q.size() << endl;

    // Empty
    if (q.empty()) {
        cout << "Queue is empty." << endl;
    }
    else {
        cout << "Queue is not empty." << endl;
    }
}


// =========================================================
// MAIN FUNCTION
// =========================================================

int main() {

    // =====================================================
    // ARRAY QUEUE DEMO
    // =====================================================

    cout << "====================================" << endl;
    cout << "       ARRAY QUEUE DEMO" << endl;
    cout << "====================================" << endl;

    ArrayQueue aq;

    aq.enqueue(10);
    aq.enqueue(20);
    aq.enqueue(30);

    aq.display();

    aq.getFront();
    aq.getRear();

    aq.dequeue();

    aq.display();

    aq.getFront();


    // =====================================================
    // LINKED LIST QUEUE DEMO
    // =====================================================

    cout << "\n====================================" << endl;
    cout << "     LINKED LIST QUEUE DEMO" << endl;
    cout << "====================================" << endl;

    LinkedListQueue lq;

    lq.enqueue(100);
    lq.enqueue(200);
    lq.enqueue(300);

    lq.display();

    lq.getFront();
    lq.getRear();

    lq.dequeue();

    lq.display();

    lq.getFront();


    // =====================================================
    // STL QUEUE DEMO
    // =====================================================

    STLQueueDemo();


    return 0;
}


/*
===========================================================
                 IMPORTANT SYNTAX
===========================================================

ARRAY QUEUE:

enqueue:
    rear++;
    arr[rear] = value;

dequeue:
    front++;


LINKED LIST QUEUE:

Insert:
    rear->next = newNode;
    rear = newNode;

Delete:
    Node* temp = front;
    front = front->next;
    delete temp;


STL QUEUE:

    queue<int> q;

    q.push(10);     // Insert
    q.pop();        // Remove front
    q.front();      // First element
    q.back();       // Last element
    q.empty();      // Check empty
    q.size();       // Number of elements


FIFO:

    First In -> First Out


COMPLEXITY:

Operation       Array       Linked List       STL
-----------------------------------------------------
Enqueue         O(1)        O(1)              O(1)
Dequeue         O(1)        O(1)              O(1)
Front           O(1)        O(1)              O(1)
Rear            O(1)        O(1)              O(1)

Space:
    O(n)



