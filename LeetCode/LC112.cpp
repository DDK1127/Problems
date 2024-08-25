// LeetCode 112. Path Sum

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
    bool f = false;
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return f;
        find(root, root->val, targetSum);
        return f;
    }
    void find(TreeNode* root, int sum, int tar){
        if(root->left)
            find(root->left, sum+root->left->val, tar);
        if(root->right)
            find(root->right, sum+root->right->val, tar);
        if((!root->right && !root->left) && sum == tar)
            f = true;
    }
};