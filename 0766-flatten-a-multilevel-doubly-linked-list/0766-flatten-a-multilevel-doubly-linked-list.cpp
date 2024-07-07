/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* findTail(Node* head) {
        Node* tail = head;
        while(tail -> next != NULL) {
            tail = tail -> next;
        }
        return tail;
    }
    Node* flatten(Node* head) {
        if(head == NULL) 
            return head;
        Node* temp = head;
        while(temp != NULL) {
            if(temp -> child != NULL) {
                Node* tans = flatten(temp -> child);
                Node* nt = temp -> next;
                temp -> next = tans;
                tans -> prev = temp;
                Node* ctail = findTail(temp -> child);
                temp -> child = NULL;
                if(nt != NULL) {
                    ctail -> next = nt;
                    nt -> prev = ctail;
                }
            }
            
            temp = temp -> next;
        }
        return head;
    }
};