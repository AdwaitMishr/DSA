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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for (auto &d : descriptions) {
            int parentVal = d[0];
            int childVal  = d[1];
            int isLeft    = d[2];

            if (!nodes.count(parentVal))
                nodes[parentVal] = new TreeNode(parentVal);

            if (!nodes.count(childVal))
                nodes[childVal] = new TreeNode(childVal);

            if (isLeft)
                nodes[parentVal]->left = nodes[childVal];
            else
                nodes[parentVal]->right = nodes[childVal];

            children.insert(childVal);
        }

        for (auto &[val, node] : nodes) {
            if (!children.count(val))
                return node;
        }

        return nullptr;
    }
};