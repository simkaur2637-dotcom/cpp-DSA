Stack Implementation in C++

There are 3 important ways to implement a Stack:

Using Array 
Using Linked List
Using C++ STL stack
1️⃣ Stack Using Array

This is the best place to start.

Basic idea

We have an array:

[10] [20] [30] [   ] [   ]
              ↑
             TOP

We need one variable:

int top;

top tells us where the current top element is.

Initially
int top = -1;

Why -1?

Because the stack is empty and there is no valid array index yet.

Array:

[ ] [ ] [ ] [ ] [ ]

top = -1

Remember:

Empty stack → top = -1
First element → top = 0
Second element → top = 1
2️⃣ Push Operation

Suppose we want to add 10.

We first increase top:

top++;

Now:

top = 0

Then:

arr[top] = 10;

So:

[10] [ ] [ ] [ ] [ ]
 ↑
top
General formula
top++;
arr[top] = value;
3️⃣ Pop Operation

Suppose:

[10] [20] [30]
          ↑
         top

We want to remove 30.

We simply do:

top--;

Now:

[10] [20] [30]
      ↑
     top

30 is logically removed because top no longer points to it.

Important

We don't actually need to erase the value from the array.

The stack only considers elements from:

index 0 → top
4️⃣ Peek / Top Operation

If we want to see the top element:

arr[top]

For:

[10] [20] [30]
          ↑
         top

we get:

30
5️⃣ Overflow Check

Suppose array size is:

const int SIZE = 5;

Valid indexes are:

0 1 2 3 4

If:

top == SIZE - 1

the stack is full.

So before pushing:

if (top == SIZE - 1) {
    cout << "Stack Overflow";
}
Why SIZE - 1?

Because:

SIZE = 5

last index = 4

5 - 1 = 4
6️⃣ Underflow Check

If:

top == -1

the stack is empty.

So before popping:

if (top == -1) {
    cout << "Stack Underflow";
}
7️⃣ Complete Stack Using Array

Here is a clean implementation you can understand and later put in your GitHub notes:

#include <iostream>
using namespace std;

class Stack {
private:
    int arr[5];
    int top;

public:

    // Constructor
    Stack() {
        top = -1;
    }

    // Push
    void push(int value) {

        if (top == 4) {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = value;
    }

    // Pop
    void pop() {

        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return;
        }

        top--;
    }

    // Peek
    int peek() {

        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return arr[top];
    }

    // Check empty
    bool isEmpty() {
        return top == -1;
    }

    // Check full
    bool isFull() {
        return top == 4;
    }

    // Display
    void display() {

        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};


int main() {

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Stack: ";
    s.display();

    cout << "Top element: " << s.peek() << endl;

    s.pop();

    cout << "After pop: ";
    s.display();

    cout << "Top element: " << s.peek() << endl;

    return 0;
}
🔍 Let's understand the code
class Stack
class Stack {

We're creating our own Stack data structure.

Private section
private:
    int arr[5];
    int top;

We have:

arr

Stores the elements.

top

Keeps track of the top position.

Why private?

Because we don't want outside code directly changing top or the internal array.

Constructor
Stack() {
    top = -1;
}

Whenever we create:

Stack s;

the constructor automatically runs.

It sets:

top = -1

meaning:

Stack is empty.

Push
void push(int value)

This function receives the value we want to add.

First:

if (top == 4)

We check whether the stack is full.

If yes:

cout << "Stack Overflow";
return;

Otherwise:

top++;
arr[top] = value;
🧪 Push Dry Run

Initially:

top = -1
push(10)
top++

becomes:

top = 0

Then:

arr[0] = 10

Stack:

[10]
 ↑
top
push(20)
top = 1
arr[1] = 20
[10] [20]
       ↑
      top
push(30)
top = 2
arr[2] = 30
[10] [20] [30]
             ↑
            top
Pop
void pop()

First:

if (top == -1)

If true, the stack is empty.

Otherwise:

top--;

Suppose:

[10] [20] [30]
             ↑
            top

After:

top--;

we have:

[10] [20] [30]
       ↑
      top

So 30 is no longer considered part of the Stack.

Peek
return arr[top];

Suppose:

[10] [20] [30]
             ↑
            top

Then:

arr[top]

means:

arr[2]

which is:

30
Display
for (int i = top; i >= 0; i--)

Why start from top?

Because Stack is viewed from the top.

Suppose:

[10] [20] [30]

We want:

30 20 10

So we start:

i = 2

then:

2 → 1 → 0
8️⃣ Stack Using Linked List

Now let's implement the same Stack using a Linked List.

Remember our Linked List:

[data | next]

For Stack, we'll make the head the TOP.

TOP
 ↓
[30] → [20] → [10] → NULL
Push

Suppose we push 40.

Create:

[40]

Connect it to the old top:

[40] → [30] → [20] → [10] → NULL
 ↑
TOP
Pop

Remove the top node:

Before:

TOP
 ↓
[40] → [30] → [20] → NULL

After:

TOP
 ↓
[30] → [20] → NULL
