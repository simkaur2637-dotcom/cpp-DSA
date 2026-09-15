//LeetCode 232 — Implement Queue using Stacks. 
class RecentCounter {

private:
    queue<int> q;

public:

    RecentCounter() {
    }

    int ping(int t) {

        q.push(t);

        while (q.front() < t - 3000) {
            q.pop();
        }

        return q.size();
    }
};

//LeetCode 232 — Implement Queue using Stacks

//LeetCode 622 — Design Circular Queue


class MyCircularQueue {
private:
    vector<int> queue;
    int front;
    int rear;
    int count;
    int size;

public:

    MyCircularQueue(int k) {
        size = k;
        queue.resize(k);

        front = 0;
        rear = -1;
        count = 0;
    }

    bool enQueue(int value) {

        if (isFull()) {
            return false;
        }

        rear = (rear + 1) % size;
        queue[rear] = value;
        count++;

        return true;
    }

    bool deQueue() {

        if (isEmpty()) {
            return false;
        }

        front = (front + 1) % size;
        count--;

        return true;
    }

    int Front() {

        if (isEmpty()) {
            return -1;
        }

        return queue[front];
    }

    int Rear() {

        if (isEmpty()) {
            return -1;
        }

        return queue[rear];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }
};
