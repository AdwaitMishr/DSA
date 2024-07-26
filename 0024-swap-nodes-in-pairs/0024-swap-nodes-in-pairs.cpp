/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next == NULL) {
            return head;
        }
        ListNode* temp = head;
        ListNode* swap = head -> next;
        temp -> next = swap -> next;
        swap -> next = temp;
        head = swap;
        temp = temp -> next;
        ListNode* prev = swap -> next;
        swap = (temp != NULL)?temp -> next: NULL;
        while(temp != NULL && temp -> next != NULL) {
            temp -> next = swap -> next;
            prev -> next = swap;
            swap -> next = temp;
            temp = temp -> next;
            prev = swap -> next;
            swap = (temp != NULL)?temp -> next : NULL;
        }
        return head;
    }
};