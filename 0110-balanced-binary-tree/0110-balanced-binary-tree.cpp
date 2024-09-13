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
    pair<bool,int> fun(TreeNode* root) {
        if(root == NULL) {
            pair<bool, int> p = make_pair(true,0);
            return p;
        }else {
            pair<bool, int> l = fun(root -> left);
            pair<bool, int> r = fun(root -> right);
        
            pair<bool,int> ans;
            bool left = l.first;
            bool right = r.first;
            bool diff = abs(l.second - r.second) <= 1;
            ans.second = max(l.second,r.second) + 1;
            if(left && right && diff)
                ans.first = true;
            else 
                ans.first = false;    
            return ans; 
        }
    }
    bool isBalanced(TreeNode* root) {
        return fun(root).first;
            }
};