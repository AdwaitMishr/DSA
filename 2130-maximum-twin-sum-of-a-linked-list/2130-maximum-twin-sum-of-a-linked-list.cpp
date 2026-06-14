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
    ListNode* rev(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr) {
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode* fast = head; 
        ListNode* slow = head;
        while(fast && fast -> next) {
            fast = (fast -> next) -> next;
            slow = slow -> next;
        }
        ListNode* h2 = rev(slow);
        int maxi = INT_MIN;
        while(head && h2) {
            maxi = max(maxi, head -> val + h2 -> val);
            head = head -> next;
            h2 = h2 -> next;
        }
        return maxi;
    }
};