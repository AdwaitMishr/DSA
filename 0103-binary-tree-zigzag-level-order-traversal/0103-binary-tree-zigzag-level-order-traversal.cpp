/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void zigzag(TreeNode* root, vector<int> &ans) {
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL) {
                ans.push_back(-101);
                if(!q.empty())
                    q.push(NULL);
            }else {
                ans.push_back(temp -> val);
            if(temp -> left) {
                q.push(temp -> left);
            }
            if(temp -> right) {
                q.push(temp -> right);
            }
            }            
        }

}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL)
            return ans;
        vector<int> temp;
        zigzag(root, temp);
        int cnt = 0;
        vector<int> p;
        for(int i = 0; i < temp.size(); i++) {
            if(temp[i] == -101) {
                if(cnt % 2 == 0) {
                    ans.push_back(p);
                    p.clear();
                }else {
                    reverse(p.begin(),p.end());
                    ans.push_back(p);
                    p.clear();
                }
                cnt++;
                continue;
            }
            p.push_back(temp[i]);
        }
        return ans;
    }
};