#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
    ~Node() {
        int value = this->data;
        if (next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory is free for the data: " << value << endl;
    }
};

void insertNode(Node*& tail, int element, int d) {
    Node* temp = new Node(d);
    // empty list
    if (tail == NULL) {
        tail = temp;
        temp->next = temp;
    } else {
        Node* curr = tail;
        while (curr->data != element) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node*& tail, int element) {
    if (tail == NULL) {
        cout << "Empty List" << endl;
        return;
    } else {
        Node* prev = tail;
        Node* curr = prev->next;

        while (curr->data != element) {
            prev = curr;
            curr = curr->next;
            if (curr == tail->next) {
                cout << "Element not found" << endl;
                return;
            }
        }

        prev->next = curr->next;

        if (curr == prev) {
            tail = NULL;
        } else if (curr == tail) {
            tail = prev;
        }

        curr->next = NULL;
        delete curr;
    }
}

void print(Node*  &tail) {
    if (tail == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = tail;
    do {
        cout << temp->next->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

int main() {
    Node* tail = NULL;
    insertNode(tail, 2, 4);
    insertNode(tail, 4, 8);
    insertNode(tail, 8, 7);
    insertNode(tail, 7, 7);
    insertNode(tail, 7, 1);
    insertNode(tail, 1, 9);

    print(tail);

    deleteNode(tail, 7);
    print(tail);

    return 0;
}
