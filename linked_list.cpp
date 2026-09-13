
#include <iostream>
using namespace std;

// ============================================================
// LINKED LIST - DSA IN C++
//
// Topics Covered:
// 1. Node creation
// 2. Traversal
// 3. Insert at beginning
// 4. Insert at end
// 5. Insert at position
// 6. Delete from beginning
// 7. Delete from end
// 8. Delete by value
// 9. Search an element
// 10. Count nodes
// 11. Reverse linked list
// 12. Find middle node
// 13. Detect cycle
// ============================================================


// ============================================================
// NODE CLASS
// ============================================================

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


// ============================================================
// DISPLAY / TRAVERSAL
// ============================================================

void display(Node* head) {

    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}


// ============================================================
// INSERT AT BEGINNING
// ============================================================

void insertAtBeginning(Node*& head, int value) {

    Node* newNode = new Node(value);

    newNode->next = head;
    head = newNode;
}


// ============================================================
// INSERT AT END
// ============================================================

void insertAtEnd(Node*& head, int value) {

    Node* newNode = new Node(value);

    // If list is empty
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;

    // Reach the last node
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}


// ============================================================
// INSERT AT A GIVEN POSITION
//
// Position starts from 1.
//
// Example:
// Position 1 = beginning
// Position 2 = after first node
// ============================================================

void insertAtPosition(Node*& head, int value, int position) {

    // Insert at beginning
    if (position == 1) {
        insertAtBeginning(head, value);
        return;
    }

    Node* newNode = new Node(value);
    Node* temp = head;

    // Move to node before required position
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    // Invalid position
    if (temp == nullptr) {
        cout << "Invalid position!\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}


// ============================================================
// DELETE FROM BEGINNING
// ============================================================

void deleteFromBeginning(Node*& head) {

    // Empty list
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    Node* temp = head;

    head = head->next;

    delete temp;
}


// ============================================================
// DELETE FROM END
// ============================================================

void deleteFromEnd(Node*& head) {

    // Empty list
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    // Only one node
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;

    // Reach second-last node
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
}


// ============================================================
// DELETE A NODE BY VALUE
// ============================================================

void deleteByValue(Node*& head, int value) {

    // Empty list
    if (head == nullptr) {
        cout << "List is empty!\n";
        return;
    }

    // Value is in the first node
    if (head->data == value) {

        Node* temp = head;
        head = head->next;

        delete temp;
        return;
    }

    Node* temp = head;

    // Find the node before the node to delete
    while (temp->next != nullptr &&
           temp->next->data != value) {

        temp = temp->next;
    }

    // Value not found
    if (temp->next == nullptr) {
        cout << "Value not found!\n";
        return;
    }

    Node* nodeToDelete = temp->next;

    temp->next = nodeToDelete->next;

    delete nodeToDelete;
}


// ============================================================
// SEARCH
// ============================================================

bool search(Node* head, int target) {

    Node* temp = head;

    while (temp != nullptr) {

        if (temp->data == target) {
            return true;
        }

        temp = temp->next;
    }

    return false;
}


// ============================================================
// COUNT NUMBER OF NODES
// ============================================================

int countNodes(Node* head) {

    int count = 0;

    Node* temp = head;

    while (temp != nullptr) {

        count++;

        temp = temp->next;
    }

    return count;
}


// ============================================================
// REVERSE LINKED LIST
//
// Uses three pointers:
// prev
// curr
// nextNode
// ============================================================

void reverseList(Node*& head) {

    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr) {

        // Save next node before changing the link
        Node* nextNode = curr->next;

        // Reverse the link
        curr->next = prev;

        // Move prev forward
        prev = curr;

        // Move curr forward
        curr = nextNode;
    }

    head = prev;
}


// ============================================================
// FIND MIDDLE NODE
//
// Uses slow and fast pointers.
// slow moves one step.
// fast moves two steps.
// ============================================================

Node* findMiddle(Node* head) {

    if (head == nullptr) {
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr &&
           fast->next != nullptr) {

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


// ============================================================
// DETECT CYCLE
//
// Floyd's Cycle Detection Algorithm
//
// slow -> one step
// fast -> two steps
// ============================================================

bool hasCycle(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr &&
           fast->next != nullptr) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}


// ============================================================
// FREE MEMORY
// ============================================================

void deleteList(Node*& head) {

    while (head != nullptr) {

        Node* temp = head;

        head = head->next;

        delete temp;
    }
}


// ============================================================
// MAIN FUNCTION
// ============================================================

int main() {

    // Initially the linked list is empty
    Node* head = nullptr;


    // --------------------------------------------------------
    // INSERT AT END
    // --------------------------------------------------------

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);

    cout << "Initial Linked List:\n";
    display(head);


    // --------------------------------------------------------
    // INSERT AT BEGINNING
    // --------------------------------------------------------

    insertAtBeginning(head, 5);

    cout << "\nAfter inserting 5 at beginning:\n";
    display(head);


    // --------------------------------------------------------
    // INSERT AT POSITION
    // --------------------------------------------------------

    insertAtPosition(head, 15, 3);

    cout << "\nAfter inserting 15 at position 3:\n";
    display(head);


    // --------------------------------------------------------
    // COUNT NODES
    // --------------------------------------------------------

    cout << "\nNumber of nodes: "
         << countNodes(head) << "\n";


    // --------------------------------------------------------
    // SEARCH
    // --------------------------------------------------------

    int target = 20;

    if (search(head, target)) {
        cout << target << " found in the list.\n";
    }
    else {
        cout << target << " not found in the list.\n";
    }


    // --------------------------------------------------------
    // FIND MIDDLE
    // --------------------------------------------------------

    Node* middle = findMiddle(head);

    if (middle != nullptr) {
        cout << "Middle node: "
             << middle->data << "\n";
    }


    // --------------------------------------------------------
    // DELETE FROM BEGINNING
    // --------------------------------------------------------

    deleteFromBeginning(head);

    cout << "\nAfter deleting from beginning:\n";
    display(head);


    // --------------------------------------------------------
    // DELETE FROM END
    // --------------------------------------------------------

    deleteFromEnd(head);

    cout << "\nAfter deleting from end:\n";
    display(head);


    // --------------------------------------------------------
    // DELETE BY VALUE
    // --------------------------------------------------------

    deleteByValue(head, 20);

    cout << "\nAfter deleting value 20:\n";
    display(head);


    // --------------------------------------------------------
    // REVERSE LINKED LIST
    // --------------------------------------------------------

    reverseList(head);

    cout << "\nAfter reversing linked list:\n";
    display(head);


    // --------------------------------------------------------
    // CYCLE DETECTION
    // --------------------------------------------------------

    if (hasCycle(head)) {
        cout << "\nCycle detected.\n";
    }
    else {
        cout << "\nNo cycle detected.\n";
    }


    // --------------------------------------------------------
    // FREE MEMORY
    // --------------------------------------------------------

    deleteList(head);

    return 0;
}

