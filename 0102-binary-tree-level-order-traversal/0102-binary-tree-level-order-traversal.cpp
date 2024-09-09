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
    void level(TreeNode* root, vector<vector<int>> &ans) {
        if(root == NULL)
            return;
        queue <TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;
        while(!q.empty()) {
        TreeNode* r = q.front();
        q.pop();
        if(r == NULL) {
            ans.push_back(temp);
            temp.clear();
            if(!q.empty())
                q.push(NULL);
        }else {
            temp.push_back(r -> val);
            if(r -> left)
                q.push(r -> left);
            if(r -> right)
                q.push(r -> right);    
        }    
        }    
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        level(root, ans);
        return ans;
    }
};