#include <bits/stdc++.h>
//ctrl + shift + b
using namespace std;
class Node {
    public :
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};
class Stack {
    public:
    Node* head;
    Node* top;
    Stack() {
        head = new Node(-1);
        top = head;
    }
    void push(int d) {
         Node* temp = new Node(d);
         top -> next = temp;
         top = temp;
    }
    int size() {
        int s = 0;
        Node* temp = head -> next;
        while(temp != NULL) {
            s++;
            temp = temp -> next;
        }
        return s;
    }    
    void pop() {
        if(top == head) {
            cout << "Stack Underflow" << endl;
        }else {
        Node* temp = head;
        while(temp -> next != top) {
            temp = temp -> next;
        }
        Node* del = top;
        top = temp;
        top -> next = NULL;
        delete del;
        } 
    }
    int peek() {
        if(top == head){
            cout << "Stack is Empty" << endl;
            return -1;
        }else
            return top -> data;    
    }
    bool isEmpty() {
        if(top == head) 
            return true;
        else    
            return false;    
    }
};
int main() {
    Stack s;
    int n = 5;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.push(x);
    }
    while(!s.isEmpty()) {
        cout << "Top element: " << s.peek() << endl;
        s.pop();
    }
return 0;
}