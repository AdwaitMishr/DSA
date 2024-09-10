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
    int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head -> next == NULL)
        return head;
        ListNode* curr = head;

            ListNode* n = curr -> next;
            ListNode* m = curr;
            int val = gcd(m-> val, n -> val);
            curr -> next = insertGreatestCommonDivisors(curr -> next);
            m -> next = new ListNode(val);
            (m -> next) -> next = n;

        return head;
    }
};