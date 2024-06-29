/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private :
    void InsertNode(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
            return;
        }else {
        tail -> next = newNode;
        tail = newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = cloneHead;
        Node* temp = head;
        while(temp != NULL) {
            int data = temp -> val;
            InsertNode(cloneHead, cloneTail, data);
            temp = temp -> next;
        }
        Node* curr1 = head;
        Node* curr2 = cloneHead;
        Node* n1 = NULL ;
        Node* n2 = NULL; 
        while( curr2 != NULL) {
            n1 = curr1 -> next;
            n2 = curr2 -> next;
            curr1 -> next = curr2;
            curr2 -> next = n1;
            curr1 = n1;
            curr2 = n2; 
        }
        temp = head;
        while(temp != NULL) {
            if( temp -> random == NULL) {
                (temp -> next) -> random = NULL;
            }
            else {
            (temp -> next) -> random = (temp -> random) -> next;
            }
            temp = (temp -> next) -> next;
        }
        curr1 = head;
        curr2 = cloneHead;
        n1 = NULL;
        n2 = NULL;
        while(curr1 != NULL && curr2 != NULL) {
            n1 = (curr1 -> next) -> next;
            n2 = (curr2 -> next == NULL)? NULL : (curr2 -> next) -> next;
            curr1 -> next = n1;
            curr2 -> next = n2;
            curr1 = n1;
            curr2 = n2;
        }
        return cloneHead;
    }
};