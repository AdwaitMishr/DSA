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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int srow = 0;
        int erow = m -1;
        int scol = 0;
        int ecol = n-1;
        while(srow <= erow && scol <= ecol && head != NULL) {
            //right
            for(int i = scol; i <= ecol && head != NULL; i++) {
                ans[srow][i] = head -> val;
                head = head -> next;
            }
            srow++;
            //down
            for(int i = srow; i <= erow && head != NULL; i++) {
                ans[i][ecol] = head -> val;
                head = head -> next; 
            } 
            ecol--;
            //left
            for(int i = ecol; i >= scol && head != NULL;i--) {
                ans[erow][i] = head -> val;
                head = head -> next;
            }
            erow--;
            //up
            for(int i = erow; i >= srow && head != NULL; i--) {
                ans[i][scol] = head -> val;
                head = head -> next;
            }
            scol++;
        }

        
        return ans;
    }
};