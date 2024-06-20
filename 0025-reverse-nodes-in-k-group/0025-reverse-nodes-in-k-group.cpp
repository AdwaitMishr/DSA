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

    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
        return NULL;
        
        //counting nodes
        ListNode* curr = head;
        int cnt1 = 0;
        while(cnt1 <= k && curr != NULL){
            curr = curr->next;
            cnt1++;
        }

        if(cnt1 < k)
            return head;

        curr=head;
        ListNode* prev=NULL;
        ListNode* next=NULL;
        int cnt = 0;
        // step 1
        
            while(curr != NULL && cnt < k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        
        }

        //step 2 recursion

        if(next != NULL) {
            head -> next = reverseKGroup(next,k);
        }

        return prev; 

    }
};