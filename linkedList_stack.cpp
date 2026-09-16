#include <iostream>
using namespace std;

class Stack {

private:

    struct Node {
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
    };

    Node* top;

public:

    Stack() {
        top = nullptr;
    }

    void push(int value) {

        Node* newNode = new Node(value);

        newNode->next = top;
        top = newNode;
    }

    void pop() {

        if (top == nullptr) {
            cout << "Stack Underflow" << endl;
            return;
        }

        Node* temp = top;

        top = top->next;

        delete temp;
    }

    int peek() {

        if (top == nullptr) {
            return -1;
        }

        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};
